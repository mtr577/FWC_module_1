module sevseg(
    input wire P,
    input wire Q,
    input wire R,
    output wire a,
    output wire b,
    output wire c,
    output wire d,
    output wire e,
    output wire f,
    output wire g
);

wire F;

// Boolean expression
assign F = (P & Q) | (Q & ~R) | (P & ~R);

// Function to display 0 or 1 on 7-segment
function automatic [6:0] seg7;
    input F_val;
    begin
        if(F_val)
            seg7 = 7'b1001111; // displays 1
        else
            seg7 = 7'b0000001; // displays 0
    end
endfunction

assign {a,b,c,d,e,f,g} = seg7(F);

endmodule
