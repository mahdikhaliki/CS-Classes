## Mahdi Khaliki
## Factorial
## 4/17/18

        .data
input:  .asciiz "Enter value for factorial: "
out1:   .asciiz "Factorial of "
out2:   .asciiz " = "
n:      .word 0

        .text
        .globl main
main:
        la      $a0, input
        li      $v0, 4
        syscall
        li      $v0, 5
        syscall
        sw      $v0, n
        addiu   $sp, $sp, -4
        sw      $v0, ($sp)

        jal     fact
        nop

        addiu   $sp, $sp, 4
        move    $t0, $v0
        la      $a0, out1
        li      $v0, 4
        syscall
        lw      $a0, n
        nop
        li      $v0, 1
        syscall
        la      $a0, out2
        li      $v0, 4
        syscall
        move    $a0, $t0
        li      $v0, 1
        syscall

        li      $v0, 10
        syscall

fact:
        addiu   $sp, $sp, -4
        sw      $ra, ($sp)
        addiu   $sp, $sp, -4
        sw      $fp, ($sp)
        or      $fp, $zero, $sp

        lw      $v0, 8($fp)
        ble     $v0, 1, return

        addiu   $v0, $v0, -1
        addiu   $sp, $sp, -4
        sw      $v0, ($sp)
        jal     fact

        addiu   $sp, $sp, 4

        lw      $t0, 8($fp)
        mult    $v0, $t0
        mflo    $v0

return:
        lw      $fp, ($sp)
        addi    $sp, $sp, 4
        lw      $ra, ($sp)
        addi    $sp, $sp, 4
        jr      $ra
        nop
