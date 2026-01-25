
li x5, 10 #limit of the loop
li x22, 0 #i=0 
li x23, 0 #sum=0

#first loop
loop1:
beq x22, x5, loop1_end

slli x6, x22, 2  #i*4
addi x6, x6, 0x200  #a[i]
sw x22, 0(x6)

addi x22, x22, 1 #i++
beq x0, x0, loop1

loop1_end:
li x22, 0 # reset i

#second loop sum = sum + a[i]
loop2:
beq x22, x5, loop2_end

slli x6, x22, 2 # i*4
addi x6, x6, 0x200  #a[i]
lw x7, 0(x6)     

add x23, x23, x7 #sum=sum+a[i]

addi x22, x22, 1 # i++
beq x0, x0, loop2

loop2_end:
