
li x10, 0x100 #arr base address
li x11, 0   #k = 1 (swap v[1] and v[2])
li x14, 5 #first value
li x15, 8 #second value

sw x14, 0(x10)  #v[0]=5
sw x15, 4(x10)  #v[1]=8

jal x1, SWAP
beq x0,x0,exit

SWAP:
    slli x12, x11, 2  #k*4
    add x12, x10, x12 #address of v[k]
    lw x16, 0(x12)    #temp = v[k]
    lw x17, 4(x12)    #load v[k+1]
    sw x17, 0(x12)    #v[k] = v[k+1]
    sw x16, 4(x12)    #v[k+1] = temp 
    jalr x0, 0(x1)   

exit:
