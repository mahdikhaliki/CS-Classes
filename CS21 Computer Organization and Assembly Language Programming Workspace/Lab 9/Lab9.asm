## Mahdi Khaliki and Farris Tang
## Lab 9
## 4/30/18
## Note: branch delays turned off

        .data
output: .asciiz "\nInteger entered: "

        .text
        .globl main
main:

input:
        li      $t1, 0                  # total
        li      $t2, 10                 # 10
        li      $t3, 43                 # sign
        li      $a3, 0xffff0000         # Base of memory-mapped IO area

sign:
        lw      $t0, ($a3)              # Poll for character
        nop
        andi    $t0, $t0, 1
        beqz    $t0, sign               # If character has not been entered, loop

        lw      $t0, 4($a3)             # Load character into $t0
        nop
        sle     $t6, $t0, 32            # Check if white space
        beq     $t6, 1, sign            # While the character is white space

        seq     $t6, $t0, 43            # Set $t6 to 1 if character is '+'
        seq     $t7, $t0, 45            # Set $t7 to 1 if character is '-'
        or      $t6, $t6, $t7
        beqz    $t6, addToTotal         # If character is not '-' or '+'

        bne     $t0, 45, digit          # If is '-' make sign '-'
        li      $t3, 45

digit:
        lw      $t0, ($a3)              # Poll for character
        nop
        andi    $t0, $t0, 1
        beqz    $t0, digit              # If character has not been entered, loop

        lw      $t0, 4($a3)             # Load character into $t0
        nop
addToTotal:
        sge     $t6, $t0, 48            # Check if character is a digit
        sle     $t7, $t0, 57

        bne     $t6, $t7, end           # If character is not a digit, end

        mul     $t1, $t1, $t2           # total *= 10
        addi    $t0, $t0, -48           # character – '0'
        add     $t1, $t0, $t1           # total += digit
        j       digit                   # Get a character

end:
        beq     $t3, 43, print
        sub     $t1, $zero, $t1
print:
        move    $t0, $t1

        la      $a0, output             # Print output message
        li      $v0, 4
        syscall

        move    $a0, $t0                # Print integer
        li      $v0, 1
        syscall

        li      $v0, 10                 # End program
        syscall
