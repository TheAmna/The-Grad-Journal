# Group Members : Humna Khan and Amna Ali 

.text 
.globl main

main:
    li x20, 5  # a = 5 
    li x21, 0   # 0
   
    addi x20, x21, 32  # a = b + 32
    # x20 stores a
    # x21 stores b
    add  x22, x20, x21 # d = a + b
    addi x22, x22, -5 # d = (a + b) - 5
    # x22 stores d

    sub  x23, x20, x22 # e = a(32) - d(27)   => 5
    sub  x24, x21, x20 # temp = b(0) - a (32)  => -32  
    add  x23, x23, x24 # e = (a - d)(5) + (b - a)(-32) => -27
    add  x23, x23, x22 # e = e(-27) + d(27) => 0

    add x23, x23, x20  # e = a(32) + e(0) => 32
    add x23, x23, x21  # e = b(0) + e(32) => 32
    add x23, x23, x22  # e = d(27) + e(32) => 59
   
end:
    j end 



