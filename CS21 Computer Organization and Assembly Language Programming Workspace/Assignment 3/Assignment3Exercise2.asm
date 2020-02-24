# Mahdi Khaliki
# Assignment 3 Exercise 2
# 3/10/2018

        .text
        .globl  main
main:
# Exercise 2
        li      $t0, 0          # Sum of evens
        li      $t1, 0          # Sum of odds
        li      $t2, 0          # Sum of all
        li      $t3, 1          # Counter
        li      $t4, 101        # End loop value

Sum:
        andi    $t5, $t3, 1
        beqz    $t5, AddEven
        nop
        add     $t1, $t1, $t3   # Add to odd

AddAll:
        add     $t2, $t2, $t3   # Add to all
        addi    $t3, $t3, 1     # Add to counter
        blt     $t3, $t4, Sum   # Loop
        nop
        li      $v0, 10
        syscall

AddEven:
        add     $t0, $t0, $t3   # Add to even
        b       AddAll
