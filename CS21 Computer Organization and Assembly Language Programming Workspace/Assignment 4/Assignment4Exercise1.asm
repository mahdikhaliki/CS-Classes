# Mahdi Khaliki
# Assignment 4 Exercise 1
# 3/12/18

        .data
string: .asciiz "ABCDEFG"

        .text
        .globl  main
main:
        li      $t0, 0                  # Increment

        la      $a0, string             # Print original string
        li      $v0, 4
        syscall
        li      $a0, 0xA                # Print new line
        li      $v0, 0xB
        syscall

loop:
        lb      $t1, string($t0)        # Hold char in $t1
        nop
        bne     $t1, 0, LowerCase
        nop

        la      $a0, string             # Print new string
        li      $v0, 4
        syscall

        li      $v0, 10                 # End program
        syscall

LowerCase:
        addi    $t1, $t1, 0x20          # Adjust char in $t1
        sb      $t1, string($t0)        # Store char in $t1
        nop
        addi    $t0, $t0, 1             # increment
        b       loop
        nop
