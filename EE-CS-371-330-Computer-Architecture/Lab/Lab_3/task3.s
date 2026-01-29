li x10, 0x100 #arr v[]
li x11, 2  # k (size of arr)
li x14, 5 # random val to populate the arr
li x15, 8 

sw x14, 0(x10)  # stroe in arr
sw x15, 4(x10)

jal x1, SWAP 
j exit 

SWAP : 
    slli, x12, x11, 2 # k*4
    add x12, x10, x12  # address of v[k] at 2
    
    lw x16, 0(x12) # temp = v[k]
    sw x16, 4(x12) # v[k] = v[k+1]
    lw x17, 4(x12)  # load v[k+1]
    sw x17, 0(x12) # v[k+1] = temp 
    jalr x0,0(x1) # return
exit : 