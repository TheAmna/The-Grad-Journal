li x1, 0 #i
li x2, 0 #sum
li x3, 10 # loop limit 
li x4, 0 # comparing with 0
li x5, 0 # for storing i%2
li x6, 2 # div by 2

LOOP:
    beq x1, x3, EXIT  # if i ==10, exit loop
    rem x7, x1, x6 # x7 = i/2
    beq x4, x7, CONDITION # if i/2 ==0, go to condition
    addi x1, x1,1   # i++
    beq x0,x0, LOOP # go to LOOP
CONDITION:
    add x2, x2, x1 # sum = sum + i
    addi x1,x1, 1 # i++
    beq x0, x0, LOOP # go to LOOP

EXIT:


# #define SIZEC 10
# //Each number is always smaller than 64
# int c[SIZEC]={23, 12, 5, 44, 98, 53, 6, 89, 32, 65};
# void main ()
# {
# //printf("Array before bubble sort\n");
# //for(int j=0; j<SIZEC; j++) printf("%d,", c[j]);
# //printf("\n");
# int swapped;
# do
# {
# swapped = false;
# for (int i =1; i< SIZEC; i++)
# {
# if(c[i-1] > c[i])
# {
# int temp = c[i];
# c[i]=c[i-1];
# c[i-1] = temp;
# swapped = true;
# }
# }
# } while (swapped);
# //printf("Array after bubble sort\n");
# //for(int j=0; j<SIZEC; j++) printf("%d,", c[j]);
# //printf("\n");
# return 0;
# }

ld x1, 0x100(x0)  # arr c[0]
ld x2, 0x108(x0)  # arr c[1]
ld x3, 0x110(x0) # arr c[2]
ld x4, 0x118(x0) # arr c[3]
ld x5, 0x120(x0) # arr c[4]
ld x6, 0x128(x0) # arr c[5]
ld x7, 0x130(x0) # arr c[6]
ld x8, 0x138(x0) # arr c[7]
ld x9, 0x140(x0) # arr c[8]
ld x10, 0x148(x0) # arr c[9]

sd x1, 23
sd x2, 12
sd x3, 5
sd x4, 44
sd x5, 98
sd x6, 53
sd x7, 6
sd x8, 89
sd x9, 32
sd x10, 65


li x11, 1 # True condition
li x12, 1 # i=1
li x13, 10 # SIZEC=10
li x14, 0 # temp
li x15, 0x100 

OUTERLOOP:
   

    INNERLOOP:
        beq x12, x13, OUTERLOOP # if i==SIZEC, go to outerloop
        slli x20, x12, 3 # i*8
        ld x21, -8(x0) # load c[i-1] 
        ld x22, 0x100(x0) # load c[i]
        bge x21, x22, SWAP # if c[i-1] > c[i], go to swap

        SWAP : 
            sd x14, 0x100(x0) # temp = c[i]
            sd x15, x21 # c[i] = c[i-1]
            sd x21, x14 # c[i-1] = temp
            li x11, 1 # swapped = true

        addi x12, x12, 1 # i++
        beq x0, x0, INNERLOOP # go to innerloop
        bne x11, x0, OUTERLOOP # if swapped == true, repeat outerloop
        li x11, 0 # swapped = false
        li x12, 1 # i=1
    b   bne x11, x11, EXIT # always true to enter inner loop

EXIT:
