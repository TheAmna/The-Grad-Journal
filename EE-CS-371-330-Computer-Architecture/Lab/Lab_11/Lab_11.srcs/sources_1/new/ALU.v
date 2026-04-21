`timescale 1ns / 1ps

module ALU (
    input  wire [31:0] A,
    input  wire [31:0] B,
    input  wire [3:0]  ALUControl,
    output reg  [31:0] ALUResult,
    output wire        Zero,
    output wire        blt
);

    // =========================================
    // Operation codes
    // =========================================
    localparam AND_OP = 4'b0000;
    localparam OR_OP  = 4'b0001;
    localparam ADD_OP = 4'b0010;
    localparam SUB_OP = 4'b0110;
    localparam XOR_OP = 4'b0100;
    localparam SLL_OP = 4'b1000;
    localparam SRL_OP = 4'b1001;
    localparam SLT_OP = 4'b0111;

    // =========================================
    // Ripple carry adder for ADD and SUB
    // SUB uses 2s complement: invert B, carry in = 1
    // =========================================
    wire [31:0] B_for_adder;
    wire [32:0] carry;
    wire [31:0] add_result;

    reg [31:0] B_temp;
    always @(*) begin
        if (ALUControl == SUB_OP)
            B_temp = ~B;
        else
            B_temp = B;
    end
    assign B_for_adder = B_temp;

    reg cin_lsb;
    always @(*) begin
        if (ALUControl == SUB_OP)
            cin_lsb = 1'b1;
        else
            cin_lsb = 1'b0;
    end
    assign carry[0] = cin_lsb;

    genvar i;
    generate
        for (i = 0; i < 32; i = i + 1) begin : ripple_adder
            FullAdder fa (
                .a   (A[i]),
                .b   (B_for_adder[i]),
                .cin (carry[i]),
                .sum (add_result[i]),
                .cout(carry[i+1])
            );
        end
    endgenerate

    // =========================================
    // Logic operations
    // =========================================
    wire [31:0] and_result = A & B;
    wire [31:0] or_result  = A | B;
    wire [31:0] xor_result = A ^ B;

    // =========================================
    // Shift operations
    // =========================================
    wire [31:0] sll_result = A << B[4:0];
    wire [31:0] srl_result = A >> B[4:0];

    // =========================================
    // SLT - signed less than
    // Returns 1 if A < B (signed), else 0
    // =========================================
    wire [31:0] slt_result = ($signed(A) < $signed(B)) ? 32'd1 : 32'd0;

    // =========================================
    // Output mux
    // =========================================
    always @(*) begin
        if      (ALUControl == AND_OP)                        ALUResult = and_result;
        else if (ALUControl == OR_OP)                         ALUResult = or_result;
        else if (ALUControl == XOR_OP)                        ALUResult = xor_result;
        else if (ALUControl == ADD_OP || ALUControl == SUB_OP) ALUResult = add_result;
        else if (ALUControl == SLL_OP)                        ALUResult = sll_result;
        else if (ALUControl == SRL_OP)                        ALUResult = srl_result;
        else if (ALUControl == SLT_OP)                        ALUResult = slt_result;
        else                                                   ALUResult = 32'b0;
    end

    // =========================================
    // Flags
    // Zero - for BEQ and BNE
    // blt  - for BLT and BGE, always computed
    //        from signed comparison of A and B
    //        independent of ALUResult
    // =========================================
    assign Zero = (ALUResult == 32'b0);
    assign blt  = ($signed(A) < $signed(B));

endmodule
