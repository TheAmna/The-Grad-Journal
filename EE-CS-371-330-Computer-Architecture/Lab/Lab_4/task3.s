ld x10, 0x100(x0) # a ptr
li x11, 3 # len 
li x7 , 2 #i=0
li x8 , 3 #j=0 
li x9 , 0 # temp


beq x10, x0, EXIT 
beq x11, x0, EXIT 

LOOPJ:
li x8, 0 #reset j for each i-th loop

LOOPI: 
lw x2, 0(x10) # load a[i]
lw x3, 4(x10) # load a[j]
bgt x2,x3, NOSWAP

add x9, x2,x0 # temp + a[i]
add x2, x0, x3 # a[i] = x0 + a[j]
add x3, x9, x0 # a[j] = x0 + temp

sw x2, 0(x10)
sw x3, 4(x10)

NOSWAP:
addi x8, x8, 1 # j++
addi x10, x10,4  # moving ptr 
blt x8, x7, LOOPI # if j < i, repeat LOOPI

addi x7, x7, 1 # i++
blt x7, x11, LOOPJ # if i < len, repeat LOOPJ

EXIT:
