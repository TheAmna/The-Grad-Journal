.text
.globl main


main:

    # Store x10 as unsigned integer at address 0x100.
    li x5, 0x100
    sw x10 0(x5) # load into x10
   
    // Store x11 as unsigned integer at address 0x1F0.
    li x6 , 0x1F0
    sw x11 0(x6) //load into x11
   
    // Load an unsigned short integer (two bytes) from address 0x100 in x12.
    lhu x12 0(x5) //load into x12

    // Load a short integer from address 0x1F0 in register x13.
    lh x13 0(x6)  //load into x13

    // Load a singed character from address 0x1F0 in register x14.
    lb x14 0(x6) //load into x14

end:
    j end
