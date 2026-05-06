
-- VHDL Instantiation Created from source file clock_generator_sdr_s8_diff.vhd -- 13:08:57 02/25/2026
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT clock_generator_sdr_s8_diff
	PORT(
		clkin_p : IN std_logic;
		clkin_n : IN std_logic;          
		ioclka : OUT std_logic;
		serdesstrobea : OUT std_logic;
		ioclkbp : OUT std_logic;
		ioclkbn : OUT std_logic;
		serdesstrobeb : OUT std_logic;
		gclk : OUT std_logic
		);
	END COMPONENT;

	Inst_clock_generator_sdr_s8_diff: clock_generator_sdr_s8_diff PORT MAP(
		clkin_p => ,
		clkin_n => ,
		ioclka => ,
		serdesstrobea => ,
		ioclkbp => ,
		ioclkbn => ,
		serdesstrobeb => ,
		gclk => 
	);


