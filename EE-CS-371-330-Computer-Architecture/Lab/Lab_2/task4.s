li x5, 3 # a
li x6, 2 # b
li x7, 0 # i
li x8, 0 # j
li x10, 0x200 # holds base addr of arr D

LOOPJ:

li x8, 0 #reset j for each i-th loop

LOOPI: 

slli x2, x8, 2 # j*4
add x3, x7, x8 # i + j
sw x3, 0x200(x2) # store (i+j) in D[j]

addi x8, x8, 1 # j++
blt x8, x6, LOOPI # if j < b, repeat LOOPI  

addi x7, x7, 1 # i++
blt x7, x5, LOOPJ # if i < a, repeat LOOPJ

EXIT:

