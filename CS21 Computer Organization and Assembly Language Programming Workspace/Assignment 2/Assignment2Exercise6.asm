
        .data

p1:     .asciiz "\nInput a Value for x = "
p2:     .asciiz "\nInput a Value for y = "
result: .asciiz "\nResult = "
x:      .word 0
y:      .word 0
answer: .word 0

        .text
        .globl  main
main:

# Exercise 6
        la      $a0, p1
        li      $v0, 4
        syscall

        li      $v0, 5
        syscall

        sw      $v0, x   

        la      $a0, p2
        li      $v0, 4
        syscall

        li      $v0, 5
        syscall

        sw      $v0, y 

        lw      $t0, x
        li      $t2, 18
        mult    $t0, $t2
        mflo    $t2
        li      $t3, 12
        lw      $t1, y
        addi    $t2, -6
        mult    $t2, $t1
        mflo    $t2
        nop
        nop
        mult    $t0, $t3
        mflo    $t3
        addi    $t2, 12
        nop
        add     $t2, $t2, $t3

        sw      $t2, answer

        la      $a0, result
        li      $v0, 4
        syscall

        lw      $a0, answer
        li      $v0, 1
        syscall

        li      $v0, 10
        syscall

# End of file
