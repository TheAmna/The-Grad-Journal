`timescale 1ns / 1ps
// =============================================================
// ALUControl_tb.v
// Testbench for ALUControl.
// Drives all rows of the ALU control truth table (Task 1).
// Verify correctness from the waveform -- no console output.
//
// ALUControl output encoding (matches ALU.v):
//   0000=AND  0001=OR  0010=ADD  0011=XOR
//   0110=SUB  1000=SLL 1001=SRL
// =============================================================
module ALUControl_tb;

    reg  [1:0] ALUOp;
    reg  [2:0] funct3;
    reg  [6:0] funct7;

    wire [3:0] ALUControl;

    // -- Instantiate DUT --------------------------------------
    ALUControl uut (
        .ALUOp     (ALUOp),
        .funct3    (funct3),
        .funct7    (funct7),
        .ALUControl(ALUControl)
    );

    initial begin

        // -- ALUOp=00: Load / Store -> always ADD (0010) ------
        ALUOp = 2'b00; funct3 = 3'b000; funct7 = 7'b0000000; #20;

        // -- ALUOp=01: Branch (BEQ) -> always SUB (0110) ------
        ALUOp = 2'b01; funct3 = 3'b000; funct7 = 7'b0000000; #20;

        // -- ALUOp=10: R-type, decode funct3 + funct7[5] ------

        // ADD  funct3=000 funct7[5]=0  -> 0010
        ALUOp = 2'b10; funct3 = 3'b000; funct7 = 7'b0000000; #20;

        // SUB  funct3=000 funct7[5]=1  -> 0110
        ALUOp = 2'b10; funct3 = 3'b000; funct7 = 7'b0100000; #20;

        // SLL  funct3=001 funct7[5]=0  -> 1000
        ALUOp = 2'b10; funct3 = 3'b001; funct7 = 7'b0000000; #20;

        // XOR  funct3=100 funct7[5]=0  -> 0011
        ALUOp = 2'b10; funct3 = 3'b100; funct7 = 7'b0000000; #20;

        // SRL  funct3=101 funct7[5]=0  -> 1001
        ALUOp = 2'b10; funct3 = 3'b101; funct7 = 7'b0000000; #20;

        // OR   funct3=110 funct7[5]=0  -> 0001
        ALUOp = 2'b10; funct3 = 3'b110; funct7 = 7'b0000000; #20;

        // AND  funct3=111 funct7[5]=0  -> 0000
        ALUOp = 2'b10; funct3 = 3'b111; funct7 = 7'b0000000; #20;

        // -- ALUOp=11: I-type arithmetic (ADDI) -> ADD (0010) -
        ALUOp = 2'b11; funct3 = 3'b000; funct7 = 7'b0000000; #20;

        $finish;
    end

endmodule
