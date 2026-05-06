
-- VHDL Instantiation Created from source file embe.vhd -- 10:57:56 06/22/2021
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT embe
	PORT(
		fpga_0_clk_1_sys_clk_pin : IN std_logic;
		fpga_0_rst_1_sys_rst_pin : IN std_logic;
		xps_uartlite_0_RX_pin : IN std_logic;          
		fpga_0_LEDS_GPIO_IO_O_pin : OUT std_logic_vector(0 to 1);
		clock_generator_0_CLKOUT1_pin : OUT std_logic;
		xps_uartlite_0_TX_pin : OUT std_logic
		);
	END COMPONENT;

attribute box_type : string;
attribute box_type of embe : component is "user_black_box";


	Inst_embe: embe PORT MAP(
		fpga_0_LEDS_GPIO_IO_O_pin => ,
		fpga_0_clk_1_sys_clk_pin => ,
		fpga_0_rst_1_sys_rst_pin => ,
		clock_generator_0_CLKOUT1_pin => ,
		xps_uartlite_0_RX_pin => ,
		xps_uartlite_0_TX_pin => 
	);



