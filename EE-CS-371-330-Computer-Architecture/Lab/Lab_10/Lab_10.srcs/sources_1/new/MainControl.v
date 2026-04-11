`timescale 1ns / 1ps



//R-type:ADD, SUB, SLL, SRL, AND, OR, XOR  (opcode = 0110011)
//I-type: ADDI (opcode = 0010011)
//Load  : LW, LH, LB  (opcode = 0000011)
//Store: SW, SH, SB  (opcode = 0100011)
//Branch: BEQ (opcode = 1100011)
// ALUOp:
//2'b10 R-type  
//2'b11 I-type arithmetic 
//2'b00 Load/Store 
//2'b01 Branch 

module MainControl (  //input - opcode output- all signals
    input  wire [6:0] opcode,
    output reg        RegWrite,
    output reg        ALUSrc,
    output reg        MemRead,
    output reg        MemWrite,
    output reg        MemtoReg,
    output reg        Branch,
    output reg [1:0]  ALUOp
);

    localparam R_TYPE  = 7'b0110011;   // ADD SUB SLL SRL AND OR XOR
    localparam I_ARITH = 7'b0010011;   // ADDI 
    localparam LOAD    = 7'b0000011;   // LW LH LB
    localparam STORE   = 7'b0100011;   // SW SH SB
    localparam BRANCH  = 7'b1100011;   // BEQ

    always @(*) begin
        //default - all signals set to 0
        RegWrite = 1'b0;
        ALUSrc   = 1'b0;
        MemRead  = 1'b0;
        MemWrite = 1'b0;
        MemtoReg = 1'b0;
        Branch   = 1'b0;
        ALUOp    = 2'b00;

        case (opcode)
            // RegWrite=1, ALUSrc=0,
            // no memory, ALUOp=10  (ALUControl decides operation)
         
            R_TYPE: begin
                RegWrite = 1'b1;
                ALUSrc   = 1'b0;
                MemRead  = 1'b0;
                MemWrite = 1'b0;
                MemtoReg = 1'b0;
                Branch   = 1'b0;
                ALUOp    = 2'b10;
            end

           
            // IADDI
            // RegWrite=1, ALUSrc=1,
            // no memory, ALUOp=11 (add)
            I_ARITH: begin
                RegWrite = 1'b1;
                ALUSrc   = 1'b1;
                MemRead  = 1'b0;
                MemWrite = 1'b0;
                MemtoReg = 1'b0;
                Branch   = 1'b0;
                ALUOp    = 2'b11;
            end

           
            // LOAD
            // RegWrite=1, ALUSrc=1,
            // MemRead=1, MemtoReg=1,
            // ALUOp=00 (add)
            LOAD: begin
                RegWrite = 1'b1;
                ALUSrc   = 1'b1;
                MemRead  = 1'b1;
                MemWrite = 1'b0;
                MemtoReg = 1'b1;
                Branch   = 1'b0;
                ALUOp    = 2'b00;
            end

           
            // STORE
            // RegWrite=0, ALUSrc=1,
            // MemWrite=1, ALUOp=00  (add)
            STORE: begin
                RegWrite = 1'b0;
                ALUSrc   = 1'b1;
                MemRead  = 1'b0;
                MemWrite = 1'b1;
                MemtoReg = 1'b0; // don't care
                Branch   = 1'b0;
                ALUOp    = 2'b00;
            end

          
            // BRANCH
            // RegWrite=0, ALUSrc=0,
            // Branch=1, ALUOp=01  (subtract)
            BRANCH: begin
                RegWrite = 1'b0;
                ALUSrc   = 1'b0;
                MemRead  = 1'b0;
                MemWrite = 1'b0;
                MemtoReg = 1'b0; // don't care
                Branch   = 1'b1;
                ALUOp    = 2'b01;
            end

            // Default: all signals off
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