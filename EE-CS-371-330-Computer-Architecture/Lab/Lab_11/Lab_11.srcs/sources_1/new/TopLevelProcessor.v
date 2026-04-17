//`timescale 1ns / 1ps

//module TopLevelProcessor (
//    input  wire  clk,
//    input  wire  rst
//);

//    // PC DATAPATH WIRES
//    wire [31:0] PC;  // current program counter
//    wire [31:0] PC_Plus4; // PC + 4 (from pcAdder)
//    wire [31:0] BranchTarget;// PC + (imm << 1) (from branchAdder)
//    wire [31:0] PC_Next;    // selected next PC (from mux_pc)
//    wire        PCSrc;   // 1 = branch taken, 0 = sequential

//    //INSTRUCTION MEMORY WIRES
 
//    wire [31:0] instruction;    // 32-bit instruction 

//    // INSTRUCTION FIELD WIRES
//    wire [6:0]  opcode;  // instruction[6:0]
//    wire [4:0]  rs1_addr; // instruction[19:15]
//    wire [4:0]  rs2_addr; // instruction[24:20]
//    wire [4:0]  rd_addr;// instruction[11:7]
//    wire [2:0]  funct3; // instruction[14:12]
//    wire [6:0]  funct7;  // instruction[31:25]

   
//    assign opcode   = instruction[6:0];
//    assign rd_addr  = instruction[11:7];
//    assign funct3   = instruction[14:12];
//    assign rs1_addr = instruction[19:15];
//    assign rs2_addr = instruction[24:20];
//    assign funct7   = instruction[31:25];

//    //CONTROL SIGNAL WIRES
//    wire        RegWrite; // 1 = write result to register file
//    wire        ALUSrc; // 1 = ALU B input is immediate
//    wire        MemRead; // 1 = read from data memory
//    wire        MemWrite; // 1 = write to data memory
//    wire        MemtoReg; // 1 = writeback from memory, 0 = from ALU
//    wire        Branch; // 1 = instruction is a branch
//    wire [1:0]  ALUOp;  // ALU operation class
//    wire [3:0]  ALUControl;// specific ALU operation code

//    // REGISTER FILE WIRES
//    wire [31:0] ReadData1;   // rs1 value from register file
//    wire [31:0] ReadData2;    // rs2 value from register file
//    wire [31:0] WriteData;    // data to write back to rd

//    //IMMEDIATE AND ALU WIRES
//    wire [31:0] imm_out;   // sign-extended immediate from immGen
//    wire [31:0] ALU_B;    // ALU second operand (from mux_alusrc)
//    wire [31:0] ALUResult;   // ALU  result
//    wire        Zero;    // ALU zero flag 

//    //DATA MEMORY WIRES
    
//    wire [31:0] MemReadData;    // data read from data memory

//  //PCSrc LOGIC
//  // Branch is taken only when Branch=1 AND ALU Zero=1

//    assign PCSrc = Branch & Zero;

   
//    // Program Counter
    
//    ProgramCounter u_pc (
//        .clk     (clk),
//        .rst     (rst),
//        .PC_Next (PC_Next),
//        .PC      (PC)
//    );

    
//    // PC + 4 Adder
//    pcAdder u_pcAdder (
//        .PC       (PC),
//        .PC_Plus4 (PC_Plus4)
//    );

//    // Immediate Generator
//    immGen u_immGen (
//        .instruction (instruction),
//        .imm_out     (imm_out)
//    );
//    //Branch Target Adder
//    branchAdder u_branchAdder (
//        .PC           (PC),
//        .imm          (imm_out),
//        .BranchTarget (BranchTarget)
//    );

//    //PC Select Mux  (mux instance 1)
//    mux2 u_mux_pc (
//        .sel  (PCSrc),
//        .in0  (PC_Plus4),
//        .in1  (BranchTarget),
//        .out  (PC_Next)
//    );

//    //Instruction Memory
    
//    InstructionMemory u_instmem (
//        .instAddress (PC),
//        .instruction (instruction)
//    );

    
//    //Main Control Unit
//    MainControl u_main_ctrl (
//        .opcode   (opcode),
//        .RegWrite (RegWrite),
//        .ALUSrc   (ALUSrc),
//        .MemRead  (MemRead),
//        .MemWrite (MemWrite),
//        .MemtoReg (MemtoReg),
//        .Branch   (Branch),
//        .ALUOp    (ALUOp)
//    );

//    // ALU Control Unit
//    ALUControl u_alu_ctrl (
//        .ALUOp      (ALUOp),
//        .funct3     (funct3),
//        .funct7     (funct7),
//        .ALUControl (ALUControl)
//    );

//    // Register File
//    RegisterFile u_regfile (
//        .clk         (clk),
//        .rst         (rst),
//        .WriteEnable (RegWrite),
//        .rs1         (rs1_addr),
//        .rs2         (rs2_addr),
//        .rd          (rd_addr),
//        .WriteData   (WriteData),
//        .ReadData1   (ReadData1),
//        .ReadData2   (ReadData2)
//    );

//    // ALU Source Mux  (mux instance 2)
    
//    mux2 u_mux_alusrc (
//        .sel  (ALUSrc),
//        .in0  (ReadData2),
//        .in1  (imm_out),
//        .out  (ALU_B)
//    );

