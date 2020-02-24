# Mahdi Khaliki
# Assignment 4 Exercise 6
# 3/12/18

        .data
array:  .space 40
prompt: .asciiz "Enter value: "

        .text
        .globl  main
main:
        li      $t0, 0                  # Count
        li      $t1, 36                 # Top of array index
input:
        la      $a0, prompt
        li      $v0, 4                  # Prompt user for input
        syscall
        li      $v0, 5                  # Read in integer
        syscall
        sw      $v0, array($t0)         # Store integer in array
        addi    $t0, $t0, 4             # Increment counter
        blt     $t0, 40, input
        nop

        li      $t0, 0                  # Reset count
print:
        lw      $a0, array($t0)         # Print original array
        li      $v0, 1
        syscall

        li      $a0, 9
        li      $v0, 11
        syscall

        addi    $t0, $t0, 4
        bne     $t0, 40, print
        nop

        li      $t0, 0                  # Reset count
swap:
        lw      $t2, array($t0)         # Hold lower index value in register
        nop
        lw      $t3, array($t1)         # Hold higher index value in register
        nop
        sw      $t2, array($t1)         # Swap lower to higher
        nop
        sw      $t3, array($t0)         # Swap higher to lower
        nop
        addi    $t0, $t0, 4             # Increment and decrement
        addi    $t1, $t1, -4
        blt     $t0, $t1, swap
        nop

        li      $a0, 10                 # Print new line
        li      $v0, 11
        syscall

        li      $t0, 0                  # Reset count
print2:
        lw      $a0, array($t0)         # Print new array
        li      $v0, 1
        syscall

        li      $a0, 9
        li      $v0, 11
        syscall

        addi    $t0, $t0, 4
        bne     $t0, 40, print2
        nop

        li      $v0, 10                 # End program
        syscall

