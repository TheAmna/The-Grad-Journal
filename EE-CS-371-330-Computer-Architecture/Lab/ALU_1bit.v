`timescale 1ns / 1ps
module ALU_1bit (
    input  wire       a,
    input  wire       b,
    input  wire       cin,
    input  wire       ainvert,
    input  wire       binvert,
    input  wire [1:0] operation,
    output reg        result,
    output wire       cout
);

    reg a_in;
    reg b_in;
    always @(*) begin
        if (ainvert == 1)
            a_in = ~a;
        else
            a_in = a;
    end
    always @(*) begin
        if (binvert == 1)
            b_in = ~b;
        else
            b_in = b;
    end

    wire and_result = a_in & b_in;
    wire or_result  = a_in | b_in;
    wire xor_result = a_in ^ b_in;

    wire sum;
    FullAdder FA (
        .a    (a_in),
        .b    (b_in),
        .cin  (cin),
        .sum  (sum),
        .cout (cout)
    );

    always @(*) begin
        if (operation == 2'b00)
            result = and_result;
        else if (operation == 2'b01)
            result = or_result;
        else if (operation == 2'b10)
            result = sum;
        else if (operation == 2'b11)
            result = xor_result;
        else
            result = 1'b0;
    end

endmodule