# Mahdi Khaliki
# Assignment 4 Exercise 5
# 3/12/18

        .data
array:  .space 40
prompt: .asciiz "Enter value: "
output: .asciiz "Smallest: "
output1:
        .asciiz "\nLargest: "

        .text
        .globl  main
main:
        li      $t0, 0
input:
        la      $a0, prompt             # Prompt user for input
        li      $v0, 4
        syscall
        li      $v0, 5                  # Read in integer
        syscall
        sw      $v0, array($t0)         # Store integer in array
        addi    $t0, $t0, 4             # Increment counter
        blt     $t0, 40, input
        nop

        li      $t0, 0
        lw      $t1, array($t0)         # Set smallest to first element
        nop
        or      $t2, $zero, $t1         # Set largest to first element

loop:
        addi    $t0, $t0, 4
        bge     $t0, 40, end
        nop
        lw      $t3, array($t0)
        nop
        blt     $t3, $t1, adjustSmallest
        nop
        bgt     $t3, $t2, adjustLargest
        nop
        b       loop
        nop

adjustSmallest:
        or      $t1, $zero, $t3
        b       loop
        nop

adjustLargest:
        or      $t2, $zero, $t3
        b       loop
        nop

end:
        li      $v0, 4                  # Print smallest output
        la      $a0, output
        syscall

        or      $a0, $zero, $t1
        li      $v0, 1
        syscall

        li      $v0, 4                  # Print smallest output
        la      $a0, output1
        syscall

        or      $a0, $zero, $t2
        li      $v0, 1
        syscall

        li      $v0, 10                 # End program
        syscall
