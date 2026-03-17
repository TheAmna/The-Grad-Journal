`timescale 1ns / 1ps
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
endmodule