

li x10, 2  #g
li x11, 2  #h
li x12, 1  #i
li x13, 2  #j
li x20, 0 #f

li x18, 0 #temp 1
li x19, 0 # temp 2

jal x1, leaf_example # x1 holds return address
li x10, 1    # x10 for func argumnt

ecall
j exit 

leaf_example : 

addi sp,sp, -12  # load in stack 
sw x18, 8(sp)
sw x19, 4(sp)
sw x20, 0(sp)

add x18, x10, x11  # temp1 = g + h
add x19, x12, x13 # temp2 = i + j
sub x20, x18, x19 # f = temp1 - temp2

addi x11, x20, 0
lw x20, 0(sp)
lw x19, 4(sp)
lw x18, 8(sp)

addi sp, sp, 12  # unload from stack
jalr x0, 0(x1) # return

exit :

