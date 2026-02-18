
li x10, 0x100      # base address of array
li x11, 3          # len = 3
li x7, 0           # i = 0

# arr = [1,5,4]
li x1, 1
sw x1, 0(x10)
li x1, 5
sw x1, 4(x10)
li x1, 4
sw x1, 8(x10)

beq x10, x0, EXIT
beq x11, x0, EXIT

LOOPJ:
bge x7, x11, EXIT      # if i >= len → exit
add x8, x7, x0              # j = i

LOOPI:
bge x8, x11, NEXT_I    # if j >= len → next i
slli x12, x7, 2        # load a[i]
add x13, x10, x12      
lw x2, 0(x13)          # x2 = a[i]
slli x14, x8, 2        # load a[j]
add x15, x10, x14      # 
lw x3, 0(x15)          # x3 = a[j]
bge x2, x3, NO_SWAP    # if a[i] >= a[j], skip
add x4, x2, x0         # temp = a[i]
sw x3, 0(x13)          # a[i] = a[j]
sw x4, 0(x15)          # a[j] = temp

NO_SWAP:
addi x8, x8, 1         # j++
beq x0,x0, LOOPI

NEXT_I:
addi x7, x7, 1         # i++
beq x0,x0, LOOPJ

EXIT:
