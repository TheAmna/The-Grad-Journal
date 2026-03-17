`timescale 1ns / 1ps
// ============================================================
// AddressDecoder.v
// Combinational address decoder for the memory-mapped I/O system.
//
// Memory map (10-bit local address space, actual bit patterns):
//
//   address[9:8]     Range        Device        Manual label
//   00 or 01         0 - 511      Data Memory   "00"  (address[9]=0)
//   10               512 - 767    LEDs           "01"
//   11               768 - 1023   Switches       "10"
//
// NOTE: The manual lists device numbers 00/01/10 in its table.
// These are DEVICE INDICES, not raw bit patterns.
// The actual bit arithmetic is:
//   DataMem  ? address[9]   == 1'b0  (covers 0-511, both 00 and 01 sub-ranges)
//   LEDs     ? address[9:8] == 2'b10 (covers 512-767)
//   Switches ? address[9:8] == 2'b11 (covers 768-1023)
//
// The decoder uses the incoming readEnable / writeEnable from
// the CPU and routes them to the correct peripheral enable signals.
// Only ONE device is enabled at any time.
// ============================================================
module AddressDecoder (
    input  wire        readEnable,   // CPU MemRead  signal
    input  wire        writeEnable,  // CPU MemWrite signal
    input  wire [31:0] address,      // full CPU address

    // Data Memory enables
    output wire        DataMemWrite,
    output wire        DataMemRead,

    // LED peripheral enable (write only)
    output wire        LEDWrite,

    // Switch peripheral enable (read only)
    output wire        SwitchReadEnable
);
    // Extract the 2-bit device selector from the 10-bit local address
    wire [1:0] devSel = address[9:8];

    // Data Memory: address[9] = 0  (ranges 0x000-0x1FF, i.e. devSel=00 or 01)
    assign DataMemWrite     = writeEnable & (address[9] == 1'b0);
    assign DataMemRead      = readEnable  & (address[9] == 1'b0);

    // LEDs: address[9:8] = 10  (range 0x200-0x2FF, 512-767)
    assign LEDWrite         = writeEnable & (devSel == 2'b10);

    // Switches: address[9:8] = 11  (range 0x300-0x3FF, 768-1023)
    assign SwitchReadEnable = readEnable  & (devSel == 2'b11);

endmodule