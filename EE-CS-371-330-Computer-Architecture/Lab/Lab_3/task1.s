# /*Write a code for the function sum shown in listing 3. It takes two integers a and b as arguments and returns
# their sum. You should also write code that calls this function i.e. it sets up the two arguments a and b in
# registers x10 and x11 and then calls sum(). After calling sum(), it then retrieves the returned result from
# the register x10. It can display the result using the ecall instruction.*/

# /*
# int sum(int a, int b) 
# {
#     return a + b;
# }
# */

li x10, 0  # a
li x11, 0  # b

addi x10, x0, 12 
addi x11, x0, 12
jal x1, sum # calls sum()
addi x11, x10, 0 # move return value to x11 for ecall
li x10, 1  # ecall for print integer
ecall   
j exit 

sum :
    add x10, x11, x10 # a + b
    jalr x0,0(x1) # return
exit :