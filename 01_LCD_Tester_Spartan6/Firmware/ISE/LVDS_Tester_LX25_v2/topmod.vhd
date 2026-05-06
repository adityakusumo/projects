----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:29:48 02/25/2021 
-- Design Name: 
-- Module Name:    topmod - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity topmod is
	port(
		clk_in	: in std_logic;
		rst_n		: in std_logic;
		usr_btn	: in std_logic_vector(1 downto 0);
		
		led_o		: out std_logic_vector(2 downto 0);
		
		bist_o	: out std_logic;
		
--		rx_i		: in std_logic;
--		tx_o		: out std_logic;	

		-- LVDS Out 2 --
		data_out_p2	: out std_logic_vector(3 downto 0);
		data_out_n2	: out std_logic_vector(3 downto 0);
		clk_out_p2	: out std_logic;
		clk_out_n2	: out std_logic--;	
		
	);
end topmod;

architecture Behavioral of topmod is

	component clk_gen
		port
		(	-- Clock in ports
			CLK_IN1           : in     std_logic;
			-- Clock out ports
			CLK_OUT1          : out    std_logic;
			CLK_OUT2          : out    std_logic--;
			-- Status and control signals
--			RESET             : in     std_logic
		);
	end component;
	
	component clk_functional
		port
		(	-- Clock in ports
			CLK_IN1           : in     std_logic;
			-- Clock out ports
			CLK_OUT1          : out    std_logic;
			CLK_OUT2          : out    std_logic--;
--			LOCKED				  : out	  std_logic
			-- Status and control signals
--			RESET             : in     std_logic
		);
	end component;	
	
	component UART
		port(  	
			tx_data_in : in std_logic_vector( 7 downto 0 ) ;                            
			tx_load    : in std_logic ;                     
			tx_intr    : out std_logic ;   
			tx_data_out: out std_logic ;		--true serial output
			baud_rate  : in std_logic_vector(3 downto 0);
			rx_data_out: out std_logic_vector( 7 downto 0 ) ; 
			rx_intr    : out std_logic ;                     
			rx_data_in : in std_logic  ; 		--true serial input       
			clock_in   : in std_logic ;
			enable     : in std_logic ; 
			ERROR      : out std_logic ;     
			reset      : in std_logic 
			 );
	end component;		
	
	component lvds_transmit
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
		bist : out std_logic;
		en_video	: in std_logic;
		rainbow	: in std_logic;
		clk_in  : in   STD_LOGIC
	);
	end component;
	
	component lvds_transmit_verilog
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
		locked	: in std_logic;
		clk_slow : in   STD_LOGIC;
		clk_in  : in   STD_LOGIC
	);
	end component;	
	
	component blink_led
	 port (
		  clk : in  std_logic;
		  rst : in  std_logic;
		  led : out std_logic
	 );
	end component;		
	
	COMPONENT embe
	PORT(
		fpga_0_clk_1_sys_clk_pin : IN std_logic;
		fpga_0_rst_1_sys_rst_pin : IN std_logic;
		xps_uartlite_0_RX_pin : IN std_logic;          
		fpga_0_LEDS_GPIO_IO_O_pin : OUT std_logic_vector(0 to 1);
		xps_uartlite_0_TX_pin : OUT std_logic;
		clock_generator_0_CLKOUT1_pin : OUT std_logic
		);
	END COMPONENT;

	attribute box_type : string;
	attribute box_type of embe : component is "user_black_box";

	signal mb_clk,clk_bus_b,clk_bus,rst_bus,clk_xxmhz,clk_xxmhzbuf,clk_led : std_logic;

	signal led_s : std_logic := '0';
	signal locked_s	: std_logic;
	
	signal pix_red_i,pix_grn_i,pix_blu_i	: std_logic_vector(7 downto 0);
	signal lvds_i_en,lvds_o_en,lvds_clk_o	: std_logic;
	signal pix_hd_r,pix_vd_r,pix_de_r	: std_logic;
	signal io_clk_o,io_strobe_o : std_logic;
	
	signal wr_clk, wr_rst, rd_clk, rd_rst, wr_en, rd_en : STD_LOGIC;
	signal din	: STD_LOGIC_VECTOR(1023 DOWNTO 0);
	signal dout : STD_LOGIC_VECTOR(1023 DOWNTO 0);
	signal full, empty : STD_LOGIC;
	
	signal en_video_s, en_disc_s : std_logic;
	signal bist_s, rainbow_s	: std_logic;
	
	-- Signals for Uart Pulse
	type txt_arr_t is array(0 to 7) of std_logic_vector(7 downto 0);
	signal txt_arr : txt_arr_t;
	signal timer_test	: natural range 0 to 50000000;
	signal state_test,state_seq	: natural range 0 to 7;
	signal tx_data_out,rx_data_in 			: std_logic;
	signal tx_en,tx_done 						: std_logic;
	signal data_send,data_recv,data_bridge : std_logic_vector(7 downto 0);		

