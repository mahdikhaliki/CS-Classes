
        .data
string: .space 100
input:  .asciiz "Enter string: "

        .text
        .globl main
main:
        la      $a0, input
        li      $v0, 4
        syscall
        la      $a0, string
        li      $v0, 8
        syscall

        li      $t0, 0
        addiu   $sp, $sp, -4
        sw      $t0, ($sp)
        la      $t1, string

push:
        lb      $t0, ($t1)
        nop
        beq     $t0, 0, pop
        nop
        addiu   $sp, $sp, -4
        sw      $t0, ($sp)
        addi    $t1, $t1, 1
        b       push
        nop

pop:
        la      $t1, string
loop:
        lw      $t0, ($sp)
        addiu   $sp, $sp, 4
        sb      $t0, ($t1)
        addi    $t1, $t1, 1
        bne     $t0, 0, loop
        nop

        la      $a0, string
        li      $v0, 4
        syscall

        li      $v0, 10
        syscall

