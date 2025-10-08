module fsm(
    output reg led_f,     // Output F to LED
    output reg d,         // BCD output to 7447
    output reg c,
    output reg b,
    output reg a
);

wire clk;
qlal4s3b_cell_macro u_qlal4s3b_cell_macro (
    .Sys_Clk0(clk)
);

reg [26:0] delay;
reg [2:0] minterm; // 3-bit minterm number, 0-7

wire P, Q, R;
assign P = minterm[2];
assign Q = minterm[1];
assign R = minterm[0];

always @(posedge clk) begin
    delay <= delay + 1;
    if (delay > 27_000_000) begin
        delay <= 0;
        if (minterm == 3'b111)
            minterm <= 3'b000;
        else
            minterm <= minterm + 1;
    end
end

// Evaluate F = PQ + Q R' + P R'
always @(*) begin
    led_f = (P & Q) | (Q & ~R) | (P & ~R);
end

always @(*) begin
    case(minterm)
        3'b000: {d,c,b,a} = 4'b0000; // m0
        3'b001: {d,c,b,a} = 4'b0001; // m1
        3'b010: {d,c,b,a} = 4'b0010; // m2
        3'b011: {d,c,b,a} = 4'b0011; // m3
        3'b100: {d,c,b,a} = 4'b0100; // m4
        3'b101: {d,c,b,a} = 4'b0101; // m5
        3'b110: {d,c,b,a} = 4'b0110; // m6
        3'b111: {d,c,b,a} = 4'b0111; // m7
        default: {d,c,b,a} = 4'b0000;
    endcase
end

endmodule
