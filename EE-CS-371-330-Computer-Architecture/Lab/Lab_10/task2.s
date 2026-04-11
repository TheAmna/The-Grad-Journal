# Memory Map:
#   0x000 - 0x1FF : Data Memory (stack lives at top)
#   0x400         : Switch peripheral (read)
#   0x800         : LED peripheral (write)
#   0xC00         : Reset button (read)
# Register usage:
#   x1  (ra)  - return address
#   x2  (sp)  - stack pointer        (0x1FC initially)
#   x6  (t1)  - temporary read value
#   x7  (t2)  - counter value
#   x8  (s0)  - switch base address  (0x400)
#   x9  (s1)  - LED base address     (0x800)
#   x18 (s2)  - reset base address   (0xC00)
#   x10 (a0)  - subroutine argument
.text
.globl _start

_start:
    li   x2,  0x1FC          # sp = 0x1FC, decimal 508
    # Memory-mapped addresses using li (safe encoding)
    li   x8,  0x400    # s0 = switch address
    li   x9,  0x800    # s1 = LED address
    li   x18, 0xC00    # s2 = reset button address

WAIT:
    sw   x0,  0(x9)     # clear LEDs garbage value for write purpose

WAIT_POLL:
    lw   x6,  0(x8)      # read switches input into x6
    beq  x6,  x0, WAIT_POLL  # loop if zero
    # Non-zero: display initial value and start countdown
    sw   x6,  0(x9)       # show initial value on LEDs if non-zero
    addi x10, x6,  0    # a0 = count value
    jal  x1,  COUNTDOWN    # call subroutine (ra saved internally)
    jal  x0,  WAIT          # return to WAIT when done
# Argument: a0 = initial count
#   sp+8 = saved ra
#   sp+4 = saved s0 (x8) switch base address
#   sp+0 = saved s1 (x9) LED base address
COUNTDOWN:
    addi x2,  x2,  -12
    sw   x1,  8(x2)    # save ra
    sw   x8,  4(x2)   # save s0 SWITCH base address
    sw   x9,  0(x2)    # save s1 LED base address
    addi x7,  x10, 0    # t2 = counter = a0

COUNT_LOOP:
    # Check reset button first
    lw   x6,  0(x18)         # read reset address
    bne  x6,  x0, COUNT_RESET
    beq  x7,  x0, COUNT_DONE
    sw   x7,  0(x9)          # LEDs = counter
    addi x7,  x7,  -1 # decrement 
    jal  x0,  COUNT_LOOP

COUNT_RESET:
    sw   x0,  0(x9)          # clear LEDs on reset

COUNT_DONE:
    lw   x9,  0(x2) #restre stack 
    lw   x8,  4(x2)
    lw   x1,  8(x2)
    addi x2,  x2,  12
    jalr x0,  x1,  0         # return to caller
