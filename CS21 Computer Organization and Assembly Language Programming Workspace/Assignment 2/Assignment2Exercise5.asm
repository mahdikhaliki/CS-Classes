
        .data

p1:     .asciiz "\nInput a Value for x = "
result: .asciiz "\nResult = "

x:      .word 0
answer: .word 0

        .text
        .globl  main
main:

# Exercise 5
        la      $a0, p1
        li      $v0, 4
        syscall

        li      $v0, 5
        syscall

        sw      $v0, x 

        lw      $t0, x
        li      $t1, 2
        mult    $t0, $t1
        mflo    $t1
        nop
        nop
        addi    $t1, -3
        mult    $t1, $t0
        mflo    $t1
        nop
        nop
        addi    $t1, 5
        mult    $t1, $t0
        mflo    $t1
        nop
        nop
        addi    $t1, 12

        sw      $t1, answer

        la      $a0, result
        li      $v0, 4
        syscall

        lw      $a0, answer
        li      $v0, 1
        syscall

# End of file
