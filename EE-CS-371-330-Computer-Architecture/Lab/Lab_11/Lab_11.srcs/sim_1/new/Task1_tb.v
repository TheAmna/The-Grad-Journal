`timescale 1ns / 1ps
module Task1_tb;

    reg clk;
    reg rst;

    // Single instantiation of the top level only
    TopLevelProcessor u_dut (
        .clk (clk),
        .rst (rst)
    );

    // 100 MHz clock
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Waveform dump
    initial begin
        $dumpfile("Task1_tb.vcd");
        $dumpvars(0, Task1_tb);
    end

    // Stimulus
    initial begin

        // PHASE 1 - Reset for 3 cycles
        // Waveform: PC = 0x00000000, all signals zeroed
        rst = 1'b1;
        repeat(3) @(posedge clk);

        // PHASE 2 - Run from address 0
        // Waveform: PC steps +4 each cycle
        //           instruction fetched from instruction.mem
        //           control signals decode each instruction
        //           ALUResult shows computation
        //           PCSrc=1 on taken branch
        rst = 1'b0;
        repeat(60) @(posedge clk);

        // PHASE 3 - Mid-execution reset
        // Waveform: PC snaps back to 0x00000000
        rst = 1'b1;
        repeat(3) @(posedge clk);

        // PHASE 4 - Re-run from start
        // Waveform: same pattern repeats from PC=0
        rst = 1'b0;
        repeat(30) @(posedge clk);

        $finish;
    end

endmodule
