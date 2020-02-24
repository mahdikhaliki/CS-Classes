# Mahdi Khaliki
# Assignment 6 Exercise 1
# 3/25/18

        .data
pa:     .asciiz "Please enter variable a: "
pb:     .asciiz "Please enter variable b: "
pc:     .asciiz "Please enter variable c: "
output: .asciiz "3ab - 2bc - 5a + 20ac - 16 = "

        .text
        .globl  main
main:
        la      $a0, pa                 # Prompt for input
        li      $v0, 4
        syscall
        li      $v0, 6
        syscall
        mov.s   $f2, $f0

        la      $a0, pb
        li      $v0, 4
        syscall
        li      $v0, 6
        syscall
        mov.s   $f1, $f0

        la      $a0, pc
        li      $v0, 4
        syscall
        li      $v0, 6
        syscall

        li.s    $f3, 3.0
        mul.s   $f3, $f3, $f2           # Multiply 3*a
        nop
        nop
        mul.s   $f3, $f3, $f1           # Multiply (3*a)*b
        addiu   $sp, $sp, -4
        s.s     $f3, ($sp)              # Save in stack

        li.s    $f3, 2.0
        mul.s   $f3, $f3, $f1           # Multiply 2*b
        nop
        nop
        mul.s   $f3, $f3, $f0           # Multiply (2*b)*c
        addiu   $sp, $sp, -4
        s.s     $f3, ($sp)

        li.s    $f3, 5.0                # Multiply 5*a
        mul.s   $f3, $f3, $f2
        addiu   $sp, $sp, -4
        s.s     $f3, ($sp)

        li.s    $f3, 20.0
        mul.s   $f3, $f3, $f2           # Multiply 20*a
        nop
        nop
        mul.s   $f3, $f3, $f0           # Multiply (20*a)*c

        li.s    $f2, -16.0              # Load -16
        add.s   $f3, $f3, $f2           # 20ac - 16

        l.s     $f2, ($sp)              # Load 5a
        addi    $sp, $sp, 4

        sub.s   $f3, $f3, $f2           # 20ac - 16 - 5a

        l.s     $f2, ($sp)              # Load 2bc
        addi    $sp, $sp, 4

        sub.s   $f3, $f3, $f2           # 20ac - 16 - 5a - 2bc

        l.s     $f2, ($sp)              # Load 3ab
        addi    $sp, $sp, 4

        add.s   $f3, $f3, $f2           # 20ac - 16 - 5a - 2bc + 3ab

        la      $a0, output             # Print equation
        li      $v0, 4
        syscall

        mov.s   $f12, $f3               # Print result
        li      $v0, 2
        syscall

        li      $v0, 10                 # End program
        syscall
