## Mahdi Khaliki
## Assignment 8 Exercise 1
## 4/17/18

        .data
input:  .asciiz "Enter value for Fibonacci: "
output: .asciiz "Fibonacci = "

        .text
        .globl main
main:
        la      $a0, input              # Get input
        li      $v0, 4
        syscall
        li      $v0, 5
        syscall

        addiu   $sp, $sp, -4            # Push parameter onto stack
        sw      $v0, ($sp)

        jal     fib                     # Call fib
        nop

        addiu   $sp, $sp, 4             # Deallocate space for parameter

        move    $t0, $v0

        la      $a0, output             # Print output
        li      $v0, 4
        syscall
        move    $a0, $t0
        li      $v0, 1
        syscall

        li      $v0, 10                 # End program
        syscall

fib:
        addiu   $sp, $sp, -4
        sw      $ra, ($sp)
        addiu   $sp, $sp, -4
        sw      $fp, ($sp)
        addiu   $fp, $sp, -8
        or      $sp, $zero, $fp

        lw      $v0, 16($fp)
        ble     $v0, 0, return0
        beq     $v0, 1, return

        addiu   $v0, $v0, -1
        addiu   $sp, $sp, -4
        sw      $v0, ($sp)
        jal     fib

        lw      $t0, ($sp)
        addiu   $sp, $sp, 4
        sw      $v0, 4($fp)
        addiu   $t0, $t0, -1
        addiu   $sp, $sp, -4
        sw      $t0, ($sp)
        jal     fib

        addiu   $sp, $sp, 4
        lw      $t0, 4($fp)
        add     $v0, $t0, $v0
return:
        addiu   $sp, $sp, 8
        lw      $fp, ($sp)
        addiu   $sp, $sp, 4
        lw      $ra, ($sp)
        addiu   $sp, $sp, 4
        jr      $ra

return0:
        li      $v0, 0
        b       return
