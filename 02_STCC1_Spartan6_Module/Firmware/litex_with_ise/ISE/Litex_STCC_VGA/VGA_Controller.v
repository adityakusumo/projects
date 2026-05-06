//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:    Aditya (Converted to Verilog)
// 
// Create Date: 2024
// Module Name: VGA_Controller
// Description: VGA Controller 800x600, 72Hz (Default)
//////////////////////////////////////////////////////////////////////////////////

module VGA_Controller #(
    // 800 x 600, 72Hz default constants
    parameter H_PIXELS       = 800,   // Horizontal display pixels
    parameter V_PIXELS       = 600,   // Vertical display pixels
    parameter H_FRONTPORCH   = 56,    // Horizontal Frontporch
    parameter H_SYNC_PULSE   = 120,   // Hsync Pulse
    parameter H_BACKPORCH    = 64,    // Horizontal Backporch
    parameter V_FRONTPORCH   = 37,    // Vertical Frontporch
    parameter V_SYNC_PULSE   = 6,     // Vsync Pulse
    parameter V_BACKPORCH    = 23,    // Vertical Backporch
    parameter H_POLARITY     = 1'b1,  // Hsync Pulse polarity
    parameter V_POLARITY     = 1'b1   // Vsync Pulse polarity
)(
    input  wire       vga_clk,        // Pixel clock in
    input  wire       rstn,           // Async active-low reset
	 input  wire [23:0] obj_color,
    output wire       vga_clk_out,    // Pixel clock out
//    output wire       vga_blank_n,    // Blank signal to ADV7125
//    output wire       vga_sync_n,     // Sync signal to ADV7125
    output reg        vga_hsync,      // Hsync Pulse to ADV7125
    output reg        vga_vsync,      // Vsync pulse to ADV7125
    output wire [7:0] vga_r,
    output wire [7:0] vga_g,
    output wire [7:0] vga_b
);

    // All constants derived from parameters
    localparam H_PERIOD = H_SYNC_PULSE + H_FRONTPORCH + H_PIXELS + H_BACKPORCH;
    localparam V_PERIOD = V_SYNC_PULSE + V_FRONTPORCH + V_PIXELS + V_BACKPORCH;

    // All internal signals
    reg [11:0] h_count = 0; // To keep track of horizontal pixel count
    reg [11:0] v_count = 0; // To keep track of vertical pixel count
    reg [31:0] row = 0;
    reg [31:0] col = 0;
	 
	 wire [23:0]  obj_color_w;
	 wire [23:0]  bkg_color_w;

    // Instantiate image_gen module
    image_gen u1 (
        .clk(vga_clk),
        .row(row),
        .col(col),
		  .obj_color(obj_color_w),
		  .bkg_color(bkg_color_w),		  
        .red(vga_r),
        .green(vga_g),
        .blue(vga_b)
    );

    // Static assignments for ADV7125 control signals
    assign vga_clk_out = vga_clk;
    assign vga_sync_n  = 1'b0; // Usually tied low if not used
    assign vga_blank_n = (h_count < H_PIXELS && v_count < V_PIXELS);
	 assign obj_color_w = obj_color;
	 assign bkg_color_w = 24'hFFFFFF;
	 
    //==========================================================================
    // PROCESS TO GENERATE SYNC PULSES AND UPDATE PIXEL COUNT
    //==========================================================================
    always @(posedge vga_clk or negedge rstn) begin
        if (!rstn) begin
            vga_hsync <= !H_POLARITY;
            vga_vsync <= !V_POLARITY;
            h_count   <= 0;
            v_count   <= 0;
            row       <= 0;
            col       <= 0;
        end else begin
            // Pixel Counter Logic
            if (h_count <= H_PERIOD - 1) begin
                h_count <= h_count + 1;
            end else begin
                h_count <= 0;
                if (v_count <= V_PERIOD - 1) begin
                    v_count <= v_count + 1;
                end else begin
                    v_count <= 0;
                end
            end

            // Set pixel coordinates (Display Time only)
            if (h_count < H_PIXELS) begin
                col <= h_count;
            end
            if (v_count < V_PIXELS) begin
                row <= v_count;
            end

            // Horizontal Sync Pulse Generation
            if ((h_count >= H_PIXELS + H_FRONTPORCH) && 
                (h_count < H_PIXELS + H_FRONTPORCH + H_SYNC_PULSE)) begin
                vga_hsync <= H_POLARITY;
            end else begin
                vga_hsync <= !H_POLARITY;
            end

            // Vertical Sync Pulse Generation
            if ((v_count >= V_PIXELS + V_FRONTPORCH) && 
                (v_count < V_PIXELS + V_FRONTPORCH + V_SYNC_PULSE)) begin
                vga_vsync <= V_POLARITY;
            end else begin
                vga_vsync <= !V_POLARITY;
            end
        end
    end

endmodule