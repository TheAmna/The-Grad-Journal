`timescale 1ns / 1ps

module RF_ALU_FSM_tb;

    reg clk;
    reg rst;

    // Wires between modules
    wire WriteEnable;
    wire [4:0] rs1, rs2, rd;
    wire [3:0] alu_ctrl;
    wire [31:0] const_data;
    wire use_const;
    wire [31:0] ReadData1, ReadData2;
    wire [31:0] ALUResult;
    wire Zero;                     // for BEQ-style check

    reg [31:0] WriteData;

    // === YOUR ORIGINAL ALU (from Lab 6) ===
    ALU alu (
        .A(ReadData1),
        .B(ReadData2),
        .ALUControl(alu_ctrl),
        .ALUResult(ALUResult),
        .Zero(Zero)
    );

    // Register File
    RegisterFile rf (
        .clk(clk),
        .rst(rst),
        .WriteEnable(WriteEnable),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .WriteData(WriteData),
        .ReadData1(ReadData1),
        .ReadData2(ReadData2)
    );

    // FSM (now does EVERYTHING the manual requires)
    RF_ALU_FSM fsm (
        .clk(clk),
        .rst(rst),
        .alu_zero(Zero),          // connected for conditional flag
        .WriteEnable(WriteEnable),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .alu_ctrl(alu_ctrl),
        .const_data(const_data),
        .use_const(use_const)
    );

    // Clock
    always #5 clk = ~clk;

    // WriteData mux (simple if)
    always @(*) begin
        if (use_const == 1)
            WriteData = const_data;
        else
            WriteData = ALUResult;
    end

    initial begin
        clk = 0;
        rst = 1;
        #40;
        rst = 0;
        #800;   // enough time for full sequence + read-after-write
    end

endmodule