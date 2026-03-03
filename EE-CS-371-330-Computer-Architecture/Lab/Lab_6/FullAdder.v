`timescale 1ns / 1ps
module FullAdder (
    input a,
    input b,
    input cin,
    output reg sum,
    output reg cout
);
always @(*) begin
    sum = a ^ b ^ cin;
    cout = (a & b) | (a & cin) | (b & cin);
end
endmodule

