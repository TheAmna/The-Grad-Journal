`timescale 1ns / 1ps
module ControlPath (
    input  wire [6:0] opcode,
    input  wire [2:0] funct3,
    input  wire [6:0] funct7,
    output wire        RegWrite,
    output wire        ALUSrc,
    output wire        MemRead,
    output wire        MemWrite,
    output wire        MemtoReg,
    output wire        Branch,
    output wire [3:0]  ALUControl
);

    wire [1:0] ALUOp;

    MainControl u_main_ctrl (
        .opcode   (opcode),
        .RegWrite (RegWrite),
        .ALUSrc   (ALUSrc),
        .MemRead  (MemRead),
        .MemWrite (MemWrite),
        .MemtoReg (MemtoReg),
        .Branch   (Branch),
        .ALUOp    (ALUOp)
    );

    ALUControl u_alu_ctrl (
        .ALUOp     (ALUOp),
        .funct3    (funct3),
        .funct7    (funct7),
        .ALUControl(ALUControl)
    );

endmodule
