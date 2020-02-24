# Mahdi Khaliki
# Assignment 6 Exercise 2
# 3/26/18

        .data
prompt: .asciiz "Enter value: "
times:  .asciiz " * "
equals: .asciiz " = "
val1:   .float  0.0
val2:   .float  0.0

        .text
        .globl  main
main:
        li      $t0, 0                  # Count

loop:
        jal     input                   # Call input
        nop
        s.s     $f0, val1
        mov.s   $f12, $f0               # Move first argument to $f12
        jal     input                   # Call input
        nop
        s.s     $f0, val2
        mov.s   $f14, $f0               # Move second argument to $f14

        jal     multiply                # Call multiply
        nop
        mov.s   $f12, $f0               # Move arguments

        jal     print                   # Call print
        nop

        addi    $t0, $t0, 1             # loop
        blt     $t0, 10, loop
        nop

        li      $v0, 10                 # End program
        syscall

input:
        la      $a0, prompt             # Print prompt
        li      $v0, 4
        syscall
        li      $v0, 6                  # Read in float
        syscall
        jr      $ra                     # Jump to return address
        nop

multiply:
        mul.s   $f0, $f12, $f14         # Multiply arguments passed in
        jr      $ra
        nop

print:
        mov.s   $f11, $f12              # Move arument for later use
        l.s     $f12, val1
        li      $v0, 2                  # Print val1
        syscall

        la      $a0, times              # Print " * "
        li      $v0, 4
        syscall

        l.s     $f12, val2              # Print val2
        li      $v0, 2
        syscall

        la      $a0, equals             # Print " = "
        li      $v0, 4
        syscall

        mov.s   $f12, $f11              # Print result
        li      $v0, 2
        syscall

        li      $a0, '\n'               # Print newline
        li      $v0, 11
        syscall

        jr      $ra                     # Jump to return address
        nop
