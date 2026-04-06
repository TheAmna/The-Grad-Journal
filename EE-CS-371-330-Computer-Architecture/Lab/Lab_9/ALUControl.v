`timescale 1ns / 1ps
module ALUControl (
    input  wire [1:0] ALUOp,
    input  wire [2:0] funct3,
    input  wire [6:0] funct7,
    output reg  [3:0] ALUControl
);

    wire funct7_b5 = funct7[5];

    always @(*) begin
        ALUControl = 4'b0010;

        case (ALUOp)
            2'b00: ALUControl = 4'b0010;
            2'b01: ALUControl = 4'b0110;
            2'b10: begin
                case (funct3)
                    3'b000: begin
                        if (funct7_b5 == 1'b1)
                            ALUControl = 4'b0110;
                        else
                            ALUControl = 4'b0010;
                    end
                    3'b001: ALUControl = 4'b1000;
                    3'b100: ALUControl = 4'b0011;
                    3'b101: ALUControl = 4'b1001;
                    3'b110: ALUControl = 4'b0001;
                    3'b111: ALUControl = 4'b0000;
                    default: ALUControl = 4'b0010;
                endcase
            end
            2'b11: begin
                case (funct3)
                    3'b000: ALUControl = 4'b0010;
                    default: ALUControl = 4'b0010;
                endcase
            end
            default: ALUControl = 4'b0010;
        endcase
    end

endmodule
