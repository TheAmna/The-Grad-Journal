li x10, 0x100 # arr x 
li x11, 0x200 # arr y
li x19, 0 # i

jal x1, strcpy
j exit

strcpy:
    beq 