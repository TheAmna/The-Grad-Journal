`timescale 1ns / 1ps

module ProcessorFPGA (
    input  wire        clk,
    input  wire        rst_raw,     // BTNC on Basys3
    input  wire [15:0] sw,          // SW0-SW15
    output wire [15:0] led          // LD0-LD15
);

    // ----------------------------------------------------------------
    // Debounced reset  -  actual ports are pbin / pbout
    // ----------------------------------------------------------------
    wire rst_clean;

    debouncer u_debounce (
        .clk   (clk),
        .pbin  (rst_raw),
        .pbout (rst_clean)
    );

    // ----------------------------------------------------------------
    // Memory interface wires between processor and memory system
    // ----------------------------------------------------------------
    wire [31:0] mem_address;
    wire [31:0] mem_write_data;
    wire        mem_write_en;
    wire        mem_read_en;
    wire [31:0] mem_read_data;

    // ----------------------------------------------------------------
    // TopLevelProcessor
    // ----------------------------------------------------------------
    TopLevelProcessor u_processor (
        .clk            (clk),
        .rst            (rst_clean),
        .mem_address    (mem_address),
        .mem_write_data (mem_write_data),
        .mem_write_en   (mem_write_en),
        .mem_read_en    (mem_read_en),
        .mem_read_data  (mem_read_data)
    );

    // ----------------------------------------------------------------
    // Address Decoder
    //   0x000-0x1FF  -> DataMemory
    //   0x200        -> LEDs  (write)
    //   0x300        -> Switches (read)
    // ----------------------------------------------------------------
    wire        DataMemWrite;
    wire        DataMemRead;
    wire        LEDWrite;
    wire        SwitchReadEnable;

    AddressDecoder u_addr_dec (
        .readEnable       (mem_read_en),
        .writeEnable      (mem_write_en),
        .address          (mem_address),
        .DataMemWrite     (DataMemWrite),
        .DataMemRead      (DataMemRead),
        .LEDWrite         (LEDWrite),
        .SwitchReadEnable (SwitchReadEnable)
    );

    // ----------------------------------------------------------------
    // DataMemory
    // ----------------------------------------------------------------
    wire [31:0] dmem_read_data;

    DataMemory u_datamem (
        .clk        (clk),
        .MemWrite   (DataMemWrite),
        .MemRead    (DataMemRead),
        .address    (mem_address),
        .write_data (mem_write_data),
        .read_data  (dmem_read_data)
    );

    // ----------------------------------------------------------------
    // LED peripheral
    // ----------------------------------------------------------------
    wire [31:0] led_read_data;   // always 0, LEDs are write-only

    leds u_leds (
        .clk         (clk),
        .rst         (rst_clean),
        .writeData   (mem_write_data),
        .writeEnable (LEDWrite),
        .readEnable  (1'b0),
        .memAddress  (mem_address[31:2]),
        .readData    (led_read_data),
        .leds        (led)
    );

    // ----------------------------------------------------------------
    // Switches peripheral
    // ----------------------------------------------------------------
    wire [31:0] sw_read_data;

    switches u_switches (
        .clk         (clk),
        .rst         (rst_clean),
        .btns        (16'd0),
        .writeData   (32'd0),
        .writeEnable (1'b0),
        .readEnable  (SwitchReadEnable),
        .memAddress  (mem_address[31:2]),
        .switches    (sw),
        .readData    (sw_read_data)
    );

    // ----------------------------------------------------------------
    // Read data mux - return the right peripheral's data to processor
    // ----------------------------------------------------------------
    assign mem_read_data = SwitchReadEnable ? sw_read_data : dmem_read_data;

endmodule