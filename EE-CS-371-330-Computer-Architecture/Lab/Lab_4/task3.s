li x10, 0x100 # a ptr
li x11, 3 # len 
li x7 , 0 #i=0
li x8 , 0 #temp

li x1, 5            
sw x1, 0(x10)       
li x1, 2           
sw x1, 4(x10)        
li x1, 9            
sw x1, 8(x10)        

beq x10, x0, EXIT # if ptr == 0, exit 
beq x11, x0, EXIT # if len == 0, exit 
addi x5, x11, -1      # outer loop bound = len-1

LOOPJ:
li x8, 0 #reset j for each i-th loop
sub x6, x11, x7       #  len - i
addi x6, x6, -1       # len - i - 1


LOOPI: 
slli x12, x8, 2        # offset = j * 4
add x13, x10, x12      # addr = base + offset
lw x2, 0(x13)          # a[j]
lw x3, 4(x13)          # a[j+1]
ble x2, x3, NO_SWAP
sw x3, 0(x13)
sw x2, 4(x13)

NOSWAP:
addi x8, x8, 1 # j++
blt x8, x6, LOOPI # if j < i, LOOPI
addi x7, x7, 1 # i++
blt x7, x5, LOOPJ # if i < len, LOOPJ

EXIT:
