LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY embe IS
PORT (
	fpga_0_LEDS_GPIO_IO_O_pin : OUT STD_LOGIC_VECTOR(0 TO 1);
	fpga_0_clk_1_sys_clk_pin : IN STD_LOGIC;
	fpga_0_rst_1_sys_rst_pin : IN STD_LOGIC;
	clock_generator_0_CLKOUT1_pin : OUT STD_LOGIC;
	xps_uartlite_0_RX_pin : IN STD_LOGIC;
	xps_uartlite_0_TX_pin : OUT STD_LOGIC
	);
END embe;

ARCHITECTURE STRUCTURE OF embe IS

BEGIN
END ARCHITECTURE STRUCTURE;
