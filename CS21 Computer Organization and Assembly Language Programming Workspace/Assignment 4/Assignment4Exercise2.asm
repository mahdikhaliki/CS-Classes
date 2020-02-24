# Mahdi Khaliki
# Assignment 4 Exercise 2
# 3/12/18

        .data
string: .asciiz "in a  hole in the  ground there lived a hobbit"

        .text
        .globl  main
main:
        li      $t0, 0                  # Increment
        li      $t1, 32                 # Used as previous character

        la      $a0, string             # Print original string
        li      $v0, 4
        syscall
        li      $a0, 10                 # Print new line
        li      $v0, 11
        syscall

Capitalize:
        lb      $t2, string($t0)
        nop
        beq     $t2, 0, end
        nop
        bne     $t1, 32, else
        nop
        bgt     $t2, 96, UpperCase
        nop
        beq     $t2, 32, else
        nop
end:
        la      $a0, string             # Print new string
        li      $v0, 4
        syscall

        li      $v0, 10                 # End program
        syscall

UpperCase:
        addi    $t2, $t2, -32           # Make char upper case
        sb      $t2, string($t0)

        or      $t1, $zero, $t2         # Copy char into previous
        addi    $t0, $t0, 1
        b       Capitalize
        nop

else:
        or      $t1, $zero, $t2
        addi    $t0, $t0, 1
        b       Capitalize
        nop
