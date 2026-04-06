`timescale 1ns / 1ps
module switches (
    input  wire        clk,
    input  wire        rst,
    input  wire        readEnable,
    input  wire [15:0] switch,
    output reg  [31:0] readData
);

    reg [15:0] sync_stage1;
    reg [15:0] sync_stage2;

    always @(posedge clk) begin
        if (rst) begin
            sync_stage1 <= 16'd0;
            sync_stage2 <= 16'd0;
        end else begin
            sync_stage1 <= switch;
            sync_stage2 <= sync_stage1;
        end
    end

    always @(posedge clk) begin
        if (rst)
            readData <= 32'd0;
        else if (readEnable)
            readData <= {16'd0, sync_stage2};
        else
            readData <= 32'd0;
    end

endmodule
