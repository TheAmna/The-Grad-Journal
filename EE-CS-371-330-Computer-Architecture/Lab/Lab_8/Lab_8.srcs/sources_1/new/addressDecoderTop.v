`timescale 1ns / 1ps
// ============================================================
// addressDecoderTop.v
// Top-level memory system for Lab 8.
//
// Integrates:
//   - AddressDecoder   (new, this lab)
//   - DataMemory       (new, this lab)
//   - leds             (reused from Lab 5 / Lab 7)
//   - switches         (reused from Lab 5 / Lab 7)
//
// Port list matches the manual's specification exactly:
//   module addressDecoderTop(
//       input clk, rst,
//       input [31:0] address,
//       input readEnable, writeEnable,
//       input [31:0] writeData,
//       input [15:0] switches,
//       output [31:0] readData,
//       output [15:0] leds
//   );
//
// readData mux:
//   - address[9]   == 0   ?  readData from DataMemory  (0x000-0x1FF)
//   - address[9:8] == 11  ?  readData from Switch synchroniser (0x300-0x3FF)
//   - anything else       ?  32'd0
// ============================================================
module addressDecoderTop (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] address,
    input  wire        readEnable,
    input  wire        writeEnable,
    input  wire [31:0] writeData,
    input  wire [15:0] switches,   // physical switch inputs from FPGA pins
    output wire [31:0] readData,
    output wire [15:0] leds        // physical LED outputs to FPGA pins
);

    // ?? 1. Address Decoder ??????????????????????????????????
    wire DataMemWrite;
    wire DataMemRead;
    wire LEDWrite;
    wire SwitchReadEnable;

    AddressDecoder u_decoder (
        .readEnable       (readEnable),
        .writeEnable      (writeEnable),
        .address          (address),
        .DataMemWrite     (DataMemWrite),
        .DataMemRead      (DataMemRead),
        .LEDWrite         (LEDWrite),
        .SwitchReadEnable (SwitchReadEnable)
    );

    // ?? 2. Data Memory ??????????????????????????????????????
    wire [31:0] dataMem_readData;

    DataMemory u_datamem (
        .clk        (clk),
        .MemWrite   (DataMemWrite),
        .MemRead    (DataMemRead),
        .address    (address),
        .write_data (writeData),
        .read_data  (dataMem_readData)
    );

    // ?? 3. LED Interface (reused from Lab 7 / Lab 5) ????????
    // IMPORTANT - what leds.v actually does:
    //   leds.v does NOT use writeEnable or writeData at all.
    //   Its only function is a 2-stage synchroniser for the physical
    //   switch inputs: switches ? sync_stage1 ? readData[15:0].
    //   writeEnable and writeData are declared ports but the module
    //   body ignores them entirely.
    //
    // Therefore:
    //   - Switch read path: physical switches ? u_leds.readData ? readData mux
    //   - LED drive path:   handled by led_reg below (separate synchronous reg)
    wire [31:0] led_readData;   // carries synchronised switch values

    leds u_leds (
        .clk         (clk),
        .rst         (rst),
        .btns        (16'd0),
        .writeData   (writeData),    // passed in but ignored by leds.v body
        .writeEnable (LEDWrite),     // passed in but ignored by leds.v body
        .readEnable  (1'b0),
        .memAddress  (address[29:0]),
        .switches    (switches),     // physical switch input - synchronised here
        .readData    (led_readData)  // synchronised switch value output
    );

    // LED output register - drives physical LEDs.
    // Needed because leds.v has no LED output port; it only synchronises
    // the switch input. This register captures writeData[15:0] on every
    // clock where LEDWrite is asserted (i.e. address[9:8]==10, writeEnable=1).
    reg [15:0] led_reg;
    always @(posedge clk) begin
        if (rst)
            led_reg <= 16'd0;
        else if (LEDWrite)
            led_reg <= writeData[15:0];
    end
    assign leds = led_reg;

    // ?? 4. Switch Interface (reused from Lab 7 / Lab 5) ?????
    // IMPORTANT - what switches.v actually does:
    //   switches.v has no switch input port. Its body only resets the
    //   leds output on rst; it does NOT populate readData from anything.
    //   The actual switch read path runs entirely through u_leds above.
    //
    // u_switches is instantiated here to satisfy the Lab 5 reuse
    // requirement. Its readData output is left unconnected (_nc)
    // and its leds output is left open - both are unused.
    wire [31:0] switch_readData_nc;

    switches u_switches (
        .clk         (clk),
        .rst         (rst),
        .writeData   (32'd0),
        .writeEnable (1'b0),
        .readEnable  (SwitchReadEnable),
        .memAddress  (address[29:0]),
        .readData    (switch_readData_nc),  // not connected - switches.v never drives this
        .leds        ()                     // not connected - LEDs driven by led_reg above
    );

    // ?? 5. readData Mux ?????????????????????????????????????
    // Route the correct source back to the CPU depending on
    // which device was selected by the address decoder.
    //
    //  address[9]   == 0   ?  Data Memory (0x000-0x1FF)
    //  address[9:8] == 11  ?  Switch synchronised values (0x300-0x3FF)
    //  otherwise           ?  32'd0
    assign readData = (address[9] == 1'b0)        ? dataMem_readData :
                      (address[9:8] == 2'b11)     ? led_readData     :
                                                    32'd0;

endmodule