.data               # start of data section
# put any global or static variables here
myArr: .quad 1, 2, 3, 4, 5
myArrSize: .quad 5          # size of myArr = 5

# some other ways to declare, initialize arrays:
myArr2: .fill 40            # 40 bytes with 0s
myArr3: .space 40           # space for 40 bytes
myArr4: .skip 40            # space for 40 bytes

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
printString: .string "%d\n"

.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution

# === functions here ===
printArray:
# loop through an array of ints, print each element
# void printArray(int * myArr, int size)
# array pointer in %rdi, size in %rsi [see note at bottom about array size]
    # save any callee-saved registers
        # a. save all callee saved registers
        # b. just save the registers we use
        # c. not use any callee saved registers
        # d. ignore the rules
    # set-up variables
        movq %rdi, %rax     # pointer to array in rax
                # callee saved.  also, I had a stack alignment issue with printf
        pushq %rbx          # rbx on stack
        movq %rsi, %rbx     # size in rbx
        movq $0, %rcx       # int i = 0, in rcx
    # loop
    _startLoop:
        # get ready to call printf("%d ", n);
            # 1. save any caller saved registers
            pushq %rax      # rax on stack
            pushq %rcx      # rcx on stack
            # 2. set-up registers: rdi, rsi, ...
            movq $printString, %rdi     # pointer to string in rdi
                # pull out one element
            # generic: offset(source, index, width) --> *(source + index*width + offset)
                    # these all need to be registers, except width
            movq (%rax, %rcx, 8), %rsi    # 8 bytes.  *(rax(myArr) + rxc(i) * 8) 
            # 3. 0 in rax, no floating point registers
            xorq %rax, %rax     # 0 in rax
            # 4. call function
                # print the element
            call printf

            # restore caller-saved registers
            popq %rcx       # i in rcx
            popq %rax       # pointer to array in rax
       
        # set-up for the next loop
            # increment i
            inc %rcx        # i++

        # check to see if we're done, if i < size, keep looping
            cmpq %rbx, %rcx         #  rcx (i) ___ rbx (size)
                                    #       i   <   size
            jl _startLoop           # if rcx(i) < rbx (size), loop to _startLoop

        # otherwise return
    # restore callee saved registers
    popq %rbx
    movq $0, %rax                   # 0 in rax for return value
    ret     # end printArray


main:           # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === code here ===
# change 2nd element (i=1) to 10, [1,2,3,4,5] -> [1,10,3,4,5]
# generic: offset(source, index, width) --> *(source + index*width + offset)
movq $myArr, %rax   # pointer to array in rax
movq $1, %rbx       # index in rbx
movq $10, (%rax, %rbx, 8)       # can't move from memory, to memory
    # using offset to move over one more element: movq $10, 8(%rax, %rbx, 8)

# on the heap with malloc
# malloc(number of bytes) -> pointer in rax
# 1. save any caller-saved registers
# none
# 2. set-up registers
movq $40, %rdi
# 3. 0 in rax
xorq %rax, %rax
# 4. call function
call malloc

movq %rax, %rdi

# place a 10 in the 2nd element
movq $1, %rbx       # index in rbx
movq $10, (%rax, %rbx, 8)       # cen't move from memory, to memory

# printArray(myArr, 5);
# 1. save any caller-saved registers
# none
# 2. set-up registers: rdi, rsi, ...
movq $myArr, %rdi                      # comment out this line when doing malloc
movq myArrSize, %rsi
# 3. 0 in rax, no flaoting point registers
xorq %rax, %rax     # 0 in rax
# 4. call function
call printArray

# return
movq $0, %rax   # place return value in rax
leave           # undo preamble, clean up the stack
ret             # return

/*
NOTE: array size options
    a. keep the size in another variable
    b. set-up a sentinel, marker at the end, e.g. null character
    c. int: set first element as the size

NOTE2: This is the order I'll probably do this lab, compiling and running after each step
    1. set-up the array variable as a global variable in the .data section
    2. talk about ways to define size, set up size as a global variable
    3. create printArray function, just print one element
    4. modify printArray to print all elements
    5. show how to change the value of an element of the array
    6. malloc
    7. change element of the malloc array
*/