//    //ALU
//    ALU u_alu (
//        .A         (ReadData1),
//        .B         (ALU_B),
//        .ALUControl(ALUControl),
//        .ALUResult (ALUResult),
//        .Zero      (Zero)
//    );

//    // Data Memory
    
//    DataMemory u_datamem (
//        .clk        (clk),
//        .MemWrite   (MemWrite),
//        .MemRead    (MemRead),
//        .address    (ALUResult),
//        .write_data (ReadData2),
//        .read_data  (MemReadData)
//    );

//    //Writeback Mux  (mux instance 3)
//    mux2 u_mux_wb (
//        .sel  (MemtoReg),
//        .in0  (ALUResult),
//        .in1  (MemReadData),
//        .out  (WriteData)
//    );

//endmodule

`timescale 1ns / 1ps

module TopLevelProcessor (
    input  wire        clk,
    input  wire        rst,

    // Memory interface ports (connect to addressDecoderTop in wrapper)
    output wire [31:0] mem_address,
    output wire [31:0] mem_write_data,
    output wire        mem_write_en,
    output wire        mem_read_en,
    input  wire [31:0] mem_read_data
);

    // PC DATAPATH WIRES
    wire [31:0] PC;
    wire [31:0] PC_Plus4;
    wire [31:0] BranchTarget;
    wire [31:0] PC_Next;
    wire        PCSrc;

    // INSTRUCTION MEMORY WIRES
    wire [31:0] instruction;

    // INSTRUCTION FIELD WIRES
    wire [6:0]  opcode;
    wire [4:0]  rs1_addr;
    wire [4:0]  rs2_addr;
    wire [4:0]  rd_addr;
    wire [2:0]  funct3;
    wire [6:0]  funct7;

    assign opcode   = instruction[6:0];
    assign rd_addr  = instruction[11:7];
    assign funct3   = instruction[14:12];
    assign rs1_addr = instruction[19:15];
    assign rs2_addr = instruction[24:20];
    assign funct7   = instruction[31:25];

    // CONTROL SIGNAL WIRES
    wire        RegWrite;
    wire        ALUSrc;
    wire        MemRead;
    wire        MemWrite;
    wire        MemtoReg;
    wire        Branch;
    wire [1:0]  ALUOp;
    wire [3:0]  ALUControl;

    // REGISTER FILE WIRES
    wire [31:0] ReadData1;
    wire [31:0] ReadData2;
    wire [31:0] WriteData;

    // IMMEDIATE AND ALU WIRES
    wire [31:0] imm_out;
    wire [31:0] ALU_B;
    wire [31:0] ALUResult;
    wire        Zero;

    // PCSrc LOGIC
    assign PCSrc = Branch & Zero;

    // Memory interface assignments (replaces DataMemory instantiation)
    assign mem_address    = ALUResult;
    assign mem_write_data = ReadData2;
    assign mem_write_en   = MemWrite;
    assign mem_read_en    = MemRead;

    // Program Counter
    ProgramCounter u_pc (
        .clk     (clk),
        .rst     (rst),
        .PC_Next (PC_Next),
        .PC      (PC)
    );

    // PC + 4 Adder
    pcAdder u_pcAdder (
        .PC       (PC),
        .PC_Plus4 (PC_Plus4)
    );

    // Immediate Generator
    immGen u_immGen (
        .instruction (instruction),
        .imm_out     (imm_out)
    );

    // Branch Target Adder
    branchAdder u_branchAdder (
        .PC           (PC),
        .imm          (imm_out),
        .BranchTarget (BranchTarget)
    );

    // PC Select Mux
    mux2 u_mux_pc (
        .sel  (PCSrc),
        .in0  (PC_Plus4),
        .in1  (BranchTarget),
        .out  (PC_Next)
    );

    // Instruction Memory
    InstructionMemory u_instmem (
        .instAddress (PC),
        .instruction (instruction)
    );

    // Main Control Unit
    MainControl u_main_ctrl (
        .opcode   (opcode),
        .RegWrite (RegWrite),
        .ALUSrc   (ALUSrc),
        .MemRead  (MemRead),
        .MemWrite (MemWrite),
        .MemtoReg (MemtoReg),
        .Branch   (Branch),
        .ALUOp    (ALUOp)
    );

    // ALU Control Unit
    ALUControl u_alu_ctrl (
        .ALUOp      (ALUOp),
        .funct3     (funct3),
        .funct7     (funct7),
        .ALUControl (ALUControl)
    );

    // Register File
    RegisterFile u_regfile (
        .clk         (clk),
        .rst         (rst),
        .WriteEnable (RegWrite),
        .rs1         (rs1_addr),
        .rs2         (rs2_addr),
        .rd          (rd_addr),
        .WriteData   (WriteData),
        .ReadData1   (ReadData1),
        .ReadData2   (ReadData2)
    );

    // ALU Source Mux
    mux2 u_mux_alusrc (
        .sel  (ALUSrc),
        .in0  (ReadData2),
        .in1  (imm_out),
        .out  (ALU_B)
    );

    // ALU
    ALU u_alu (
        .A          (ReadData1),
        .B          (ALU_B),
        .ALUControl (ALUControl),
        .ALUResult  (ALUResult),
        .Zero       (Zero)
    );

    // Writeback Mux
    // in1 is now mem_read_data from the external address decoder
    mux2 u_mux_wb (
        .sel  (MemtoReg),
        .in0  (ALUResult),
        .in1  (mem_read_data),
        .out  (WriteData)
    );

endmodule