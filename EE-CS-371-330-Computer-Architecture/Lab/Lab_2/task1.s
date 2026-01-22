assuming variables f to j are registers x19-x23
li x19, 1 #f
li x20, 1 #g
li x21, 1 #h
li x22, 1 #i
li x23, 1 #j

bne x22, x23, ELSE  # if ( i != j)
add x19, x20, x21       #  f =  g + h
beq x0, x0 , EXIT    # True condition to exit loop 

ELSE : 
sub x19, x20, x21     # f = g - h 

EXIT :


# assuming i & k in x22 and x24

li x22, 1  # i
li x24, 4  # k
li x26, 2 

sw x26, 4(x25)
sw x26, 8(x25)
sw x26, 12(x25)
sw x26, 16(x25)

LOOP : 
# shift left immediate 
slli x10, x22, 3  # temp reg x10 = i*8
add x10, x10, x25  # x10 = adrress of save[i]
ld x9, 0(x10)  # temp reg x9 = save[i]
bne x9, x24, EXIT  # EXIT if save[i] != k
addi x22, x22, 1  # i = i+1
beq x0, x0, LOOP # LOOP againnn

EXIT :