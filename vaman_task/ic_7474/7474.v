
module ic_7474(
    input wire P,
    input wire Q,
    input wire R,
    output reg F_led
);

wire clk;

// Instantiate board clock
qlal4s3b_cell_macro u_qlal4s3b_cell_macro (
    .Sys_Clk0 (clk)
);

// Combinational logic for F
wire F_comb;
assign F_comb = (P & Q) | (Q & ~R) | (P & ~R);

// D flip-flop behavior using FPGA clock
reg F_dff;
always @(posedge clk) begin
    F_dff <= F_comb;
    F_led <= F_dff;  // Output to LED
end

endmodule
