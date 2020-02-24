# Mahdi Khaliki
# CS21 Assignment 1
# 2/14/18

    .text
    .globl main
main:
# Exercise 1
    ori $t0, $zero, 0x01
    ori $t1, $zero, 0x0
    or  $t1, $t0, $t1
    sll $t0, $t0, 2
    or  $t2, $t0, $t1
    or  $t0, $t0, $t2
    sll $t2, $t2, 4
    or  $t2, $t0, $t2
    or  $t1, $t1, $t2
    sll $t2, $t2, 8
    or  $t2, $t1, $t2
    or  $t0, $t0, $t2
    sll $t2, $t2, 16
    or  $t1, $t0, $t2

# Exercise 2
    ori $t0, $zero, 0x01
    ori $t1, $zero, 0x0
    sll $t1, $t0, 3
    or  $t2, $t0, $t1
    sll $t0, $t0, 6
    sll $t1, $t1, 2
    or  $t0, $t0, $t1
    or  $t2, $t0, $t2
    sll $t0, $t2, 8
    or  $t2, $t0, $t2
    sll $t0, $t2, 16
    or  $t1, $t0, $t2

# Exercise 3
    ori $t0, $zero, 0x01
    ori $t1, $zero, 0x0
    nor $t1, $t0, $t1
    or  $t1, $t0, $t1
