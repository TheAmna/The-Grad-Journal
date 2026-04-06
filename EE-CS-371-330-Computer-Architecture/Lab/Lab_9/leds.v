`timescale 1ns / 1ps
module leds (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] writeData,
    input  wire        writeEnable,
    output reg  [15:0] led
);

    always @(posedge clk) begin
        if (rst)
            led <= 16'd0;
        else if (writeEnable)
            led <= writeData[15:0];
    end

endmodule
