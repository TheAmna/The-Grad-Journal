## Lab 9 Constraints - Basys3 Board
## RISC-V Control Path FPGA Verification

## Clock
set_property PACKAGE_PIN W5       [get_ports clk]
set_property IOSTANDARD  LVCMOS33 [get_ports clk]
create_clock -add -name sys_clk_pin -period 10.00 -waveform {0 5} [get_ports clk]

## Reset (BTNC)
set_property PACKAGE_PIN U18      [get_ports btn_reset_raw]
set_property IOSTANDARD  LVCMOS33 [get_ports btn_reset_raw]

## Switches (sw_raw[0..15])
## sw[6:0]  = opcode  (7 bits)
## sw[9:7]  = funct3  (3 bits)
## sw[14:10]= unused
## sw[15]   = funct7[5] (ADD/SUB select)
set_property PACKAGE_PIN V17  [get_ports {sw_raw[0]}]
set_property PACKAGE_PIN V16  [get_ports {sw_raw[1]}]
set_property PACKAGE_PIN W16  [get_ports {sw_raw[2]}]
set_property PACKAGE_PIN W17  [get_ports {sw_raw[3]}]
set_property PACKAGE_PIN W15  [get_ports {sw_raw[4]}]
set_property PACKAGE_PIN V15  [get_ports {sw_raw[5]}]
set_property PACKAGE_PIN W14  [get_ports {sw_raw[6]}]
set_property PACKAGE_PIN W13  [get_ports {sw_raw[7]}]
set_property PACKAGE_PIN V2   [get_ports {sw_raw[8]}]
set_property PACKAGE_PIN T3   [get_ports {sw_raw[9]}]
set_property PACKAGE_PIN T2   [get_ports {sw_raw[10]}]
set_property PACKAGE_PIN R3   [get_ports {sw_raw[11]}]
set_property PACKAGE_PIN W2   [get_ports {sw_raw[12]}]
set_property PACKAGE_PIN U1   [get_ports {sw_raw[13]}]
set_property PACKAGE_PIN T1   [get_ports {sw_raw[14]}]
set_property PACKAGE_PIN R2   [get_ports {sw_raw[15]}]
set_property IOSTANDARD LVCMOS33 [get_ports {sw_raw[*]}]

## LEDs (led_out[0..15])
## led[0]    = RegWrite
## led[1]    = ALUSrc
## led[2]    = MemRead
## led[3]    = MemWrite
## led[4]    = MemtoReg
## led[5]    = Branch
## led[7:6]  = ALUOp[1:0]
## led[11:8] = ALUControl[3:0]
## led[15:12]= unused (0)
set_property PACKAGE_PIN U16  [get_ports {led_out[0]}]
set_property PACKAGE_PIN E19  [get_ports {led_out[1]}]
set_property PACKAGE_PIN U19  [get_ports {led_out[2]}]
set_property PACKAGE_PIN V19  [get_ports {led_out[3]}]
set_property PACKAGE_PIN W18  [get_ports {led_out[4]}]
set_property PACKAGE_PIN U15  [get_ports {led_out[5]}]
set_property PACKAGE_PIN U14  [get_ports {led_out[6]}]
set_property PACKAGE_PIN V14  [get_ports {led_out[7]}]
set_property PACKAGE_PIN V13  [get_ports {led_out[8]}]
set_property PACKAGE_PIN V3   [get_ports {led_out[9]}]
set_property PACKAGE_PIN W3   [get_ports {led_out[10]}]
set_property PACKAGE_PIN U3   [get_ports {led_out[11]}]
set_property PACKAGE_PIN P3   [get_ports {led_out[12]}]
set_property PACKAGE_PIN N3   [get_ports {led_out[13]}]
set_property PACKAGE_PIN P1   [get_ports {led_out[14]}]
set_property PACKAGE_PIN L1   [get_ports {led_out[15]}]
set_property IOSTANDARD LVCMOS33 [get_ports {led_out[*]}]
