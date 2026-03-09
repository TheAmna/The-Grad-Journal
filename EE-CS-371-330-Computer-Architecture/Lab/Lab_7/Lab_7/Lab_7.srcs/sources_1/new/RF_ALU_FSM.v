`timescale 1ns / 1ps

module RF_ALU_FSM (
    input wire clk,
    input wire rst,
    input wire alu_zero,           // NEW: from ALU for BEQ-style check
    output reg WriteEnable,
    output reg [4:0] rs1,
    output reg [4:0] rs2,
    output reg [4:0] rd,
    output reg [3:0] alu_ctrl,
    output reg [31:0] const_data,
    output reg use_const
);

    reg [4:0] state;
    parameter IDLE          = 5'd0;
    parameter WRITE_REGS    = 5'd1;   // manual example state name
    parameter ADD_OP        = 5'd2;
    parameter SUB_OP        = 5'd3;
    parameter AND_OP        = 5'd4;
    parameter OR_OP         = 5'd5;
    parameter XOR_OP        = 5'd6;
    parameter SLL_OP        = 5'd7;
    parameter SRL_OP        = 5'd8;
    parameter ZERO_CHECK    = 5'd9;
    parameter FLAG_WRITE    = 5'd10;  // BEQ-style conditional write
    parameter READ_AFTER    = 5'd11;  // read-after-write test
    parameter DONE          = 5'd12;

    always @(posedge clk) begin
        if (rst) begin
            state       <= IDLE;
            WriteEnable <= 0;
            rs1         <= 5'd0;
            rs2         <= 5'd0;
            rd          <= 5'd0;
            alu_ctrl    <= 4'd0;
            const_data  <= 32'd0;
            use_const   <= 0;
        end else begin
            case (state)
                IDLE: begin
                    state <= WRITE_REGS;
                end

                // i. Write known constants
                WRITE_REGS: begin
                    rd <= 5'd1; const_data <= 32'h10101010; use_const <= 1; WriteEnable <= 1; state <= ADD_OP;
                end

                // ii. ALU operations
                ADD_OP: begin rs1 <= 5'd1; rs2 <= 5'd1; rd <= 5'd4; alu_ctrl <= 4'b0010; use_const <= 0; WriteEnable <= 1; state <= SUB_OP; end
                SUB_OP: begin rs1 <= 5'd1; rs2 <= 5'd2; rd <= 5'd5; alu_ctrl <= 4'b0110; WriteEnable <= 1; state <= AND_OP; end
                AND_OP: begin rs1 <= 5'd1; rs2 <= 5'd2; rd <= 5'd6; alu_ctrl <= 4'b0000; WriteEnable <= 1; state <= OR_OP; end
                OR_OP:  begin rs1 <= 5'd1; rs2 <= 5'd2; rd <= 5'd7; alu_ctrl <= 4'b0001; WriteEnable <= 1; state <= XOR_OP; end
                XOR_OP: begin rs1 <= 5'd1; rs2 <= 5'd2; rd <= 5'd8; alu_ctrl <= 4'b0100; WriteEnable <= 1; state <= SLL_OP; end
                SLL_OP: begin rs1 <= 5'd1; rs2 <= 5'd3; rd <= 5'd9; alu_ctrl <= 4'b1000; WriteEnable <= 1; state <= SRL_OP; end
                SRL_OP: begin rs1 <= 5'd1; rs2 <= 5'd3; rd <= 5'd10; alu_ctrl <= 4'b1001; WriteEnable <= 1; state <= ZERO_CHECK; end

                // iii. BEQ-style check using Zero + conditional flag write
                ZERO_CHECK: begin
                    rs1 <= 5'd1; rs2 <= 5'd1; rd <= 5'd11; alu_ctrl <= 4'b0110; WriteEnable <= 1;
                    state <= FLAG_WRITE;
                end
                FLAG_WRITE: begin
                    rd <= 5'd12;                  // flag register
                    if (alu_zero) begin
                        const_data <= 32'h00000001; // true
                    end else begin
                        const_data <= 32'h00000000; // false
                    end
                    use_const <= 1;
                    WriteEnable <= 1;
                    state <= READ_AFTER;
                end

                // iv. Read-after-write timing test
                READ_AFTER: begin
                    rs1 <= 5'd12; rs2 <= 5'd10;   // read flag + last result
                    WriteEnable <= 0;
                    state <= DONE;
                end

                DONE: begin
                    WriteEnable <= 0;
                end

                default: state <= IDLE;
            endcase
        end
    end
endmodule