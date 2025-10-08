
module kmap(
    input wire P,
    input wire Q,
    input wire R,
    output wire F
);

assign F = (~P & Q & ~R) | (P & ~Q & ~R) | (P & Q & ~R) | (P & Q & R);

endmodule
