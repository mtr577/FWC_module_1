// GATE 2010 CS Question 6 Implementation
// f(P,Q,R) = PQ + Q~R + P~R

module blink(
    input wire P,
    input wire Q,
    input wire R,
    output wire F
);

assign F = (P & Q) | (Q & ~R) | (P & ~R);

endmodule
