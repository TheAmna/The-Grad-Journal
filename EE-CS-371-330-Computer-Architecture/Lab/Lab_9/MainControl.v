`timescale 1ns / 1ps
module MainControl (
    input  wire [6:0] opcode,
    output reg        RegWrite,
    output reg        ALUSrc,
    output reg        MemRead,
    output reg        MemWrite,
    output reg        MemtoReg,
    output reg        Branch,
    output reg [1:0]  ALUOp
);

    localparam R_TYPE  = 7'b0110011;
    localparam I_ARITH = 7'b0010011;
    localparam LOAD    = 7'b0000011;
    localparam STORE   = 7'b0100011;
    localparam BRANCH  = 7'b1100011;

    always @(*) begin
        RegWrite = 1'b0;
        ALUSrc   = 1'b0;
        MemRead  = 1'b0;
        MemWrite = 1'b0;
        MemtoReg = 1'b0;
        Branch   = 1'b0;
        ALUOp    = 2'b00;

        case (opcode)
            R_TYPE: begin
                RegWrite = 1'b1;
                ALUSrc   = 1'b0;
                MemRead  = 1'b0;
                MemWrite = 1'b0;
                MemtoReg = 1'b0;
                Branch   = 1'b0;
                ALUOp    = 2'b10;
            end
            I_ARITH: begin
                RegWrite = 1'b1;
                ALUSrc   = 1'b1;
                MemRead  = 1'b0;
                MemWrite = 1'b0;
                MemtoReg = 1'b0;
                Branch   = 1'b0;
                ALUOp    = 2'b11;
            end
            LOAD: begin
                RegWrite = 1'b1;
                ALUSrc   = 1'b1;
                MemRead  = 1'b1;
                MemWrite = 1'b0;
                MemtoReg = 1'b1;
                Branch   = 1'b0;
                ALUOp    = 2'b00;
            end
            STORE: begin
                RegWrite = 1'b0;
                ALUSrc   = 1'b1;
                MemRead  = 1'b0;
                MemWrite = 1'b1;
                MemtoReg = 1'b0;
                Branch   = 1'b0;
                ALUOp    = 2'b00;
            end
            BRANCH: begin
                RegWrite = 1'b0;
                ALUSrc   = 1'b0;
                MemRead  = 1'b0;
                MemWrite = 1'b0;
                MemtoReg = 1'b0;
                Branch   = 1'b1;
                ALUOp    = 2'b01;
            end
            default: begin
                RegWrite = 1'b0;
                ALUSrc   = 1'b0;
                MemRead  = 1'b0;
                MemWrite = 1'b0;
                MemtoReg = 1'b0;
                Branch   = 1'b0;
                ALUOp    = 2'b00;
            end
        endcase
    end

endmodule
