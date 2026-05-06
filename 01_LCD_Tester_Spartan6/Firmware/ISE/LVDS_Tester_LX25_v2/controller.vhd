library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

library UNISIM;
use UNISIM.VComponents.all;

entity lvds_transmit is
    Port (  
        clk_in   : in  STD_LOGIC;	-- 40MHz clock
        en_video : in  STD_LOGIC;	-- input button for activating bist mode (lcd's built in self test mode); active low
        rainbow  : in  STD_LOGIC;	-- input button for white screen (deactivating rainbow stripe); active low
        bist     : out STD_LOGIC;	-- bist mode (lcd's built in self test mode) output pin; active high (connected to HSD104JPW1-A10 CMFD 10.4 lcd 1st pin)
        -- LVDS Outputs
        CK1IN_p  : out STD_LOGIC;	-- LVDS positive clock
        CK1IN_n  : out STD_LOGIC;	-- LVDS negative clock
        TX_p     : out std_logic_vector(3 downto 0);	-- LVDS positive data line
        TX_n     : out std_logic_vector(3 downto 0)	-- LVDS negative data line
    );
end lvds_transmit;

architecture Behavioral of lvds_transmit is

    -- ============================================================
    -- RESOLUTION CONSTANTS (Custom 960x1280 @ 60Hz)
    -- ============================================================
    constant hres : integer := 960;
    constant vres : integer := 1280;
    
    -- Horizontal Timing
    constant hfpor : integer := 20;
    constant hsyn  : integer := 10;
    constant hbpor : integer := 30;
    
    -- Vertical Timing
    constant vfpor : integer := 10;
    constant vsyn  : integer := 4;
    constant vbpor : integer := 26;

    -- Derived Timing Boundaries
    constant h_max       : integer := hres - 1;
    constant hdat_begin  : integer := hbpor + hsyn - 1;
    constant hdat_end    : integer := hdat_begin + hres;
    constant hpixel_end  : integer := hdat_end + hfpor;
    
    constant v_max       : integer := vres - 1;
    constant vdat_begin  : integer := vbpor + vsyn - 1;
    constant vdat_end    : integer := vdat_begin + vres;
    constant vline_end   : integer := vdat_end + vfpor;

    -- ============================================================
    -- COLOR BAR / RAINBOW LOGIC
    -- ============================================================
    constant num_segments : integer := 8;
    constant increment    : integer := vres / num_segments;
    type line_array is array (0 to num_segments-1) of integer;

    constant line : line_array := (
         0 => increment * 1, 1 => increment * 2, 2 => increment * 3, 3 => increment * 4,
         4 => increment * 5, 5 => increment * 6, 6 => increment * 7, 7 => increment * 8
    );

    -- ============================================================
    -- SIGNALS
    -- ============================================================
    signal clk_fast : std_logic;
    signal slot     : integer range 0 to 6 := 0;
    
    -- Internal Counters
    signal hcount   : integer := 0;
    signal vcount   : integer := 0;
    signal ex       : integer range 0 to 2047 := 0;
    signal ye       : integer range 0 to 2047 := 0;

    -- Color Signals
    signal red, green, blue : std_logic_vector(7 downto 0);
    signal red_rainbow, green_rainbow, blue_rainbow : std_logic_vector(7 downto 0);
    
    -- Control Signals
    signal pix_de    : std_logic;
    signal hcount_ov : std_logic;
    signal vcount_ov : std_logic;

    -- LVDS Internal Wires
    signal RX0DATA, RX1DATA, RX2DATA, RX3DATA : std_logic_vector(0 to 6);
    constant CK1DATA : std_logic_vector(0 to 6) := "1100011";
    signal CK1IN, RXIN0, RXIN1, RXIN2, RXIN3 : std_logic;

begin

    -- 1. CLOCK GENERATION (Spartan-6 DCM)
    DCM_SP_inst : DCM_SP
        generic map (
            CLKFX_DIVIDE   => 1,
            CLKFX_MULTIPLY => 7  -- 40MHz * 7 = 280MHz
        )
        port map (
            CLKFX => clk_fast,
            CLKIN => clk_in,
            RST   => '0'
        );

    -- 2. DISPLAY TIMING LOGIC
    hcount_ov <= '1' when (hcount = hpixel_end) else '0';
    vcount_ov <= '1' when (vcount = vline_end)  else '0';
    
    -- Data Enable (Active Video Area)
    pix_de <= '1' when (hcount >= hdat_begin and hcount < hdat_end and 
                        vcount >= vdat_begin and vcount < vdat_end) else '0';

    bist <= not en_video;

    -- 3. MAIN COUNTER PROCESS
    process(clk_fast)
    begin
        if rising_edge(clk_fast) then
            -- LVDS Bitstream Mapping
            RX3DATA(0)      <= '0';
            RX3DATA(1 to 2) <= blue(7 downto 6);
            RX3DATA(3 to 4) <= green(7 downto 6);
            RX3DATA(5 to 6) <= red(7 downto 6);

            RX2DATA(0)      <= pix_de;
            RX2DATA(1 to 2) <= "00"; -- HSync and VSync tied low
            RX2DATA(3 to 6) <= blue(5 downto 2);

            RX1DATA(0 to 1) <= blue(1 downto 0);
            RX1DATA(2 to 6) <= green(5 downto 1);

            RX0DATA(0)      <= green(0);
            RX0DATA(1 to 6) <= red(5 downto 0);

            -- Serialize Data to Inputs
            RXIN0 <= RX0DATA(slot);
            RXIN1 <= RX1DATA(slot);
            RXIN2 <= RX2DATA(slot);
            RXIN3 <= RX3DATA(slot);
            CK1IN <= CK1DATA(slot);

            -- Timing and Pixel Step Logic
            if slot = 6 then
                slot <= 0;
                
                -- Update Coordinate Counters for the Generator
                if pix_de = '1' then
                    if ex >= h_max then
                        ex <= 0;
                        if ye >= v_max then ye <= 0; else ye <= ye + 1; end if;
                    else
                        ex <= ex + 1;
                    end if;
                end if;

                -- Update Global Sync Counters
                if hcount_ov = '1' then
                    hcount <= 0;
                    if vcount_ov = '1' then vcount <= 0; else vcount <= vcount + 1; end if;
                else
                    hcount <= hcount + 1;
                end if;
            else
                slot <= slot + 1;
            end if;
        end if;
    end process;

    -- 4. RAINBOW GENERATOR LOGIC (Combinational)
    red_rainbow   <= (others => '1') when (ye < line(0)) else (others => '0') when (ye < line(1)) else
                     (others => '0') when (ye < line(2)) else (others => '1') when (ye < line(3)) else
                     (others => '0') when (ye < line(4)) else (others => '1') when (ye < line(5)) else
                     (others => '1') when (ye < line(6)) else (others => '0');

    green_rainbow <= (others => '0') when (ye < line(0)) else (others => '1') when (ye < line(1)) else
                     (others => '0') when (ye < line(2)) else (others => '1') when (ye < line(3)) else
                     (others => '1') when (ye < line(4)) else (others => '0') when (ye < line(5)) else
                     (others => '1') when (ye < line(6)) else (others => '0');

    blue_rainbow  <= (others => '0') when (ye < line(0)) else (others => '0') when (ye < line(1)) else
                     (others => '1') when (ye < line(2)) else (others => '0') when (ye < line(3)) else
                     (others => '1') when (ye < line(4)) else (others => '1') when (ye < line(5)) else
                     (others => '1') when (ye < line(6)) else (others => '0');

    -- Final Color Mux
    red   <= red_rainbow   when (rainbow = '1') else (others => '1');
    green <= green_rainbow when (rainbow = '1') else (others => '1');
    blue  <= blue_rainbow  when (rainbow = '1') else (others => '1');

    -- 5. LVDS OUTPUT BUFFERS
    OBUFDS_CK  : OBUFDS generic map (IOSTANDARD => "LVDS_33") port map (O => CK1IN_p, OB => CK1IN_n, I => CK1IN);
    OBUFDS_TX0 : OBUFDS generic map (IOSTANDARD => "LVDS_33") port map (O => TX_p(0), OB => TX_n(0), I => RXIN0);
    OBUFDS_TX1 : OBUFDS generic map (IOSTANDARD => "LVDS_33") port map (O => TX_p(1), OB => TX_n(1), I => RXIN1);
    OBUFDS_TX2 : OBUFDS generic map (IOSTANDARD => "LVDS_33") port map (O => TX_p(2), OB => TX_n(2), I => RXIN2);
    OBUFDS_TX3 : OBUFDS generic map (IOSTANDARD => "LVDS_33") port map (O => TX_p(3), OB => TX_n(3), I => RXIN3);

end Behavioral;