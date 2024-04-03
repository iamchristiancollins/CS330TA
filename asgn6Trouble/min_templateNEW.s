.data               # start of data section
# put any global or static variables here
a: .quad 50
b: .quad 10

.section .rodata 
# start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
multString: .string "The answer is %d\n"

.text           # start of text /code
# everything inside .text is read-only, which includes your code!
.global main  # required, tells gcc where to begin execution

# === functions here ===


Mult:
# addq %rdi, 
# movq %rdi, %rax         #B in rax
imulq %rbx          # Multiplies rbx value by result in rax
ret

Sub:
movq a, %r8  # Moves a to r8 register
movq b, %r9 #  Moves b to r9 register
addq %r8, %r9 #   Adds a and b, and stores result in r9 register

movq a, %r10 # Moves a to r10 register
movq b, %r11 #  Moves b to r11 register

div %r10, %r11  # Divides a by b and stores in %r11 register
sub %r9, %r11    # Subtracts r9 value(a+b) by rll value(a/b)
ret

Add:
# addq $a, 
# ret

main:           # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp

# === code here ===
#Mult Func
movq $5, %rax
movq a, %rbx

movq %rax, %rsi
# movq $0, %rax

call Mult
movq $multString, %rdi
call printf

#Add Func


#Sub Func

call Sub
movq $multString, %rdi
call printf

# return
movq $0, %rax   # place return value in rax
leave           # undo preamble, clean up the stack
ret             # return
