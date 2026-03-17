`timescale 1ns / 1ps
// ============================================================
// DataMemory.v
// 512 x 32-bit data memory for the single-cycle RISC-V processor.
//
// Write : synchronous on posedge clk, gated by MemWrite
// Read  : asynchronous (combinational), gated by MemRead
//
// Only address[8:0] (9 bits) is used internally ? 512 locations.
// The address decoder above this module has already qualified
// that address[9:8] == 2'b00 before asserting MemWrite/MemRead,
// so we simply index with the lower 9 bits.
// ============================================================
module DataMemory (
    input  wire        clk,
    input  wire        MemWrite,   // write enable (from address decoder)
    input  wire        MemRead,    // read  enable (from address decoder)
    input  wire [31:0] address,    // full address; only [8:0] used here
    input  wire [31:0] write_data,
    output reg  [31:0] read_data
);
    // 512 words of 32 bits
    reg [31:0] mem [0:511];

    // Initialise all locations to 0 for clean simulation
    integer i;
    initial begin
        for (i = 0; i < 512; i = i + 1)
            mem[i] = 32'd0;
    end

    // Synchronous write
    always @(posedge clk) begin
        if (MemWrite)
            mem[address[8:0]] <= write_data;
    end

    // Asynchronous (combinational) read - explicit sensitivity list avoids
    // the iverilog warning about @* being sensitive to all 512 array words.
    always @(MemRead or address) begin
        if (MemRead)
            read_data = mem[address[8:0]];
        else
            read_data = 32'd0;
    end

endmodule