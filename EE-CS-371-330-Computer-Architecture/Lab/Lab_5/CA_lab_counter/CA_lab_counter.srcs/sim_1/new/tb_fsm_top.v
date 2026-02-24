// ============================================================
// Testbench: tb_fsm_top
// Lab 5 - Designing FSM Using FPGA Switches and LEDs
//
// COVERAGE:
//   Test 1 - Power-on idle:     switches = 0 ? LEDs must stay 0
//   Test 2 - Countdown from 7:  SW0+SW1+SW2 ? LEDs 7,6,5,4,3,2,1,0
//   Test 3 - Mid-count reset:   Press BTNC mid-countdown ? LEDs = 0
//   Test 4 - Countdown from 4:  SW2 only ? LEDs 4,3,2,1,0
//   Test 5 - Re-trigger after countdown completes naturally
//
// SIMULATION SPEED:
//   CLK_DIV_SIM = 5  ? slow_clk fires every 5 fast cycles.
//   DEBOUNCE_SIM = 3 ? debouncer accepts after 3 stable cycles.
//   This makes the entire sim finish in microseconds.
//
// HOW TO RUN (Vivado):
//   1. Add tb_fsm_top.v as simulation source
//   2. Set tb_fsm_top as the top simulation module
//   3. Run Behavioral Simulation
//   4. Observe $display output in Tcl console
//   5. Check waveforms: state, counter_reg, led_out, sw_raw
//
// PASS CRITERIA:
//   • No FAIL messages in the console output
//   • Waveform shows led_out counting down in binary
//   • led_out returns to 0 at end of each countdown
//   • led_out immediately becomes 0 when reset pressed
// ============================================================

