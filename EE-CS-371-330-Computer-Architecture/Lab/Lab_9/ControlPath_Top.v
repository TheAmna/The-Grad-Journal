`timescale 1ns / 1ps
module ControlPath_Top #(
    parameter DEBOUNCE_STAB = 500_000
)(
    input  wire        clk,
    input  wire        rst_raw,
    input  wire [15:0] sw_raw,
    output wire [15:0] led_out
);

    wire rst;
    debouncer #(.STABLE_MAX(DEBOUNCE_STAB)) u_debouncer (
        .clk   (clk),
        .pbin  (rst_raw),
        .pbout (rst)
    );

    wire        sw_readEnable;
    wire [31:0] sw_readData;

    switches u_switches (
        .clk        (clk),
        .rst        (rst),
        .readEnable (sw_readEnable),
        .switch     (sw_raw),
        .readData   (sw_readData)
    );
    wire        led_writeEnable;
    wire [31:0] led_writeData;

    leds u_leds (
        .clk         (clk),
        .rst         (rst),
        .writeData   (led_writeData),
        .writeEnable (led_writeEnable),
        .led         (led_out)
    );
    reg [6:0] opcode_lat;
    reg [2:0] funct3_lat;
    reg [6:0] funct7_lat;

    wire       RegWrite, ALUSrc, MemRead, MemWrite, MemtoReg, Branch;
    wire [3:0] ALUControl;

    ControlPath u_ctrl (
        .opcode    (opcode_lat),
        .funct3    (funct3_lat),
        .funct7    (funct7_lat),
        .RegWrite  (RegWrite),
        .ALUSrc    (ALUSrc),
        .MemRead   (MemRead),
        .MemWrite  (MemWrite),
        .MemtoReg  (MemtoReg),
        .Branch    (Branch),
        .ALUControl(ALUControl)
    );
    localparam [1:0] IDLE = 2'd0, SAMPLE = 2'd1, DISPLAY = 2'd2;

    reg [1:0]  state;
    reg        fsm_sw_re;
    reg        fsm_led_we;
    reg [31:0] fsm_led_data;

    assign sw_readEnable   = fsm_sw_re;
    assign led_writeEnable = fsm_led_we;
    assign led_writeData   = fsm_led_data;

    always @(posedge clk) begin
        if (rst) begin
            state        <= IDLE;
            fsm_sw_re    <= 1'b0;
            fsm_led_we   <= 1'b1;
            fsm_led_data <= 32'd0;
            opcode_lat   <= 7'd0;
            funct3_lat   <= 3'd0;
            funct7_lat   <= 7'd0;
        end else begin
            case (state)

                IDLE: begin
                    fsm_sw_re    <= 1'b0;
                    fsm_led_we   <= 1'b1;
                    fsm_led_data <= 32'd0;
                    state        <= SAMPLE;
                end

                SAMPLE: begin
                    fsm_sw_re  <= 1'b1;     // tell switches to present readData
                    fsm_led_we <= 1'b0;     // hold LEDs
                    state      <= DISPLAY;
                end

                DISPLAY: begin
                    fsm_sw_re <= 1'b0;

                    // Decode switch word into instruction fields
                    // sw[6:0]  -> opcode, sw[9:7] -> funct3, sw[10] -> funct7[5]
                    opcode_lat <= sw_readData[6:0];
                    funct3_lat <= sw_readData[9:7];
                    funct7_lat <= {1'b0, sw_readData[10], 5'b00000};

                    // Pack control signals and write to LED peripheral
                    fsm_led_data <= {22'd0,
                                     ALUControl,  // led[9:6]
                                     Branch,      // led[5]
                                     MemtoReg,    // led[4]
                                     MemWrite,    // led[3]
                                     MemRead,     // led[2]
                                     ALUSrc,      // led[1]
                                     RegWrite};   // led[0]
                    fsm_led_we   <= 1'b1;

                    state <= SAMPLE;
                end

                default: state <= IDLE;

            endcase
        end
    end

endmodule
