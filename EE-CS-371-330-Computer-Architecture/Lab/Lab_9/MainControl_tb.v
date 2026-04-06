`timescale 1ns / 1ps
// =============================================================
// MainControl_tb.v
// Testbench for MainControl.
// Drives all five supported opcodes in sequence.
// Verify correctness from the waveform -- no console output.
// =============================================================
module MainControl_tb;

    reg  [6:0] opcode;

    wire       RegWrite;
    wire       ALUSrc;
    wire       MemRead;
    wire       MemWrite;
    wire       MemtoReg;
    wire       Branch;
    wire [1:0] ALUOp;

    // -- Instantiate DUT --------------------------------------
    MainControl uut (
        .opcode   (opcode),
        .RegWrite (RegWrite),
        .ALUSrc   (ALUSrc),
        .MemRead  (MemRead),
        .MemWrite (MemWrite),
        .MemtoReg (MemtoReg),
        .Branch   (Branch),
        .ALUOp    (ALUOp)
    );

    initial begin

        // R-type: ADD, SUB, SLL, SRL, AND, OR, XOR
        // Expected: RegWrite=1 ALUSrc=0 MemRead=0 MemWrite=0
        //           MemtoReg=0 Branch=0 ALUOp=10
        opcode = 7'b0110011; #20;

        // I-type arithmetic: ADDI
        // Expected: RegWrite=1 ALUSrc=1 MemRead=0 MemWrite=0
        //           MemtoReg=0 Branch=0 ALUOp=11
        opcode = 7'b0010011; #20;

        // Load: LW, LH, LB
        // Expected: RegWrite=1 ALUSrc=1 MemRead=1 MemWrite=0
        //           MemtoReg=1 Branch=0 ALUOp=00
        opcode = 7'b0000011; #20;

        // Store: SW, SH, SB
        // Expected: RegWrite=0 ALUSrc=1 MemRead=0 MemWrite=1
        //           MemtoReg=0 Branch=0 ALUOp=00
        opcode = 7'b0100011; #20;

        // Branch: BEQ
        // Expected: RegWrite=0 ALUSrc=0 MemRead=0 MemWrite=0
        //           MemtoReg=0 Branch=1 ALUOp=01
        opcode = 7'b1100011; #20;

        $finish;
    end

endmodule
