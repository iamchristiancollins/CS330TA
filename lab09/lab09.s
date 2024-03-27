.data               # start of data section
# put any global or static variables here

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
myString: .string "The answer is %d\n"


.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===

main:               # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === main() code here ===

# set up a = 2
movq $2, %rax   # a = 2 in rax
# set up b = 3
movq $3, %rbx   # b = 3 in rbx
# add a+b=c
addq %rbx, %rax # c (rax) = a (rax) + b (rbx)

# printf("The answer is %d\n", c)
# 1. Save any caller saved registers
    # a move to a different register
pushq %rax
pushq %rax
# 2. set up our registers
movq $myString, %rdi
movq %rax, %rsi

# 3. 0 in rax since 0 floating point registers
xorq %rax, %rax
# 4. call function
call printf

popq %rax
popq %rax


# clean up and return
movq $0, %rax       # place return value in rax
leave               # undo preamble, clean up the stack
ret                 # return
