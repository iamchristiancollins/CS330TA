.data               # start of data section
# put any global or static variables here
myY: .space 8       # assign 8 bytes to myY
myY2: .quad 0       # assign 8 bytes, initializes 0

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
printString: .string "The answer is %d\n"   # string to print the answer
scanString: .string "%d"                    # string to take user input, note: no '\n'
userInputPrintString: .string "\n\nPlease enter an int, y, \nwhere 2 will be raised to the y power, 2^y: "

.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution

# === functions here ===

# pow(x, y).  calc x^y
# takes two ints, x(rdi) and y(rsi), raises x to the power of y,
# returns the answer in rax
# NOTE: this doesn't work when y=0, can you fix it?
pow:
    # save any callee-saved registers
        # none
    # set-up variables
        # x in rdi
        # y in rsi
        # counter (i)
        movq $0, %rcx           # i=0 in rcx
        # int answer = 1;
        movq $1, %rax           # answer = 1 in rax
    # for(int i = 0; i<y; i++)
    _forLoop:
        # answer = answer * x
        imulq %rdi          # rdi(x) * rax(answer) --> rax(answer)
        # increment i
        inc %rcx            # i++ in rcx
        # check to see if I'm done looping
        cmpq %rsi, %rcx     # rcx(i) - rsi(y), setting eflags
                            # rcx(i) - rsi(y) __ 0
                            #        + rsi(y)    +rsi(y)
                            # rcx(i) < rsi(y).  je, jl, jle, jg, jge
                            # rcx(i) < rsi(y)
        jl _forLoop         # if rcx(i) < rsi(y), keep looping

    # return answer (rax)
    # restore any callee-saved registers
    ret             # end of pow() function


# =====================================
# ========== start of main() ==========
main:           # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === code here ===

# ========== take user input ==========
# First, let's print a nice note to warn the user we're expecting input (added this after lab)
# printf("Please enter an int: \n");
# 1. save any caller saved registers
    # none
# 2. set-up registers: rdi, rsi, ...
    movq $userInputPrintString, %rdi
# 3. 0 in rax, no floating point registers
    xorq %rax, %rax
# 4. call the function
    call printf

# ===== call scanf to get user input =====
# scanf("%d", &y); 
# 1. save any caller saved registers
    # none
# 2. set-up registers: rdi, rsi, ...
    movq $scanString, %rdi          # ptr to string in rdi
    movq $myY2, %rsi                # ptr to variable for use input (&y) in rsi
# 3. 0 in rax
    xorq %rax, %rax
# 4. call function
    call scanf                      # now user input stored in myY2


# ========== call the pow() function ==========
# pow(2, 3)
# 1. save any caller-saved registers
    # none
# 2. set-up registers: rdi, rsi, ...
    movq $2, %rdi                   # x=2 in rdi
    #movq $3, %rsi                  # y=3 in rsi
    movq myY2, %rsi                 # myY2 in rsi. Note: no '$', this dereferences the myY2 pointer
    movq (myY2), %rsi               # parens also dereferences the myY2 pointer to get the variable value
    movslq (myY2), %rsi             # use movslq to move/copy a signed int from memory
# 3. 0 in rax, no floating pt registers
    xorq %rax, %rax
# 4. call function
    call pow


# ========== print the answer ==========
# printf("The answer is %d\n", answer);
# 1. save any caller saved reg
    # none
# 2. set-up reg: rdi, rsi
    movq $printString, %rdi         # string ptr in rdi
    movq %rax, %rsi                 # answer in rsi
# 3. 0 in rax, zero floating pt reg
    xorq %rax, %rax
# 4. call function
    call printf

# return
movq $0, %rax   # place return value in rax
leave           # undo preamble, clean up the stack
ret             # return
