`timescale 1ns / 1ps

module lvds_transmit_verilog (
    // LVDS Pins
    output wire [3:0] TX_p, TX_n,
	 output wire CK1IN_p, CK1IN_n,
	 
    
    // Inputs
    input wire en_video,
	 input wire locked,
	 input wire clk_slow,
    input wire clk_in
);

	// --- Signals and Registers ---
	reg [7:0] red = 0, green = 8'h00, blue = 8'h00;
	reg [2:0] slot = 0;  // Optimized 3-bit slot

	// Optimized 12-bit counters (more efficient than 32-bit integers)
	reg [11:0] hcount = 0;
	reg [11:0] vcount = 0;
	reg [11:0] ex = 0;
	reg [11:0] ye = 0;

	localparam S = 7;
	localparam D = 4;
	
	// Custom Resolution 60Hz
	localparam hres = 480;
	localparam hfpor = 20;
	localparam hsyn = 10;
	localparam hbpor = 20;
	localparam vres = 640;
	localparam vfpor = 2;
	localparam vsyn = 2;
	localparam vbpor = 10;
//	localparam hspol : std_logic := '0';
//	localparam vspol : std_logic := '0';	

	// Custom Resolution Constants (800x1280)
//	localparam hres    = 800;
//	localparam hfpor   = 20;
//	localparam hsyn    = 10;
//	localparam hbpor   = 24;
//	localparam vres    = 1280;
//	localparam vfpor   = 1;
//	localparam vsyn    = 4;
//	localparam vbpor   = 23;

	// Calculation constants
	localparam hmax = hres-1;
	localparam hdat_begin = hbpor + hsyn - 1;
	localparam hdat_end   = hdat_begin + hres;
	localparam hpixel_end = hdat_end + hfpor;
	localparam vmax = vres-1;
	localparam vdat_begin = vbpor + vsyn - 1;
	localparam vdat_end   = vdat_begin + vres;
	localparam vline_end  = vdat_end + vfpor;

	// Control Signals
	wire hcount_ov = (hcount == hpixel_end);
	wire vcount_ov = (vcount == vline_end);
	wire pix_de    = (hcount >= hdat_begin && hcount < hdat_end && 
						 vcount >= vdat_begin && vcount < vdat_end);
//	wire pix_de    = 1'b1;						 

	// --- LVDS Data Mapping ---
	reg [0:6] rx0_data, rx1_data, rx2_data, rx3_data;
	localparam [S-1:0] TX_CLK_GEN = 7'b1100011;
	
	wire ioclk_to_serdes, strobe_to_serdes, pixel_clk;
	wire [D*S-1:0] datain;
	 
	clock_generator_sdr_s8_diff #(
		.S(S),              // IMPORTANT: Set to 7 for LVDS Display standard
		.DIFF_TERM("TRUE")  // Internal 100-ohm termination for the input clock
	) u_clk_gen (
//		.clkin_p(board_clk_p),     // Differential input from pin
//		.clkin_n(board_clk_n),     // Differential input from pin
		.clkin(clk_in),
		.clkslow(clk_slow),
		.locked(locked),
		.ioclka(ioclk_to_serdes),  // Connect to OSERDES2 CLK0
		.serdesstrobea(strobe_to_serdes), // Connect to OSERDES2 IOCE
		.ioclkbp(open),                // Leave unconnected if not used
		.ioclkbn(open),
		.serdesstrobeb(open),
		.gclk(pixel_clk)           // Global clock for your HCOUNT/VCOUNT logic
	);
	
	serdes_n_to_1_s8_diff #(
		.S(S),   			// Parameter to set the serdes factor 1..8
		.D(1)//,			// Set the number of inputs and outputs
//		.DATA_STRIPING = "PER_CLOCK" ;	
	) clk_gen_diff (
    .txioclk(ioclk_to_serdes), 
    .txserdesstrobe(strobe_to_serdes), 
    .reset(1'b0), 
    .gclk(pixel_clk), 
    .datain(TX_CLK_GEN), 
    .dataout_p(CK1IN_p), 
    .dataout_n(CK1IN_n)
   );	
	
	serdes_n_to_1_s8_diff #(
		.S(S),   			// Parameter to set the serdes factor 1..8
		.D(D)//,			// Set the number of inputs and outputs
//		.DATA_STRIPING = "PER_CLOCK" ;	
	) dat_gen_diff (
    .txioclk(ioclk_to_serdes), 
    .txserdesstrobe(strobe_to_serdes), 
    .reset(1'b0), 
    .gclk(pixel_clk), 
    .datain(datain), 
    .dataout_p(TX_p), 
    .dataout_n(TX_n)
   );		
	
//	assign datain = {7'b0000000 , 7'b0000000 , 7'b0000000 , 7'b1111111};
	assign datain[0] = 1'b0;
	assign datain[1] = pix_de;
	assign datain[2] = blue[1];
	assign datain[3] = green[0];
	assign datain[4] = blue[7];
	assign datain[5] = 1'b0;
	assign datain[6] = blue[0];
	assign datain[7] = red[5];
	assign datain[8] = blue[6];
	assign datain[9] = 1'b0;
	assign datain[10] = green[5];
	assign datain[11] = red[4];
	assign datain[12] = green[7];
	assign datain[13] = blue[5];
	assign datain[14] = green[4];
	assign datain[15] = red[3];	
	assign datain[16] = green[6];
	assign datain[17] = blue[4];
	assign datain[18] = green[3];
	assign datain[19] = red[2];
	assign datain[20] = red[7];
	assign datain[21] = blue[3];
	assign datain[22] = green[2];
	assign datain[23] = red[1];
	assign datain[24] = red[6];
	assign datain[25] = blue[2];
	assign datain[26] = green[1];
	assign datain[27] = red[0];	
	
//    always @(*) begin
//        rx3_data = {1'b0, blue[7:6], green[7:6], red[7:6]};
//        rx2_data = {pix_de, 1'b0, 1'b0, blue[5:2]}; // VS/HS forced to 0 per VHDL
//        rx1_data = {blue[1:0], green[5:1]};
//        rx0_data = {green[0], red[5:0]};
//    end

	// --- Sequential Logic ---
	always @(posedge pixel_clk) begin
		// Pixel logic (ex, ye)
		if (pix_de) begin
			if (ex >= hmax) begin
			  ex <= 0;
			  ye <= (ye >= vmax) ? 0 : ye + 1;
			end else begin
			  ex <= ex + 1;
			end
		end

		// Hardware timing counters
		if (hcount_ov) begin
			hcount <= 0;
			vcount <= vcount_ov ? 0 : vcount + 1;
		end else begin
			hcount <= hcount + 1;
		end
	end

    // --- RGB Data Selection ---
    always @(posedge pixel_clk) begin
        if (pix_de) begin
            if (en_video) begin
                // "Mode menu cmfd biasa"
                if (ye < 100) begin
                    red <= 8'hFF; green <= 8'h00; blue <= 8'h00; // Green bar
                end else begin
                    red <= 8'h00; green <= 8'h00; blue <= 8'h00; // Black
                end
            end else begin
                // "Mode cek dead pixel" (White Screen)
                red <= 8'hFF; green <= 8'hFF; blue <= 8'hFF;
            end
        end
    end

endmodule