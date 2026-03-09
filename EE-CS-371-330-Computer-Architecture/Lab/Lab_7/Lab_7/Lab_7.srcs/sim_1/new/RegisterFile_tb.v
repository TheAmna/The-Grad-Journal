`timescale 1ns / 1ps

module RegisterFile_tb;

    reg        clk;
    reg        rst;
    reg        WriteEnable;
    reg [4:0]  rs1;
    reg [4:0]  rs2;
    reg [4:0]  rd;
    reg [31:0] WriteData;

    wire [31:0] ReadData1;
    wire [31:0] ReadData2;

    RegisterFile dut (
        .clk          (clk),
        .rst          (rst),
        .WriteEnable  (WriteEnable),
        .rs1          (rs1),
        .rs2          (rs2),
        .rd           (rd),
        .WriteData    (WriteData),
        .ReadData1    (ReadData1),
        .ReadData2    (ReadData2)
    );
    always #5 clk = ~clk;
    initial begin
        clk         = 0;
        rst         = 1;
        WriteEnable = 0;
        rs1         = 5'd0;
        rs2         = 5'd0;
        rd          = 5'd0;
        WriteData   = 32'd0;
        #40;                  // reset active
        rst = 0;              // release reset
        #10;
        WriteEnable = 1;
        rd          = 5'd5;
        WriteData   = 32'hDEADBEEF;
        #10;                  // one full clock cycle
        WriteEnable = 0;
        rs1         = 5'd5;   // read it back
        #10;                  // you will see ReadData1 = DEADBEEF

        // ii. Attempt to write to x0 (must stay zero)
        WriteEnable = 1;
        rd          = 5'd0;
        WriteData   = 32'h12345678;   // garbage
        #10;
        WriteEnable = 0;
        rs1         = 5'd0;           // read x0
        #10;                
        WriteEnable = 1;
        rd          = 5'd10;
        WriteData   = 32'hAAAAAAAA;
        #10;
        WriteEnable = 1;
        rd          = 5'd20;
        WriteData   = 32'hBBBBBBBB;
        #10;
        WriteEnable = 0;
        rs1         = 5'd10;
        rs2         = 5'd20;
        #10;                 
        WriteEnable = 1;
        rd          = 5'd5;
        WriteData   = 32'hFFFFFFF;   // new value
        #10;
        WriteEnable = 0;
        rs1         = 5'd5;
        #10;                  
        rst = 1;
        #20;
        rst = 0;
        rs1 = 5'd5;           // should now show 5 again
        rs2 = 5'd10;          // should show 10 again
        #30;
    end
endmodule