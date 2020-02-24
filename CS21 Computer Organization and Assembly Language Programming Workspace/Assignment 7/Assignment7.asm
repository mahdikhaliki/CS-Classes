## Mahdi Khaliki
## Assignment 7
## 4/14/18

## $f0 - $f1 = return value
## $f4 = x1
## $f5 = y1
## $f6 = x2
## $f7 = y2
## $f16 - $f19 = argument

        .data
px1:    .asciiz "Enter x1 coordinate: "
py1:    .asciiz "Enter y1 coordinate: "
px2:    .asciiz "Enter x2 coordinate: "
py2:    .asciiz "Enter y2 coordinate: "
result: .asciiz "The distance between the 2 points is: "

        .text
        .globl main
main:
        la      $a0, px1
        jal     prompt
        nop
        mov.s   $f4, $f0
        la      $a0, py1
        jal     prompt
        nop
        mov.s   $f5, $f0
        la      $a0, px2
        jal     prompt
        nop
        mov.s   $f6, $f0
        la      $a0, py2
        jal     prompt
        nop
        mov.s   $f7, $f0


        sub.s   $f4, $f6, $f4           # x2-x1
        mul.s   $f4, $f4, $f4           # x^2
        nop
        nop
        sub.s   $f5, $f7, $f5           # y2-y1
        mul.s   $f5, $f5, $f5           # y^2

        add.s   $f16, $f4, $f5          # deltaX^2 + deltaY^2

        jal     sqrt                    # Call sqrt(n) function
        nop

        mov.s   $f12, $f0
        la      $a0, result             # print results
        li      $v0, 4
        syscall
        li      $v0, 2
        syscall

        li      $v0, 10                 # End program
        syscall

prompt:
        li      $v0, 4
        syscall
        li      $v0, 6
        syscall
        jr      $ra
        nop

sqrt:
        mov.s   $f0, $f16
        li.s    $f12, 1.0               # constant 1.0
        li.s    $f2, 2.0                # constant 2.0
        li.s    $f4, 1.0                # x == first approx. (a guess, and 1.0 is close enough)
        li.s    $f10, 1.0e-5            # five figure accuracy

loop:
        mov.s   $f6, $f0                # x' = n
        div.s   $f6, $f6, $f4           # x' = n/x
        add.s   $f6, $f4, $f6           # x' = x + n/x
        div.s   $f4, $f6, $f2           # x  = (1/2)(x + n/x)

        mul.s   $f8, $f4, $f4           # check: x^2
        div.s   $f8, $f0, $f8           # n/x^2
        sub.s   $f8, $f8, $f12          # n/x^2 - 1.0
        abs.s   $f8, $f8                # |n/x^2 - 1.0|
        c.lt.s  $f8, $f10               # |x^2 - n| < small ?
        bc1f    loop
        nop
        mov.s   $f0, $f4
        jr      $ra
        nop
