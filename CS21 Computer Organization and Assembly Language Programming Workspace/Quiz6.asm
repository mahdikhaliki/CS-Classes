## Mahdi Khaliki
## 
## 4/17/18

        .data
input:  .asciiz "Enter integer: "
output: .asciiz "The product = "

        .text
        .globl main
main:
        jal     getInt
        nop
        move    $t0, $v0
        li      $v0, 1
        jal     getInt
        nop
        move    $t1, $v0
        move    $a0, $t0
        move    $a1, $t1
        jal     multiply
        nop
        move    $a0, $v0
        jal     print
        nop

        li      $v0, 10
        syscall

getInt:
        la      $a0, input
        li      $v0, 4
        syscall
        li      $v0, 5
        syscall
        jr      $ra
        nop

multiply:
        mult    $a0, $a1
        mflo    $v0
        jr      $ra
        nop

print:
        move    $t0, $a0
        la      $a0, output
        li      $v0, 4
        syscall
        move    $a0, $t0
        li      $v0, 1
        syscall
        jr      $ra
        nop
