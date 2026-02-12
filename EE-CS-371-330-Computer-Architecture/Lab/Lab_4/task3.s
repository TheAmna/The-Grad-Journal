li x10, 0x100 # a ptr
li x11, 3 # len 
li x7 , 0 #i=0
li x8 , 0 #j=0 

LOOPJ:
li x8, 0 #reset j for each i-th loop

LOOPI: 
lw x2, 0(x10) # load a[i]
add x3, x7, x8 # i + j
sw x3, 0x200(x2) # store (i+j) in D[j]

addi x8, x8, 1 # j++
blt x8, x6, LOOPI # if j < b, repeat LOOPI  

addi x7, x7, 1 # i++
blt x7, x5, LOOPJ # if i < a, repeat LOOPJ

EXIT:
