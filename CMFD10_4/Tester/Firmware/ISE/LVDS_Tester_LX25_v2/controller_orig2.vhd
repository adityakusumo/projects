--	--Resolution 800x600 60Hz
--	constant hres : integer := 800;
--	constant hfpor : integer := 40;
--	constant hsyn : integer := 128;
--	constant hbpor : integer := 88;
--	constant vres : integer := 600;
--	constant vfpor : integer := 1;
--	constant vsyn : integer := 4;
--	constant vbpor : integer := 23;
--	constant hspol : std_logic := '1';
--	constant vspol : std_logic := '1';----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    23:40:06 09/03/2011 
-- Design Name: 
-- Module Name:    controller - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity lvds_transmit is
    Port ( 	 
		CK1IN_p : out  STD_LOGIC;
		CK1IN_n : out  STD_LOGIC;
--		RXIN3_p : out  STD_LOGIC;
--		RXIN3_n : out  STD_LOGIC;		
--		RXIN2_p : out  STD_LOGIC;
--		RXIN2_n : out  STD_LOGIC;
--		RXIN1_p : out  STD_LOGIC;
--		RXIN1_n : out  STD_LOGIC;
--		RXIN0_p : out  STD_LOGIC;
--		RXIN0_n : out  STD_LOGIC;
		
		TX_p : out std_logic_vector(3 downto 0);
		TX_n : out std_logic_vector(3 downto 0);
		
		en_video	: in std_logic;
--		mode_pix	: in std_logic;
		
		clk_in : in  STD_LOGIC
	);
end lvds_transmit;

architecture Behavioral of lvds_transmit is

	-- fast clock, 12 Mhz x 21 = 252 Mhz, which gives us a pixel clock of 36 Mhz
	signal clk_fast : std_logic;
	
	-- colors
	signal red : std_logic_vector(7 downto 0) := (others=>'0');
	signal green : std_logic_vector(7 downto 0) := (others=>'0');
	signal blue : std_logic_vector(7 downto 0) := (others=>'0');
	
	-- which slot are we in right now?
	signal slot : integer range 0 to 6;
	
	-- control signals
	signal hsync : std_logic := '0';
	signal vsync : std_logic := '0';
	signal dataenable : std_logic := '0';
	signal pix_de : std_logic := '0';
	
--    // Resolution Constants
--    localparam hres = 960;
--    localparam hfpor = 20;
--    localparam hsyn = 16;
--    localparam hbpor = 24;
--    localparam vres = 1280;
--    localparam vfpor = 4;
--    localparam vsyn = 4;
--    localparam vbpor = 32;	
	
--	--Resolution 1280x960 60Hz
--	constant hres : integer := 1280;
--	constant hfpor : integer := 80;
--	constant hsyn : integer := 136;
--	constant hbpor : integer := 216;
--	constant vres : integer := 960;
--	constant vfpor : integer := 3;
--	constant vsyn : integer := 10;
--	constant vbpor : integer := 38;
--	constant hspol : std_logic := '1';
--	constant vspol : std_logic := '1';	

	--Custom Resolution 60Hz
	constant hres : integer := 480;
	constant hfpor : integer := 20;
	constant hsyn : integer := 10;
	constant hbpor : integer := 20;
	constant vres : integer := 640;
	constant vfpor : integer := 2;
	constant vsyn : integer := 2;
	constant vbpor : integer := 10;
	constant hspol : std_logic := '1';
	constant vspol : std_logic := '1';		
	
--	--Resolution 800x600 60Hz
--	constant hres : integer := 800;
--	constant hfpor : integer := 40;
--	constant hsyn : integer := 128;
--	constant hbpor : integer := 88;
--	constant vres : integer := 600;
--	constant vfpor : integer := 1;
--	constant vsyn : integer := 4;
--	constant vbpor : integer := 23;
--	constant hspol : std_logic := '1';
--	constant vspol : std_logic := '1';	
	
--	--Resolution 640x480 60Hz
--	constant hres : integer := 640;
--	constant hfpor : integer := 16;
--	constant hsyn : integer := 96;
--	constant hbpor : integer := 48;
--	constant vres : integer := 480;
--	constant vfpor : integer := 10;
--	constant vsyn : integer := 2;
--	constant vbpor : integer := 33;
--	constant hspol : std_logic := '1';
--	constant vspol : std_logic := '1';	
	-- display parameters
	constant h_max : integer := hres-1;
	constant hsync_end : integer := hsyn-1;				--hsync-1
	constant hdat_begin : integer := hbpor+hsyn-1;		--(backporch+sync)-1
	constant hdat_end : integer := hdat_begin+hres;		--hdat_begin+640
	constant hpixel_end : integer := hdat_end+hfpor;	--hdat_end+frontporch
	constant v_max : integer := vres-1;
	constant vsync_end : integer := vsyn-1;				--vsync-1
	constant vdat_begin : integer := vbpor+vsyn-1;		--(backporch+sync)-1
	constant vdat_end : integer := vdat_begin+vres;		--vdat_begin+480
	constant vline_end : integer := vdat_end+vfpor;		--vdat_end+frontporch
	signal hcount : integer := 0;
	signal vcount : integer := 0;
--	signal hcount : unsigned(11 downto 0) := (others => '0');
--	signal vcount : unsigned(11 downto 0) := (others => '0');
	
	
	signal data : std_logic_vector(8 downto 0) := "000000000";
	signal h_dat : std_logic_vector(8 downto 0) := "000000000";
	signal v_dat : std_logic_vector(8 downto 0) := "000000000";
	signal CLK_100 : std_logic := '0';
	signal hcount_ov : std_logic := '0';
	signal vcount_ov : std_logic := '0';
	signal dat_act : std_logic := '0';
	signal vga_clk : std_logic := '0';
	signal f1,f2,f3,f4 : std_logic := '0';
	signal f5 : std_logic_vector(3 downto 0) := (others=>'0');
	signal vfbc_start	: std_logic;
	signal va,vb,eof	: std_logic;

	
	-- the signals holding the data to be sent to the lcd on each slot.
	-- this is hardwired on the RGB, hsync and vsync signals.
	signal RX0DATA : std_logic_vector(0 to 6) := "0000000";
	signal RX1DATA : std_logic_vector(0 to 6) := "0000000";
	signal RX2DATA : std_logic_vector(0 to 6) := "0000000";
	signal RX3DATA : std_logic_vector(0 to 6) := "0000000";
	constant CK1DATA : std_logic_vector(0 to 6) := "1100011"; -- this is per spec, the clock 
																					-- is always the same 
	-- internal LVDS signal inputs
	signal CK1IN : std_logic;
	signal RXIN0 : std_logic;
	signal RXIN1 : std_logic;
	signal RXIN2 : std_logic;
	signal RXIN3 : std_logic;
	
	signal color_cur : integer range 0 to 2 := 0;
	
	signal ex : integer range 0 to 2047 := 0;
	signal ye : integer range 0 to 2047 := 0;
	signal delay : natural range 0 to 200000000 := 0;
	
	signal pix_a,pix_b,pix_c : std_logic_vector(7 downto 0) := (others=>'0');
	
 	signal pixel_on : std_logic := '0';
	
begin

	DCM_SP_inst : DCM_SP
		generic map (
			CLKFX_DIVIDE => 1,
			CLKFX_MULTIPLY => 7 -- 25 Mhz * 7 = 175 Mhz clock
		)
		port map (
			CLKFX => clk_fast,
			CLKIN => clk_in,
			RST => '0'
		);

	OBUFDS_CK1IN_inst : OBUFDS
		generic map (IOSTANDARD => "LVDS_33")
		port map (
			O => CK1IN_p,    -- Diff_p output (connect directly to top-level port)
			OB => CK1IN_n,   -- Diff_n output (connect directly to top-level port)
			I => CK1IN       -- Buffer input 
		);

	OBUFDS_RXIN0_inst : OBUFDS
		generic map (IOSTANDARD => "LVDS_33")
		port map (
			O => TX_p(0),    -- Diff_p output (connect directly to top-level port)
			OB => TX_n(0),   -- Diff_n output (connect directly to top-level port)
			I => RXIN0       -- Buffer input 
		);

	OBUFDS_RXIN1_inst : OBUFDS
		generic map (IOSTANDARD => "LVDS_33")
		port map (
			O => TX_p(1),    -- Diff_p output (connect directly to top-level port)
			OB => TX_n(1),   -- Diff_n output (connect directly to top-level port)
			I => RXIN1       -- Buffer input 
		);

	OBUFDS_RXIN2_inst : OBUFDS
		generic map (IOSTANDARD => "LVDS_33")
		port map (
			O => TX_p(2),    -- Diff_p output (connect directly to top-level port)
			OB => TX_n(2),   -- Diff_n output (connect directly to top-level port)
			I => RXIN2       -- Buffer input 
		);
		
	OBUFDS_RXIN3_inst : OBUFDS
		generic map (IOSTANDARD => "LVDS_33")
		port map (
			O => TX_p(3),    -- Diff_p output (connect directly to top-level port)
			OB => TX_n(3),   -- Diff_n output (connect directly to top-level port)
			I => RXIN3       -- Buffer input 
		);	

	-- data enable: should be high when the data is valid for display
	dataenable <= vsync and hsync;

	-- RX1DATA is (blue[7:6], green[7:6], red[7:6])
	RX3DATA(0)	<= '0';
	RX3DATA(1 to 2) <= blue(7 downto 6);
	RX3DATA(3 to 4) <= green(7 downto 6);
	RX3DATA(5 to 6) <= red(7 downto 6);

	-- RX2DATA is (DE, vsync, hsync, blue[5:2])
	RX2DATA(0) <= pix_de;
	RX2DATA(1) <= '0';--vsync;
	RX2DATA(2) <= '0';--hsync;
	RX2DATA(3 to 6) <= blue(5 downto 2);

	-- RX1DATA is (blue[1:0], green[5:1])
	RX1DATA(0 to 1) <= blue(1 downto 0);
	RX1DATA(2 to 6) <= green(5 downto 1);

	-- RX1DATA is (green[0], red[5:0])
	RX0DATA(0) <= green(0);
	RX0DATA(1 to 6) <= red(5 downto 0);

	-- connect signals with the appropriate slot
	RXIN0 <= RX0DATA(slot);
	RXIN1 <= RX1DATA(slot);
	RXIN2 <= RX2DATA(slot);
	RXIN3 <= RX3DATA(slot);
	CK1IN <= CK1DATA(slot);


	hcount_ov <= '1' when(hcount = hpixel_end) else
					 '0';					 

	vcount_ov <= '1' when(vcount = vline_end) else
					 '0';
					 
	f1 <= '1' when(hcount >= hdat_begin) else '0';			
	f2 <= '1' when(hcount < hdat_end) else '0';
	f3 <= '1' when(vcount >= vdat_begin) else '0';		
	f4 <= '1' when(vcount < vdat_end) else '0';	
	f5 <= f1 & f2 & f3 & f4;
		
	pix_de <= '1' when(f5=x"F") else '0';

	process(clk_fast) is
	begin
		if rising_edge(clk_fast) then
			if slot = 6 then
				-- this is the last slot, wrap around
				slot <= 0;--(others=>'0');--0;
				
				if pix_de='1' then
					if ex>=h_max then
						ex <= 0;--(others=>'0');--0;
						if ye>=v_max then
							ye <= 0;--(others=>'0');--0;
						else
							ye <= ye+1;
						end if;
					else
						ex <= ex+1;
					end if;
				end if;
				
				if (hcount_ov='1') then
					hcount <= 0;--(others=>'0');--0;--(others=>'0');			
					
					if (vcount_ov='1') then
						vcount <= 0;--(others=>'0');--0;--(others=>'0');					
					else
						vcount <= vcount + 1;--'1';
					end if;					
				else
					hcount <= hcount + 1; --'1'
				end if;	
				
			else
				slot <= slot + 1;
			end if;
		else
			slot <= slot;
		end if;
	end process;

