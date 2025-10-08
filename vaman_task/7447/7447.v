module ic_7447(
    input wire P,
    input wire Q,
    input wire R,
    output wire D,
    output wire C,
    output wire B,
    output wire A
);

wire F;

// Boolean expression
assign F = (P & Q) | (Q & ~R) | (P & ~R);

// Map F to 7447 inputs DCBA
assign {D,C,B,A} = F ? 4'b0001 : 4'b0000;

endmodule
