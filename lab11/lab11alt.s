.data               # start of data section
# put any global or static variables here
varX: .space 8      # space for 8 bytes (x) in data section
varY: .quad 0       # set-up a quad (8 bytes) space initialized to 0

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
scanfString: .string "%d"   # string to use with scanf to take user input. NOTE: no \n

.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution

# === functions here ===

addif:
    # takes two args x (rdi), y (rsi), adds them
    # together while result <= 3

    # save any callee saved registers, four approaches:
        # a. save all callee-saved registers
        # b. just save the registers we use
        # c. don't use any callee saved registers
        # d. ignore the rules
        # for this function, I just chose: b. just save what I use
    # prep rax, set to 0
    xorq %rax, %rax     # 0 in rax
    # start the loop
    _addifloop:
        # set-up variables
        movq %rdi, %rax     # x in rax
        # add x + y = result
        addq %rsi, %rax     # rsi (y) + rax (x) = result (rax)
        # increment x
        inc %rdi            # x++
        # check to see if I'm done
        cmpq $3, %rax       # (rax) result - 3, set flags
                            # (rax) result __ 3
                            # (rax) result <= 3
                            # rax -3 __ 0
                            #    + 3    + 3
                            # (rax) result ___ 3
        # we're not done, keep looping
        jle _addifloop
        # we're done, return, result in rax

    ret


main:           # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === code here ===
# addif(1, 0);
# set-up variables x=1, y=0
# scanf("%d", &x);

# 1. save any caller saved registers
# none
# 2. set-up registers: rdi, rsi, ...
movq $scanfString, %rdi         # a pointer to string in rdi
movq $varX, %rsi                # a pointer to var in rsi
# 3. 0 in rax, no floating point registers
xorq %rax, %rax     # 0 in rax
# 4. call function
call scanf


# 1. save any caller saved registers
# none
# 2. set-up register: rdi, rsi, ...
movq $1, %rdi
movslq varX, %rdi         # x in rdi
movq $0, %rsi
# 3. 0 in rax, no floating point registers
xorq %rax, %rax     # 0 in rax
# 4. call function
call addif


# return
movq $0, %rax   # place return value in rax
leave           # undo preamble, clean up the stack
ret             # return