begin
--	en_video_s	<= not(usr_btn) nand en_disc_s;
	en_video_s	<= usr_btn(0);
	rainbow_s	<= usr_btn(1);
	bist_o	<= bist_s;

--	clock_generator : clk_gen
--	port map
--	(	 -- Clock in ports
--		 CLK_IN1 => clk_in,
--		 -- Clock out ports
--		 CLK_OUT1 => clk_led,--clk_xxmhz,
--		 CLK_OUT2 => clk_xxmhzbuf
--		 -- Status and control signals
----		 RESET  => '0'
--	 );
	 
	clock_generator : clk_functional
	port map
	(	 -- Clock in ports
		 CLK_IN1 => clk_in,
		 -- Clock out ports
		 CLK_OUT1 => clk_xxmhzbuf,--clk_xxmhzbuf,clk_led
		 CLK_OUT2 => clk_led--,
--		 LOCKED	=> open--locked_s
		 -- Status and control signals
--		 RESET  => '0'
	 );	 

--	Inst_embe: embe PORT MAP(
--		fpga_0_LEDS_GPIO_IO_O_pin(0) => en_disc_s,--open,--en_video_s,
--		fpga_0_LEDS_GPIO_IO_O_pin(1) => led_s,
--		fpga_0_clk_1_sys_clk_pin => clk_in,
--		fpga_0_rst_1_sys_rst_pin => '0',
--		xps_uartlite_0_RX_pin => rx_i,
--		xps_uartlite_0_TX_pin => tx_o,
--		clock_generator_0_CLKOUT1_pin => clk_xxmhzbuf
--		);	

	LVDS_Tx2 : lvds_transmit
	port map(
		clk_in		=> clk_xxmhzbuf,--clk_xxmhzbuf,
--		clk_slow		=> clk_led,
--		locked		=> locked_s,
		en_video		=> en_video_s,
		rainbow		=> rainbow_s,
		bist			=> bist_s,
		
		CK1IN_p		=> clk_out_p2,
		CK1IN_n		=> clk_out_n2,
		TX_p			=> data_out_p2,
		TX_n			=> data_out_n2
--		RXIN0_p		=> data_out_p2(0),
--		RXIN0_n		=> data_out_n2(0),
--		RXIN1_p		=> data_out_p2(1),
--		RXIN1_n		=> data_out_n2(1),
--		RXIN2_p		=> data_out_p2(2),
--		RXIN2_n		=> data_out_n2(2),
--		RXIN3_p		=> data_out_p2(3),
--		RXIN3_n		=> data_out_n2(3)	
	);
	
--	LVDS_Tx2 : lvds_transmit_verilog
--	port map(
--		clk_in		=> clk_xxmhzbuf,--clk_xxmhzbuf,
--		clk_slow		=> clk_led,
--		locked		=> locked_s,
--		en_video		=> en_video_s,	
--		
--		CK1IN_p		=> clk_out_p2,
--		CK1IN_n		=> clk_out_n2,
--		TX_p			=> data_out_p2,
--		TX_n			=> data_out_n2
----		RXIN0_p		=> data_out_p2(0),
----		RXIN0_n		=> data_out_n2(0),
----		RXIN1_p		=> data_out_p2(1),
----		RXIN1_n		=> data_out_n2(1),
----		RXIN2_p		=> data_out_p2(2),
----		RXIN2_n		=> data_out_n2(2),
----		RXIN3_p		=> data_out_p2(3),
----		RXIN3_n		=> data_out_n2(3)	
--	);		
	
--	LVDS_Tx2 : lvds_transmit_verilog
--	port map(
--		clk_in		=> clk_xxmhzbuf,
--		en_video		=> en_video_s,		
--		
--		CK1IN_p		=> clk_out_p2,
--		CK1IN_n		=> clk_out_n2,
--		RXIN0_p		=> data_out_p2(0),
--		RXIN0_n		=> data_out_n2(0),
--		RXIN1_p		=> data_out_p2(1),
--		RXIN1_n		=> data_out_n2(1),
--		RXIN2_p		=> data_out_p2(2),
--		RXIN2_n		=> data_out_n2(2),
--		RXIN3_p		=> data_out_p2(3),
--		RXIN3_n		=> data_out_n2(3)	
--	);		
	
	u_blink : blink_led
	port map (
		clk => clk_led, -- Your 80MHz clock source
		rst => rst_n,
		led => led_s     -- Connect to your FPGA pin
	);	
	
	led_o(0) <= led_s;
	
	led_o(1) <= '0';
	led_o(2) <= '0';


end Behavioral;

