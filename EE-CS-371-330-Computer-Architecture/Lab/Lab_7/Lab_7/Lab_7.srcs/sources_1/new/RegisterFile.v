`timescale 1ns / 1ps
module RegisterFile (
    input  wire        clk,
    input  wire        rst,
    input  wire        WriteEnable,
    input  wire [4:0]  rs1,
    input  wire [4:0]  rs2,
    input  wire [4:0]  rd,
    input  wire [31:0] WriteData,
    output reg  [31:0] ReadData1,   
    output reg  [31:0] ReadData2   
);
    reg [31:0] regs [0:31];
    initial begin
        regs[0]  = 32'd0;
        regs[1]  = 32'd1;
        regs[2]  = 32'd2;
        regs[3]  = 32'd3;
        regs[4]  = 32'd4;
        regs[5]  = 32'd5;
        regs[6]  = 32'd6;
        regs[7]  = 32'd7;
        regs[8]  = 32'd8;
        regs[9]  = 32'd9;
        regs[10] = 32'd10;
        regs[11] = 32'd11;
        regs[12] = 32'd12;
        regs[13] = 32'd13;
        regs[14] = 32'd14;
        regs[15] = 32'd15;
        regs[16] = 32'd16;
        regs[17] = 32'd17;
        regs[18] = 32'd18;
        regs[19] = 32'd19;
        regs[20] = 32'd20;
        regs[21] = 32'd21;
        regs[22] = 32'd22;
        regs[23] = 32'd23;
        regs[24] = 32'd24;
        regs[25] = 32'd25;
        regs[26] = 32'd26;
        regs[27] = 32'd27;
        regs[28] = 32'd28;
        regs[29] = 32'd29;
        regs[30] = 32'd30;
        regs[31] = 32'd31;
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            regs[0]  <= 32'd0;
            regs[1]  <= 32'd1;
            regs[2]  <= 32'd2;
            regs[3]  <= 32'd3;
            regs[4]  <= 32'd4;
            regs[5]  <= 32'd5;
            regs[6]  <= 32'd6;
            regs[7]  <= 32'd7;
            regs[8]  <= 32'd8;
            regs[9]  <= 32'd9;
            regs[10] <= 32'd10;
            regs[11] <= 32'd11;
            regs[12] <= 32'd12;
            regs[13] <= 32'd13;
            regs[14] <= 32'd14;
            regs[15] <= 32'd15;
            regs[16] <= 32'd16;
            regs[17] <= 32'd17;
            regs[18] <= 32'd18;
            regs[19] <= 32'd19;
            regs[20] <= 32'd20;
            regs[21] <= 32'd21;
            regs[22] <= 32'd22;
            regs[23] <= 32'd23;
            regs[24] <= 32'd24;
            regs[25] <= 32'd25;
            regs[26] <= 32'd26;
            regs[27] <= 32'd27;
            regs[28] <= 32'd28;
            regs[29] <= 32'd29;
            regs[30] <= 32'd30;
            regs[31] <= 32'd31;
        end
        else if (WriteEnable && (rd != 5'b00000)) begin
            regs[rd] <= WriteData;
        end
    end

    always @(*) begin
        if (rs1 == 5'b00000) begin
            ReadData1 = 32'b0;          
        end else begin
            ReadData1 = regs[rs1];
        end
        if (rs2 == 5'b00000) begin
            ReadData2 = 32'b0;           
        end else begin
            ReadData2 = regs[rs2];
        end
    end

endmodule