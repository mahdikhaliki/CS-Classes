# Mahdi Khaliki
# Assignment 4 Exercise 3
# 3/12/18

        .data
string: .asciiz "In a  Hole in the  Ground there lived A hobbit"

        .text
        .globl  main
main:
        li      $t0, 0                  # Increment
        li      $t1, 32                 # Used as previous character

        la      $a0, string             # Print original string
        li      $v0, 4
        syscall
        li      $a0, 0xA                # Print new line
        li      $v0, 0xB
        syscall

Capitalize:
        lb      $t2, string($t0)
        nop
        beq     $t2, 0, end
        nop
        bne     $t1, 32, else
        nop
        bgt     $t2, 64, UpperCase
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
        blt     $t2, 97, else
        nop
        addi    $t2, $t2, -32           # Make char upper case
        sb      $t2, string($t0)

        or      $t1, $zero, $t2         # Copy char into previous
        addi    $t0, $t0, 1             # Increment
        b       Capitalize
        nop

else:
        or      $t1, $zero, $t2         # Copy char into previous
        addi    $t0, $t0, 1             # Increment
        b       Capitalize
        nop
