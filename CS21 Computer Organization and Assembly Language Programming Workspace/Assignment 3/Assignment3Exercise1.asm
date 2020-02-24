# Mahdi Khaliki
# Assignment 3 Exercise 1
# 3/10/2018

        .text
        .globl  main
main:
# Exercise 1
        li      $t0, 0
        li      $t1, 1
        li      $t2, 101

Sum:
        add     $t0, $t0, $t1
        addi    $t1, $t1, 1
        blt     $t1, $t2, Sum
        nop

        li      $v0, 10
        syscall
