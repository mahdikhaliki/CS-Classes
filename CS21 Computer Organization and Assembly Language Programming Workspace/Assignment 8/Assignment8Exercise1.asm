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
        addiu   $sp, $sp, -4            # Push $ra onto stack
        sw      $ra, ($sp)
        addiu   $sp, $sp, -4            # Push $fp onto stack
        sw      $fp, ($sp)

        addiu   $fp, $sp, -8            # Initializing frame pointer
        or      $sp, $zero, $fp         # $sp = $fp

        lw      $s0, 12($fp)            # Load n into register $s0
        nop
        ble     $s0, 0, return0         # Return 0 if n <= 0
        nop
        beq     $s0, 1, return1         # Return 1 if n == 1
        nop

        addiu   $s1, $s0, -1            # n - 1
        addiu   $sp, $sp, -4            # Push parameter n onto stack
        sw      $s1, ($sp)
        jal     fib                     # Call fib
        nop
        sw      $v0, 4($fp)             # Push x = fib(n - 1) on stack

        lw      $s0, 12($fp)            # Load n into register $s0
        addiu   $s2, $s0, -2            # n - 2
        addiu   $sp, $sp, -4            # Push parameter n onto stack
        sw      $s2, ($sp)
        jal     fib                     # Call fib
        nop
        sw      $v0, ($fp)              # Push y = fib(n - 2) on stack

        lw      $s1, 4($fp)             # Load x into $s1
        lw      $s2, ($fp)              # Load y into $s2
        nop
        add     $v0, $s1, $s2           # x + y into $v0

        addiu   $sp, $fp, 8             # $sp = $fp + space_for_variables

        lw      $fp, ($sp)              # Pop caller's frame pointer
        addiu   $sp, $sp, 4
        lw      $ra, ($sp)              # Pop $ra
        addiu   $sp, $sp, 4
        jr      $ra                     # Return to caller with $ra
        nop

return0:
        li      $v0, 0                  # Load 0 into return value

        addiu   $sp, $fp, 8             # $sp = $fp + variable space + $s registers used

        lw      $fp, ($sp)              # Pop caller's frame pointer
        addiu   $sp, $sp, 4
        lw      $ra, ($sp)              # Pop $ra
        addiu   $sp, $sp, 4
        jr      $ra                     # Return to caller with $ra
        nop

return1:
        li      $v0, 1                  # Load 0 into return value

        addiu   $sp, $fp, 8             # $sp = $fp + variable space + $s registers used

        lw      $fp, ($sp)              # Pop caller's frame pointer
        addiu   $sp, $sp, 4
        lw      $ra, ($sp)              # Pop $ra
        addiu   $sp, $sp, 4
        jr      $ra                     # Return to caller with $ra
        nop
