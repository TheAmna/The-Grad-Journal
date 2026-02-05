#task 4
#x10 destination string, x1 source string
#copies characters from y to x until null terminator '\0'


li x10, 0x200 # destination address
li x11, 0x300 # source address

li x14, 0x48   #'H'
sb x14, 0(x11)
li x14, 0x69  #'i'
sb x14, 1(x11)
li x14, 0x00  #'\0' 
sb x14, 2(x11)

jal x1, strcpy
j exit

strcpy:
    li x12, 0 #i=0
    
loop:
    add x13, x11, x12 #address of y[i]
    lb x14, 0(x13)  #load y[i]
    
    add x15, x10, x12 #address of x[i]
    sb x14, 0(x15)    #x[i] = y[i]
    
    beq x14, x0, done  #if y[i] == '\0', exit loop
    
    addi x12, x12, 1  #i++
    j loop
    
done:
    jalr x0, 0(x1)

exit:
