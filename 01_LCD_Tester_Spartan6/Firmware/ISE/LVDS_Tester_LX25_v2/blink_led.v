`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:01:06 02/20/2026 
// Design Name: 
// Module Name:    blink_led 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module blink_led (
    input  clk,      // 80MHz input clock
	 input  rst,		// Active high reset
    output reg led   // LED output
);

    // 26-bit counter to accommodate 40,000,000
    reg [25:0] count = 0;

	 always @(posedge clk or posedge rst) begin
        if (rst) begin
            // This block executes immediately when rst goes high
            count <= 0;
            led   <= 0;
		  end else begin
			  if (count == 39_999_999) begin
					count <= 0;
					led   <= ~led; // Toggle LED state
			  end else begin
					count <= count + 1;
			  end
		  end
    end

endmodule
