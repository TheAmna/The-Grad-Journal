
`timescale 1ns / 1ps
module ALU_Top (
    input wire clk,
    input wire rst_raw,
    input wire [3:0] sw,
    output wire [15:0] led
);
wire rst_deb;
debouncer #(
    .STABLE_MAX(500_000)
) db_rst (
    .clk(clk),
    .pbin(rst_raw),
    .pbout(rst_deb)
);

wire [31:0] A = 32'h10101010;
wire [31:0] B = 32'h01010101;
wire [3:0] ALUControl = sw;
wire [31:0] ALUResult;
wire Zero;

ALU alu_inst (
    .A(A),
    .B(B),
    .ALUControl(ALUControl),
    .ALUResult(ALUResult),
    .Zero(Zero)
);

assign led[14:0] = ALUResult[14:0];
assign led[15]   = Zero;
endmodule
