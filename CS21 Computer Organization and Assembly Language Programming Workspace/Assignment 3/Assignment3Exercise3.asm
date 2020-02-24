# Mahdi Khaliki
# Assignment 3 Exercise 3
# 3/10/2018

        .text
        .globl  main
main:
# Exercise 3
        li      $t0, 0          # 1st term
        li      $t1, 1          # 2st term
        li      $t2, 0          # Sum
        li      $t3, 1          # Counter
        li      $t4, 101        # End loop

Fibonacci:
        add     $t2, $t0, $t1
        or      $t0, $zero, $t1
        or      $t1, $zero, $t2
        addi    $t3, 1
        blt     $t3, $t4, Fibonacci
        nop

        li $v0, 10
        syscall
