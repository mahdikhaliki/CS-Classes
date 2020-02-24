# Mahdi Khaliki
# Assignment 4 Exercise 4
# 3/12/18

        .data
string: .asciiz ""
prompt: .asciiz "Enter in a string: "

        .text
        .globl  main
main:
        li      $t0, 0                  # Count

        la      $a0, prompt
        li      $v0, 4
        syscall

        li      $v0, 8                  # Get user input
        la      $a0, string
        syscall

loop:
        lb      $t2, string($t0)
        nop
        beq     $t2, 0, end
        nop
        bgt     $t2, 96, UpperCase
        nop
        bgt     $t2, 64, LowerCase
        nop

        addi    $t0, $t0, 1             # Else increment
        b       loop
        nop

UpperCase:
        addi    $t2, $t2, -32           # Make char upper case
        sb      $t2, string($t0)
        addi    $t0, $t0, 1             # Increment
        b       loop
        nop

LowerCase:
        addi    $t2, $t2, 32            # Make char upper case
        sb      $t2, string($t0)
        addi    $t0, $t0, 1             # Increment
        b       loop
        nop

end:
        la      $a0, string
        li      $v0, 4                  # Print new string
        syscall
        li      $v0, 10
        syscall
