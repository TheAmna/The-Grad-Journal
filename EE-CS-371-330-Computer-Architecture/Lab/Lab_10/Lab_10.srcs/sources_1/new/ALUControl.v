`timescale 1ns / 1ps


// ALUControl encoding:
// 4'b0000 AND
// 4'b0001 OR
// 4'b0010 ADD
// 4'b0110 SUB
// 4'b0100 XOR
// 4'b1000 SLL
// 4'b1001 SRL

// ALUOp decoding:
// 2'b00 ADD  
// 2'b01 SUB  
// 2'b10 R-type func3 and func7[5] bit used 
// 2'b11 ADDI use funct3 to pick op


module ALUControl (
    input  wire [1:0] ALUOp,
    input  wire [2:0] funct3,
    input  wire [6:0] funct7,
    output reg  [3:0] ALUControl
);

    always @(*) begin
        case (ALUOp)

            // load/store
            2'b00: ALUControl = 4'b0010;//ADD

            // branch
            2'b01: ALUControl = 4'b0110;//SUB

            // R-type
            2'b10: begin
                case (funct3)
                    3'b000: begin   //ADD or SUB
                        if (funct7[5])
                            ALUControl = 4'b0110;  // SUB (funct7 = 0100000)
                        else
                            ALUControl = 4'b0010;  // ADD (funct7 = 0000000)
                    end
                    3'b001: ALUControl = 4'b0100;  // SLL
                    3'b101: ALUControl = 4'b0101;  // SRL (funct7=0)
                    3'b110: ALUControl = 4'b0001;  // OR
                    3'b111: ALUControl = 4'b0000;  // AND
                    3'b100: ALUControl = 4'b0001;  // XOR
                    default: ALUControl = 4'b0010; // default: ADD
                endcase
            end

            // Immediate arithmetics
            2'b11: begin
                case (funct3)
                    3'b000: ALUControl = 4'b0010;  // ADDI ADD
                    default: ALUControl = 4'b0010; // safe default: ADD
                endcase
            end

            default: ALUControl = 4'b0010; // safe default: ADD
        endcase
    end

endmodule