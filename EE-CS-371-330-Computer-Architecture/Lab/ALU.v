`timescale 1ns / 1ps
module ALU(
    input  wire [31:0] A,
    input  wire [31:0] B,
    input  wire [3:0]  ALUControl,
    output wire [31:0] ALUResult,
    output wire        Zero
);

    wire        ainvert;
    wire        binvert;
    wire [1:0]  operation;
    assign ainvert   = ALUControl[3];
    assign binvert   = ALUControl[2];
    assign operation = ALUControl[1:0];
    wire [32:0] carry;
    assign carry[0] = binvert;
    wire [31:0] slice_result;
    genvar i;
    generate
        for (i = 0; i < 32; i = i + 1) begin : SLICE
            ALU_1bit U_slice (
                .a         (A[i]),
                .b         (B[i]),
                .cin       (carry[i]),
                .ainvert   (ainvert),
                .binvert   (binvert),
                .operation (operation),
                .result    (slice_result[i]),
                .cout      (carry[i+1])
            );
        end
    endgenerate

    wire [31:0] sll_result;
    wire [31:0] srl_result;

    assign sll_result = A << B[4:0];
    assign srl_result = A >> B[4:0];

    reg [31:0] alu_out;

    always @(*) begin
        if (ALUControl == 4'b0100)
            alu_out = sll_result;
        else if (ALUControl == 4'b0101)
            alu_out = srl_result;
        else
            alu_out = slice_result;
    end

    assign ALUResult = alu_out;

    reg zero_flag;

    always @(*) begin
        if (ALUResult == 32'b0)
            zero_flag = 1;
        else
            zero_flag = 0;
    end

    assign Zero = zero_flag;

endmodule