---- Rainbow Image Generator
	process(clk_fast, en_video)
	begin
		if(rising_edge(clk_fast)) then
--			if pix_de='1' and slot=6 then
--			if en_video='1' then
				if en_video='1' then
						if ye<100 then
							red	<= (others=>'1');
							green	<= (others=>'0');
							blue	<= (others=>'0');
--						elsif ye<200 then
--							red	<= (others=>'0');
--							green	<= (others=>'1');
--							blue	<= (others=>'0');		
--						elsif ye<300 then
--							red	<= (others=>'0');
--							green	<= (others=>'0');
--							blue	<= (others=>'1');	
--						elsif ye<400 then
--							red	<= (others=>'1');
--							green	<= (others=>'1');
--							blue	<= (others=>'0');		
--						elsif ye<500 then
--							red	<= (others=>'0');
--							green	<= (others=>'1');
--							blue	<= (others=>'1');
--						elsif ye<600 then
--							red	<= (others=>'1');
--							green	<= (others=>'0');
--							blue	<= (others=>'1');		
--						elsif ye<700 then
--							red	<= (others=>'1');
--							green	<= (others=>'1');
--							blue	<= (others=>'1');							
						else
							red	<= (others=>'0');
							green	<= (others=>'0');
							blue	<= (others=>'0');							
						end if;	-- end if ye


					elsif en_video='0' then		-- Mode cek dead pixel (lcd test) 
							red	<= (others=>'1');
							green	<= (others=>'1');
							blue	<= (others=>'1');
					else		
						red	<= (others=>'0');
						green	<= (others=>'0');
						blue	<= (others=>'0');					
					end if;	--en_video='1'
--				end if;	
		end if;	--rising edge
	end process;
	
--	process(clk_in) is
--		variable flag : natural range 0 to 5 := 1;
--	begin
--		if rising_edge(clk_in) then
--				if delay<200000000 then
--					delay <= delay + 1;
--				else
--					if en_video='0' then		-- Mode cek dead pixel (lcd test)
--						delay <= 0;					
--					else								-- Mode manu cmfd biasa
--						if flag=1 then
--							pix_a	<= (others=>'1');
--							pix_b	<= (others=>'0');
--							pix_c	<= (others=>'0');
--							flag := flag + 1;
--						elsif flag=2 then
--							pix_a	<= (others=>'0');
--							pix_b	<= (others=>'1');
--							pix_c	<= (others=>'0');
--							flag := flag + 1;
--						elsif flag=3 then
--							pix_a	<= (others=>'0');
--							pix_b	<= (others=>'0');
--							pix_c	<= (others=>'1');
--							flag := 1;
--						else
--							pix_a	<= pix_a;
--							pix_b	<= pix_b;
--							pix_c	<= pix_c;
--							flag := 1;							
--						end if;
--						delay <= 0;
--					end if;
--				end if;
--		end if;
--	end process;	

end Behavioral;

