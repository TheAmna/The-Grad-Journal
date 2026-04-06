`timescale 1ns / 1ps
// =============================================================
// ControlPath_tb.v
// Integrated testbench for the full ControlPath module.
// Applies all 15 supported instructions one by one.
// Each instruction holds for 20 ns so every signal transition
// is clearly visible on the waveform.
//
// Signal key (for waveform inspection):
//   RW  = RegWrite     AS  = ALUSrc
//   MR  = MemRead      MW  = MemWrite
//   M2R = MemtoReg     BR  = Branch
//   ALUC= ALUControl[3:0]
//
// Expected ALUControl values:
//   ADD/ADDI/LW/LH/LB/SW/SH/SB = 0010
//   SUB/BEQ                     = 0110
//   AND                         = 0000
//   OR                          = 0001
//   XOR                         = 0011
//   SLL                         = 1000
//   SRL                         = 1001
// =============================================================
module ControlPath_tb;

    reg  [6:0] opcode;
    reg  [2:0] funct3;
    reg  [6:0] funct7;

    wire        RegWrite;
    wire        ALUSrc;
    wire        MemRead;
    wire        MemWrite;
    wire        MemtoReg;
    wire        Branch;
    wire [3:0]  ALUControl;

    // -- Instantiate DUT --------------------------------------
    ControlPath uut (
        .opcode    (opcode),
        .funct3    (funct3),
        .funct7    (funct7),
        .RegWrite  (RegWrite),
        .ALUSrc    (ALUSrc),
        .MemRead   (MemRead),
        .MemWrite  (MemWrite),
        .MemtoReg  (MemtoReg),
        .Branch    (Branch),
        .ALUControl(ALUControl)
    );

    initial begin

        // ======================================================
        // R-type instructions  (opcode = 0110011)
        // RegWrite=1 ALUSrc=0 MemRead=0 MemWrite=0
        // MemtoReg=0 Branch=0
        // ======================================================

        // ADD  funct3=000 funct7=0000000  ALUControl=0010
        opcode=7'b0110011; funct3=3'b000; funct7=7'b0000000; #20;

        // SUB  funct3=000 funct7=0100000  ALUControl=0110
        opcode=7'b0110011; funct3=3'b000; funct7=7'b0100000; #20;

        // SLL  funct3=001 funct7=0000000  ALUControl=1000
        opcode=7'b0110011; funct3=3'b001; funct7=7'b0000000; #20;

        // SRL  funct3=101 funct7=0000000  ALUControl=1001
        opcode=7'b0110011; funct3=3'b101; funct7=7'b0000000; #20;

        // AND  funct3=111 funct7=0000000  ALUControl=0000
        opcode=7'b0110011; funct3=3'b111; funct7=7'b0000000; #20;

        // OR   funct3=110 funct7=0000000  ALUControl=0001
        opcode=7'b0110011; funct3=3'b110; funct7=7'b0000000; #20;

        // XOR  funct3=100 funct7=0000000  ALUControl=0011
        opcode=7'b0110011; funct3=3'b100; funct7=7'b0000000; #20;

        // ======================================================
        // I-type arithmetic  (opcode = 0010011)
        // RegWrite=1 ALUSrc=1 MemRead=0 MemWrite=0
        // MemtoReg=0 Branch=0
        // ======================================================

        // ADDI  funct3=000  ALUControl=0010
        opcode=7'b0010011; funct3=3'b000; funct7=7'b0000000; #20;

        // ======================================================
        // Load instructions  (opcode = 0000011)
        // RegWrite=1 ALUSrc=1 MemRead=1 MemWrite=0
        // MemtoReg=1 Branch=0  ALUControl=0010
        // ======================================================

        // LW   funct3=010
        opcode=7'b0000011; funct3=3'b010; funct7=7'b0000000; #20;

        // LH   funct3=001
        opcode=7'b0000011; funct3=3'b001; funct7=7'b0000000; #20;

        // LB   funct3=000
        opcode=7'b0000011; funct3=3'b000; funct7=7'b0000000; #20;

        // ======================================================
        // Store instructions  (opcode = 0100011)
        // RegWrite=0 ALUSrc=1 MemRead=0 MemWrite=1
        // MemtoReg=0 Branch=0  ALUControl=0010
        // ======================================================

        // SW   funct3=010
        opcode=7'b0100011; funct3=3'b010; funct7=7'b0000000; #20;

        // SH   funct3=001
        opcode=7'b0100011; funct3=3'b001; funct7=7'b0000000; #20;

        // SB   funct3=000
        opcode=7'b0100011; funct3=3'b000; funct7=7'b0000000; #20;

        // ======================================================
        // Branch  (opcode = 1100011)
        // RegWrite=0 ALUSrc=0 MemRead=0 MemWrite=0
        // MemtoReg=0 Branch=1  ALUControl=0110
        // ======================================================

        // BEQ  funct3=000
        opcode=7'b1100011; funct3=3'b000; funct7=7'b0000000; #20;

        $finish;
    end

endmodule
