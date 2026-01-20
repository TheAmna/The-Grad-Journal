
li x1, 1
li x2, 2
li x3, 3

# array A takes 1 byte
sb x1, 0x100(x0)
sb x1, 0x101(x0)
sb x1, 0x102(x0)
sb x1, 0x103(x0)

# array B takes 2 bytes
sh x2, 0x200(x0)
sh x2, 0x202(x0)
sh x2, 0x204(x0)
sh x2, 0x206(x0)

# c[0] = a[0] + b[0]
lb x4, 0x100(x0)
lh x5, 0x200(x0)
add x6, x4, x5

# c[1] = a[1] + b[1]
lb x7, 0x101(x0)
lh x8, 0x202(x0)
add x9, x8, x7

# c[2] = a[2] + b[2]
lb x10, 0x102(x0)
lh x11, 0x204(x0)
add x12, x11, x10

# c[3] = a[3] + b[3]
lb x13, 0x103(x0)
lh x14, 0x206(x0)
add x15, x13, x14

# store in array C (unsigned int)
# takes 4 bytes 
sw x6, 0x300(x0)
sw x9, 0x304(x0)
sw x12, 0x308(x0)
sw x15, 0x30c(x0)
