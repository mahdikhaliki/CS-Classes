
        .data
str:    .asciiz  "The quick brown fox jumps over a lazy dog"

        .text
        .globl  main
main:
        li      $t0, 0                  # Beginning index
        li      $t1, 0                  # End index
        li      $t2, 0

        li      $v0, 4
        la      $a0, str
        syscall

FindEnd:
        addi    $t1, $t1, 1             
        lb      $t2, str($t1)
        nop
        bne     $t2, 0, FindEnd
        nop
        addi    $t1, $t1, -1
                                        # $t1 at end, $t0 at beginning
reverse:
        lb      $t2, str($t0)           # Char at beg
        nop
        lb      $t3, str($t1)           # Char at end
        nop
        sb      $t2, str($t1)           # Store at lower and upper index
        sb      $t3, str($t0)
        addi    $t0, $t0, 1             # Increment and decrement
        addi    $t1, $t1, -1
        ble     $t0, $t1, reverse
        nop

        li      $a0, 10                 # Print new line
        li      $v0, 11
        syscall


        la      $a0, str                # Print new string
        li      $v0, 4
        syscall

        li      $v0, 10                 # End program
        syscall

