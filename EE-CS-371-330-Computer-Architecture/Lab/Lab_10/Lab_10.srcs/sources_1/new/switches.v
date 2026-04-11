/*`timescale 1ns / 1ps
module switches (
    input              clk,
    input              rst,
    input  [31:0]      writeData,
    input              writeEnable,
    input              readEnable,
    input  [29:0]      memAddress,
    output reg [31:0]  readData,
    output reg [15:0]  leds
);
    initial readData = 32'd0;
    always @(posedge clk) begin
        if (rst) begin
            leds <= 16'd0;
        end
    end
endmodule*/

`timescale 1ns / 1ps

// switches module
// Reads the physical FPGA switches.
// Synchronises raw switch inputs through a register stage to avoid
// metastability, then presents the stable value on readData[15:0].
// writeData and writeEnable are kept for bus compatibility but unused.

module switches (
    input              clk,
    input              rst,
    input  [15:0]      btns,        // unused - kept for bus compatibility
    input  [31:0]      writeData,   // unused - switches are read-only
    input              writeEnable, // unused
    input              readEnable,  // unused - always reading
    input  [29:0]      memAddress,  // unused - kept for bus compatibility
    input  [15:0]      switches,    // raw physical switch inputs from FPGA pins
    output reg [31:0]  readData     // synchronised switch value on [15:0]
);

    reg [15:0] sync_stage1; // first flip-flop to remove metastability

    always @(posedge clk) begin
        if (rst) begin
            sync_stage1    <= 16'd0;
            readData       <= 32'd0;
        end else begin
            sync_stage1      <= switches;      // latch raw input
            readData[15:0]   <= sync_stage1;  // one cycle later: stable output
            readData[31:16]  <= 16'd0;        // upper half always zero
        end
    end

endmodule