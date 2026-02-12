li x10, 3 # n=3
li x7, 1 # i
li x6, 1 # temp

fact:
    bgt x7, x10, end  # i> n, terminate 
    mul x6, x6, x7 # temp = temp * i
    addi x7, x7, 1 # i = i+1
    jal x0, fact # recursive call

end:
    addi x10, x6, 0 # return temp value 
    jalr x0, 0(x1)  # function return 
