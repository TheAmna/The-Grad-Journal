# The switch statement is similar to if/else statements. 
#Write the equivalent RISC-V assembly code for Listing
# Assume that the variables x, a, b & c are signed integers
# and stored in x20, x21, x22, x23 respectively.
# Make sure to first assign suitable values for b and c first.


li x20, 4 #x
li x21, 1 #a
li x22, 6 #b
li x23, 3 #c

li x24, 1 # 1
li x25, 2 # 2
li x26, 3 # 3
li x27, 4 # 4
li x28, 0 # 0

beq x20, x24, CASE1
beq x20, x25, CASE2
beq x20, x26, CASE3
beq x20, x27, CASE4


sub x21, x21, x21 # a= a-a
beq x21, x28, EXIT

CASE1 :
add x21, x22, x23 # a = b + c
beq x0, x0, EXIT  #  break

CASE2 :
sub x21, x22, x23 # a = b - c
beq x0, x0, EXIT  #  break

CASE3 :
slli x21, x22, 1  # a = b*2
beq x0, x0, EXIT  #  break

CASE4 :
srli x21, x22, 1  # a = b/2
beq x0, x0, EXIT  #  break


EXIT :

