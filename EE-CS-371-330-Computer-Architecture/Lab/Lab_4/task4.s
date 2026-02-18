# c code
# int binary_search(int* arr, int low, int high, int target) {
#     if (low > high) return -1;
#     int mid = low + (high - low) / 2;
#     if (arr[mid] == target) return arr[mid];
#     else if (arr[mid] < target) return binary_search(arr, mid+1, high, target);
#     else return binary_search(arr, low, mid-1, target);
# }

# array {3, 11, 25, 42, 67}
# target 25
# result in x10: 25 if found, -1 if not

    addi sp, sp, -20 #create space on stack
    li   x5, 3
    sw   x5,  0(sp) #arr[0] = 3
    li   x5, 11
    sw   x5,  4(sp) #arr[1] = 11
    li   x5, 25
    sw   x5,  8(sp) #arr[2] = 25
    li   x5, 42
    sw   x5, 12(sp) #arr[3] = 42
    li   x5, 67
    sw   x5, 16(sp) #arr[4] = 67
    add  x10, sp,  x0  # x10 = array address
    li   x11, 0   #low = 0
    li   x12, 4  #high = 4
    li   x13, 25 #target = 25
    jal  x1, BSEARCH #call


# args: x10=arr  x11=low  x12=high  x13=target
# returns: x10 = target value if found, -1 if not found
BSEARCH:
    addi sp, sp, -20
    sw   x1,   0(sp) #save ra
    sw   x18,  4(sp) #save low
    sw   x19,  8(sp) #save high
    sw   x20, 12(sp) #save target
    sw   x21, 16(sp) #save arr base

    add  x21, x10, x0 #x21 = arr
    add  x18, x11, x0 #x18 = low
    add  x19, x12, x0  #x19 = high
    add  x20, x13, x0 #x20 = target

    bgt  x18, x19, NOTFOUND  #low > high 

    sub  x5, x19, x18  #high - low
    srai x5, x5,  1  #divide by 2 
    add  x5, x18, x5 #x5 = mid

    slli x6, x5,  2   #mid*4 
    add  x6, x21, x6  #x6 = &arr[mid]
    lw   x7, 0(x6)  #x7 = arr[mid]

    beq  x7, x20, FOUND    #arr[mid] == target
    blt  x7, x20, GORIGHT  #arr[mid] < target 

GOLEFT:
    add  x10, x21, x0
    add  x11, x18, x0
    addi x12, x5,  -1  #high = mid - 1
    add  x13, x20, x0
    jal  x1, BSEARCH
    j    DONE
GORIGHT:
    add  x10, x21, x0
    addi x11, x5,  1  #low = mid + 1
    add  x12, x19, x0
    add  x13, x20, x0
    jal  x1, BSEARCH
    j    DONE
NOTFOUND:
    li   x10, -1
    j    DONE
FOUND:
    add  x10, x7, x0  #return the value itself
DONE:
    lw   x1,   0(sp) #restore ra
    lw   x18,  4(sp)
    lw   x19,  8(sp)
    lw   x20, 12(sp)
    lw   x21, 16(sp)
    addi sp,  sp,  20
    jalr x0,  x1,  0
