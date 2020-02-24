## Mahdi Khaliki
## Assignment 8 Exercise 2
## 4/17/18

## $t0 = count
## $t1 = flag
## $t2 = index
## $t3 = 1000
## $f2 = sum
## $f3 = numerator
## $f4 = denominator
## $f5 = temp
## $f6 = 2.0 to add to denominator

        .data
array1: .space  40
array2: .space  40
output: .asciiz "Iterative           Recurrsive"

        .text
        .globl main
main:
        li      $t0, 0                  # $t0 = 0
        li      $t2, 0                  # $t2 = 0
        li      $t3, 1000               # $t3 = 1000
        li.s    $f2, 0.0                # $f2 = 0.0
        li.s    $f3, 4.0                # $f3 = 4.0
        li.s    $f4, -1.0               # $f4 = -1.0
        li.s    $f6, 2.0                # $f6 = 2.0
        la      $t4, array1             # Address of array1 for later use

iterative:
        beq     $t0, $t3, addToArray
        nop
        beq     $t0, 10000, end         # if count == 10000 end
        nop

        andi    $t1, $t0, 1
        addi    $t0, $t0, 1
        add.s   $f4, $f4, $f6           # denominator + 2.0
        beq     $t1, 0, addIter
        nop
        div.s   $f5, $f3, $f4
        sub.s   $f2, $f2, $f5
        b       iterative
        nop

addToArray:
        s.s     $f2, ($t4)
        addi    $t3, $t3, 1000
        addi    $t4, $t4, 4
        b       iterative
        nop

addIter:
        div.s   $f5, $f3, $f4
        add.s   $f2, $f2, $f5
        b       iterative
        nop

        end:
        la      $a0, output
        li      $v0, 4
        syscall

        la      $a0, 10
        li      $v0, 11
        syscall
        la      $t4, array1

        li      $t0, 0
        li.s    $f4, 1.0
        li.s    $f2, 0.0
        li      $t2, 0

        addiu   $sp, $sp, -4            # Push count param
        sw      $t0, ($sp)
        addiu   $sp, $sp, -4            # Push denominator param
        s.s     $f4, ($sp)
        addiu   $sp, $sp, -4            # Push sum param
        s.s     $f2, ($sp)
        addiu   $sp, $sp, -4            # Push array index param
        sw      $t2, ($sp)

        jal     recurrsion
        nop
        addi    $sp, $sp, 12            # Deallocated spaces for params

        la      $t5, array2
        li      $t2, 0

print:
        l.s     $f12, ($t4)
        nop
        li      $v0, 2
        syscall
        la      $a0, 9
        li      $v0, 11
        syscall
        li      $v0, 11
        syscall
        l.s     $f12, ($t5)
        nop
        li      $v0, 2
        syscall
        li      $a0, 10
        li      $v0, 11
        syscall

        addi    $t4, $t4, 4
        addi    $t5, $t5, 4
        addi    $t2, $t2, 1
        blt     $t2, 10, print
        nop

        li      $v0, 10                 # End program
        syscall

recurrsion:
        addiu   $sp, $sp, -4
        sw      $ra, ($sp)
        addiu   $sp, $sp, -4
        sw      $fp, ($sp)
        or      $fp, $zero, $sp         # initalize $fp

        la      $t6, array2             # Load array2 address
        lw      $t0, 20($fp)            # Load count into $t0
        l.s     $f2, 16($fp)            # Load denom into $f2
        l.s     $f3, 12($fp)            # Load sum into $f3
        lw      $t2, 8($fp)

        li.s    $f4, 4.0
        li      $t1, 1000
        div     $t0, $t1                # Check if at 1000, 2000, 3000...
        mfhi    $t1
        beq     $t1, 0, addToArray2
        nop

continue:
        beq     $t0, 10000, return
        nop
        andi    $t1, $t0, 1
        beq     $t1, 0, addRecur
        nop
        div.s   $f5, $f4, $f2
        sub.s   $f3, $f3, $f5
        b       call
        nop


addRecur:
        div.s   $f5, $f4, $f2                   # Add term
        add.s   $f3, $f3, $f5
        b       call
        nop

call:
        addi    $t0, $t0, 1
        li.s    $f5, 2.0
        add.s   $f2, $f2, $f5

        addiu   $sp, $sp, -4                    # Push params on stack
        sw      $t0, ($sp)
        addiu   $sp, $sp, -4
        s.s     $f2, ($sp)
        addiu   $sp, $sp, -4
        s.s     $f3, ($sp)
        addiu   $sp, $sp, -4
        sw      $t2, ($sp)

        jal     recurrsion
        nop
        addi    $sp, $sp, 16                    # Deallocate space for params
        b       return
        nop

return:
        lw      $fp, ($sp)                      # pop $fp and $ra
        addiu   $sp, $sp, 4
        lw      $ra, ($sp)
        addiu   $sp, $sp, 4
        jr      $ra
        nop

addToArray2:
        beq     $t0, 0, continue                # Save term to array
        nop
        add     $t6, $t6, $t2
        s.s     $f3, ($t6)
        addi    $t2, $t2, 4
        b       continue
        nop
