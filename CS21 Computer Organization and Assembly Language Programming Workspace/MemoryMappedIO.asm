#
# memmapIO.asm
#
# Keith Mehl
# 11/19/12
# CS21 example program
# Illustrate polling and memory-mapped IO
# Turn on memory-mapped IO, load/branch delays, pseudoinstructions.
# Turn off load exception handler.
#
.text
.globl        main
main:        la        $a0, pMsg                # read a string from console
jal        printIt                        # without syscall
nop
la        $a0, str                # address of input buffer
jal        readIt
nop
la        $a0, rMsg                # print the string
jal        printIt                        # again, without syscall
nop
la        $a0, str
jal        printIt
nop
li        $v0, 10
syscall

#         read routine using simplest calling convention, w/buffer address in $a0
readIt:        li        $a3, 0xffff0000                # base of memory-mapped IO area
rloop:        lw        $t1,($a3)
nop
andi        $t1, $t1, 1                # mask off ready bit
beqz        $t1, rloop
nop
lw        $t0, 4($a3)                # extract character (as a word)
nop
sb        $t0, ($a0)                # put the byte into buffer
nop
li        $t2, 0x0a                # 0x0A is '\n' (newline) character
beq        $t0, $t2, rexit                # if we just read the '\n' byte, exit
nop
addiu        $a0, $a0, 1                # advance to next byte
j        rloop                        # otherwise try again
nop
rexit:        li        $t2, 0
addiu        $a0, $a0, 1
sb        $t2, ($a0)                # add terminating NUL to C-string
jr        $ra
nop

#         print routine using simplest calling convention, string address in $a0
printIt:
li        $a3, 0xffff0000                # base of memory-mapped IO area
ploop:        lw        $t1, 8($a3)                # extract transmitter control
nop
andi        $t1, $t1, 1                # mask off ready bit
beqz        $t1, ploop
nop
lb        $t0, ($a0)                # extract next character
nop
beqz        $t0, pexit                # find the 0 byte? Yes == exit
nop
sw        $t0, 12($a3)                # write character to display
addiu        $a0, $a0, 1                # advance to next character
j        ploop                        # and try again
nop
pexit:        jr        $ra
nop

.data
pMsg:        .asciiz        "Enter a string (nothing will appear on screen)\n"
rMsg:        .asciiz        "You entered\n"
str:        .space        200                        # room for user's enrty
