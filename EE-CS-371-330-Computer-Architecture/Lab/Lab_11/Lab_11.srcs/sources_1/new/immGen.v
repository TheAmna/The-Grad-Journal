//`timescale 1ns / 1ps
//// ============================================================
//// immGen.v
//// Lab 11 - Task 1
////
//// Immediate Generator - extracts and sign-extends the
//// immediate value from a 32-bit RISC-V instruction.
////
//// Supports three formats as required by the manual:
////
////   I-type (loads, ADDI, JALR):
////     imm[11:0] = instr[31:20]
////     sign bit  = instr[31]
////
////   S-type (stores SW, SH, SB):
////     imm[11:5] = instr[31:25]
////     imm[4:0]  = instr[11:7]
////     sign bit  = instr[31]
////
////   B-type (branches BEQ, BNE, BLT, BGE):
////     imm[12]   = instr[31]
////     imm[10:5] = instr[30:25]
////     imm[4:1]  = instr[11:8]
////     imm[11]   = instr[7]
////     imm[0]    = 0 (always, branches are halfword aligned)
////     sign bit  = instr[31]
////
//// All outputs are sign-extended to 32 bits.
//// Opcode is used to select which format applies.
////
//// Opcode values:
////   0000011 = Load  (I-type)
////   0010011 = I-arithmetic (I-type)
////   1100111 = JALR  (I-type)
////   0100011 = Store (S-type)
////   1100011 = Branch (B-type)
//// ============================================================
//module immGen (
//    input  wire [31:0] instruction,   // full 32-bit instruction word
//    output reg  [31:0] imm_out        // sign-extended immediate
//);

//    wire [6:0] opcode = instruction[6:0];

//    // Opcode localparams for readability
//    localparam LOAD   = 7'b0000011;   // I-type
//    localparam I_ARITH= 7'b0010011;   // I-type
//    localparam JALR   = 7'b1100111;   // I-type
//    localparam STORE  = 7'b0100011;   // S-type
//    localparam BRANCH = 7'b1100011;   // B-type

//    always @(*) begin
//        case (opcode)

//            // --------------------------------------------------
//            // I-type: Load, ADDI/ANDI/ORI/XORI, JALR
//            // imm[11:0] = instr[31:20], sign-extended from bit 31
//            // --------------------------------------------------
//            LOAD, I_ARITH, JALR: begin
//                imm_out = {{20{instruction[31]}}, instruction[31:20]};
//            end

//            // --------------------------------------------------
//            // S-type: Store (SW, SH, SB)
//            // imm[11:5] = instr[31:25]
//            // imm[4:0]  = instr[11:7]
//            // Reassemble then sign-extend from bit 31
//            // --------------------------------------------------
//            STORE: begin
//                imm_out = {{20{instruction[31]}},
//                           instruction[31:25],
//                           instruction[11:7]};
//            end

//            // --------------------------------------------------
//            // B-type: Branch (BEQ, BNE, BLT, BGE, BLTU, BGEU)
//            // Bits are scrambled in the instruction word.
//            // Reassemble in correct order:
//            //   [12]   = instr[31]
//            //   [11]   = instr[7]
//            //   [10:5] = instr[30:25]
//            //   [4:1]  = instr[11:8]
//            //   [0]    = 0
//            // Sign-extend from bit 12 (bit 31 of instruction)
//            // --------------------------------------------------
//            BRANCH: begin
//                imm_out = {{19{instruction[31]}},
//                           instruction[31],
//                           instruction[7],
//                           instruction[30:25],
//                           instruction[11:8],
//                           1'b0};
//            end

//            // --------------------------------------------------
//            // Default: output zero for any unrecognised opcode
//            // --------------------------------------------------
//            default: begin
//                imm_out = 32'd0;
//            end

//        endcase
//    end

//endmodule


`timescale 1ns / 1ps

//extracts and sign-extends the immediate value 

module immGen (
    input  wire [31:0] instruction, // 32-bit instruction
    output reg  [31:0] imm_out //sign-extended immediate
);

    wire [6:0] opcode = instruction[6:0];

    localparam LOAD    = 7'b0000011; // I-type
    localparam I_ARITH = 7'b0010011; // I-type
    localparam JALR    = 7'b1100111; // I-type
    localparam STORE   = 7'b0100011; // S-type
    localparam BRANCH  = 7'b1100011; // B-type

    always @(*) begin
        case (opcode)
          
            // I-type
            // imm[11:0] from instr[31:20], sign-extended
            LOAD, I_ARITH, JALR: begin
                imm_out = {{20{instruction[31]}}, instruction[31:20]};
            end

 
            // S-type: Store 
            // imm upper = instr[31:25], imm lower = instr[11:7]
            // reassembled and sign-extended
            STORE: begin
                imm_out = {{20{instruction[31]}},
                           instruction[31:25],
                           instruction[11:7]};
            end

         
            // B-type:
            // Outputs bits[12:1] of the offset sign-extended
            // bit 0 is always zero so branchAdder shifts left 1
            // imm[12] = instr[31]   sign bit
            // imm[11] = instr[7]
            // imm[10:5] = instr[30:25]
            // imm[4:1]  = instr[11:8]
           
 //12 bits assembled, sign-extended to 32
           
            BRANCH: begin
                imm_out = {{20{instruction[31]}},
                           instruction[31],
                           instruction[7],
                           instruction[30:25],
                           instruction[11:8]};
            end

            // default: zero for unrecognised opcode
            
            default: begin
                imm_out = 32'd0;
            end

        endcase
    end

endmodule