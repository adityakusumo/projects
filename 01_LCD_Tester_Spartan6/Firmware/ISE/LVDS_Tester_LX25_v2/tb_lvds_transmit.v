`timescale 1ns / 1ps

module tb_lvds_transmit();

    // Parameters
    parameter real CLK_FREQ_MHZ = 140.0;
    parameter real CLK_PERIOD = 1000.0 / CLK_FREQ_MHZ; // 7.142 ns

    // Inputs
    reg clk_in;
    reg en_video;

    // Outputs
    wire [3:0] TX_p;
    wire [3:0] TX_n;

    // Unit Under Test (UUT)
    lvds_transmit_verilog uut (
        .TX_p(TX_p),
        .TX_n(TX_n),
        .en_video(en_video),
        .clk_in(clk_in)
    );

    // Differential signals for easier waveform viewing
    // (In your waveform viewer, look at these to see the 'logical' bit)
    wire [3:0] TX_diff = TX_p ^ TX_n; 

    // 140 MHz Clock Generation
    initial begin
        clk_in = 0;
        forever #(CLK_PERIOD / 2.0) clk_in = ~clk_in;
    end

    // Test Sequence
    initial begin
        // Initialize inputs
        en_video = 1'b1;  // Set constant to 1 as requested
        
        $display("Starting LVDS Simulation...");
        $display("Input Clock: 140 MHz");
        
        // Wait for the internal PLL/DCM and Counters to start
        #(CLK_PERIOD * 100);
        
        $display("Simulation running. Check TX pins for high-speed toggling.");

        // Run simulation for enough time to see multiple lines of video
        // For a 480x640 display, one horizontal line is ~25,000ns
        #50000; 

        $display("Simulation complete.");
        $finish;
    end

endmodule