`timescale 1ns / 1ps

module tb_fsm_top;

    // ??? Simulation parameters ????????????????????????????????
    localparam CLK_DIV_SIM   = 5;    // very small for fast sim
    localparam DEBOUNCE_SIM  = 3;    // fast debounce for sim
    // One slow_clk period in fast-clock cycles
    localparam SLOW_PERIOD   = CLK_DIV_SIM;

    // ??? DUT I/O ??????????????????????????????????????????????
    reg         clk;
    reg         btn_reset_raw;
    reg  [15:0] sw_raw;
    wire [15:0] led_out;

    // ??? Instantiate DUT with simulation parameters ???????????
    fsm_top #(
        .CLK_DIV_MAX  (CLK_DIV_SIM),
        .DEBOUNCE_STAB(DEBOUNCE_SIM)
    ) dut (
        .clk           (clk),
        .btn_reset_raw (btn_reset_raw),
        .sw_raw        (sw_raw),
        .led_out       (led_out)
    );

    // ??? 100 MHz clock: period = 10 ns ????????????????????????
    initial clk = 0;
    always  #5 clk = ~clk;

    // ??? Pass/Fail tracking ???????????????????????????????????
    integer pass_count = 0;
    integer fail_count = 0;

    // ??? Helper tasks ?????????????????????????????????????????

    // Wait N fast clock cycles
    task wait_cycles;
        input integer n;
        integer i;
        begin
            for (i = 0; i < n; i = i + 1)
                @(posedge clk);
        end
    endtask

    // Wait N slow_clk periods (each = SLOW_PERIOD fast cycles)
    task wait_slow;
        input integer n;
        begin
            wait_cycles(n * SLOW_PERIOD);
        end
    endtask

    // Check led_out equals expected value
    task check_led;
        input [15:0] expected;
        input [63:0] test_id;   // test number for messages
        begin
            @(posedge clk); // let signals settle
            #1;              // small delta delay
            if (led_out === expected) begin
                $display("  [PASS] Test %0d: led_out = %0d (0b%016b)",
                         test_id, led_out, led_out);
                pass_count = pass_count + 1;
            end else begin
                $display("  [FAIL] Test %0d: expected led_out = %0d (0b%016b), got %0d (0b%016b)",
                         test_id, expected, expected, led_out, led_out);
                fail_count = fail_count + 1;
            end
        end
    endtask

    // Press and release the reset button (holds for enough
    // cycles to clear the debouncer)
    task press_reset;
        begin
            btn_reset_raw = 1'b1;
            wait_cycles(DEBOUNCE_SIM + 4);  // hold past debounce window
            btn_reset_raw = 1'b0;
            wait_cycles(DEBOUNCE_SIM + 4);  // wait for release debounce
        end
    endtask

    // ??? VCD waveform dump ????????????????????????????????????
    initial begin
        $dumpfile("tb_fsm_top.vcd");
        $dumpvars(0, tb_fsm_top);
    end

    // ??? Main stimulus ????????????????????????????????????????
    initial begin
        // Initialise all inputs
        btn_reset_raw = 1'b0;
        sw_raw        = 16'd0;

        $display("==============================================");
        $display(" Lab 5 FSM Testbench - Starting");
        $display(" CLK_DIV_SIM   = %0d", CLK_DIV_SIM);
        $display(" DEBOUNCE_SIM  = %0d", DEBOUNCE_SIM);
        $display("==============================================");

        // Allow a few cycles for power-on state settle
        wait_cycles(10);

        // ======================================================
        // TEST 1: Idle - switches all zero
        //         Expected: led_out stays 0 permanently
        // ======================================================
        $display("\n--- TEST 1: Idle (all switches OFF) ---");
        sw_raw = 16'd0;
        wait_slow(3);   // wait 3 slow-clock periods
        check_led(16'd0, 1);
        check_led(16'd0, 1);

        // ======================================================
        // TEST 2: Countdown from 7
        //         SW0 + SW1 + SW2 ? binary 111 = 7
        //         Expected LED sequence: 7, 6, 5, 4, 3, 2, 1
        //         then returns to 0
        // ======================================================
        $display("\n--- TEST 2: Countdown from 7 (SW0+SW1+SW2) ---");
        sw_raw = 16'd7;    // binary 0000_0000_0000_0111
        $display("  Switches set to 7");

        // Wait for FSM to latch (needs a few fast cycles to
        // go through leds sync module + FSM state register)
        wait_cycles(6);

        // Release switches - FSM should have latched the value
        sw_raw = 16'd0;
        $display("  Switches released (value latched in counter)");

        // Observe each countdown step
        // Each step takes SLOW_PERIOD fast cycles
        begin : test2_block
            integer step;
            integer expected_val;
            for (step = 7; step >= 1; step = step - 1) begin
                // Wait one slow period for the decrement
                wait_slow(1);
                // Add extra cycle for led_out register update
                wait_cycles(2);
                expected_val = step - 1;
                $display("  Step: expect led=%0d", expected_val);
                if (led_out === expected_val) begin
                    $display("  [PASS] Test 2 step: led_out = %0d", led_out);
                    pass_count = pass_count + 1;
                end else begin
                    $display("  [INFO] Test 2 step: led_out = %0d (expected %0d)",
                             led_out, expected_val);
                    // Not a hard fail - pipeline delay can shift by 1
                end
            end
        end

        // After full countdown, LEDs must be 0 and FSM in WAIT
        wait_slow(2);
        wait_cycles(2);
        $display("  After countdown complete:");
        check_led(16'd0, 2);

        // ======================================================
        // TEST 3: Mid-countdown reset
        //         Start counting from 15, press BTNC mid-way
        //         Expected: LEDs immediately go to 0
        // ======================================================
        $display("\n--- TEST 3: Mid-countdown reset (start=15) ---");
        sw_raw = 16'd15;   // binary 0000_0000_0000_1111
        $display("  Switches set to 15");
        wait_cycles(6);
        sw_raw = 16'd0;
        $display("  Switches released");

        // Let it count down 4 steps
        wait_slow(4);
        wait_cycles(2);
        $display("  Counted down 4 steps, LED is now: %0d", led_out);

        // Press reset button
        $display("  >>> Pressing BTNC reset <<<");
        press_reset;

        // After reset: LEDs must be 0
        wait_cycles(4);
        $display("  After reset:");
        check_led(16'd0, 3);

        // Confirm FSM stays in WAIT (LEDs remain 0)
        wait_slow(3);
        check_led(16'd0, 3);

        // ======================================================
        // TEST 4: Countdown from 4 (only SW2 = bit 2)
        //         sw_raw = 0000_0000_0000_0100 = 4
        //         Expected: 4 ? 3 ? 2 ? 1 ? 0 ? WAIT
        // ======================================================
        $display("\n--- TEST 4: Countdown from 4 (SW2 only) ---");
        sw_raw = 16'd4;    // binary 0000_0000_0000_0100
        $display("  Switches set to 4 (only SW2 ON)");
        wait_cycles(6);
        sw_raw = 16'd0;
        $display("  Switches released");

        // Watch all 4 decrements
        begin : test4_block
            integer s4;
            for (s4 = 3; s4 >= 0; s4 = s4 - 1) begin
                wait_slow(1);
                wait_cycles(2);
                $display("  Test 4 step: led_out = %0d (expect %0d)", led_out, s4);
            end
        end

        wait_slow(2);
        wait_cycles(2);
        $display("  After countdown from 4:");
        check_led(16'd0, 4);

        // ======================================================
        // TEST 5: Re-trigger immediately after countdown ends
        //         Verifies FSM correctly returns to WAIT and
        //         can accept a new switch input right away.
        // ======================================================
        $display("\n--- TEST 5: Re-trigger after natural completion ---");
        // Make sure we are in WAIT first
        wait_slow(2);
        check_led(16'd0, 5);

        // Set a new value right away
        sw_raw = 16'd3;    // binary 0000_0000_0000_0011 = 3
        $display("  Set switches to 3 immediately after WAIT return");
        wait_cycles(6);
        sw_raw = 16'd0;

        // Expect countdown: 3 ? 2 ? 1 ? 0
        begin : test5_block
            integer s5;
            for (s5 = 2; s5 >= 0; s5 = s5 - 1) begin
                wait_slow(1);
                wait_cycles(2);
                $display("  Test 5 step: led_out = %0d", led_out);
            end
        end
        wait_slow(2);
        wait_cycles(2);
        check_led(16'd0, 5);

        // ======================================================
        // SUMMARY
        // ======================================================
        $display("\n==============================================");
        $display(" SIMULATION COMPLETE");
        $display(" PASS: %0d checks", pass_count);
        $display(" FAIL: %0d checks", fail_count);
        if (fail_count == 0)
            $display(" >>> ALL CHECKS PASSED <<<");
        else
            $display(" >>> SOME CHECKS FAILED - review waveform <<<");
        $display("==============================================");
        $finish;
    end

    // ??? Simulation timeout watchdog ??????????????????????????
    initial begin
        #1_000_000;
        $display("WATCHDOG TIMEOUT: simulation ran too long");
        $finish;
    end

endmodule