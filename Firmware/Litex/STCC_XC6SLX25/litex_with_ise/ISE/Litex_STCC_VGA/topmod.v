`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:42:39 01/08/2026 
// Design Name: 
// Module Name:    topmod 
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
module topmod(
    input  wire          clk100,
    inout  wire          i2c0_scl,
    inout  wire          i2c0_sda,
    input  wire          serial_rx,
    output wire          serial_tx,
    input  wire          rst_btn0,
	 input  wire          user_btn,
    output wire          user_led0,
    output wire       	 vga_clk_out,    // Pixel clock out
//    output wire       vga_blank_n,    // Blank signal to ADV7125
//    output wire       vga_sync_n,     // Sync signal to ADV7125
    output wire        vga_hsync,      // Hsync Pulse to ADV7125
    output wire        vga_vsync,      // Vsync pulse to ADV7125
    output wire [7:0] vga_r,
    output wire [7:0] vga_g,
    output wire [7:0] vga_b
    );
	 
	wire [23:0]  obj_color_w;

	spartan6_board u1(
		.clk100(clk100),
		.from_litex_ctrl(obj_color_w),
		.i2c0_scl(i2c0_scl),
		.i2c0_sda(i2c0_sda),
		.serial_rx(serial_rx),
		.serial_tx(serial_tx),
		.rst_btn0(rst_btn0),
		.user_led0(user_led0),
		.user_btn(user_btn)
	);
	
	VGA_Controller u2(
		.vga_clk(clk100),        // Pixel clock in
		.rstn(rst_btn0),           // Async active-low reset
		.obj_color(obj_color_w),
		.vga_clk_out(vga_clk_out),    // Pixel clock out
//		.vga_blank_n(),    // Blank signal to ADV7125
//		.vga_sync_n(),     // Sync signal to ADV7125
		.vga_hsync(vga_hsync),      // Hsync Pulse to ADV7125
		.vga_vsync(vga_vsync),      // Vsync pulse to ADV7125
		.vga_r(vga_r),
		.vga_g(vga_g),
		.vga_b(vga_b)
	);

endmodule
