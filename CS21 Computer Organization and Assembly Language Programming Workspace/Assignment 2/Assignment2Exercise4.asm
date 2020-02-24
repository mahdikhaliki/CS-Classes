
        .text
        .globl  main
main:

# Exercise 4
        ori     $t0, $zero, 0x186A
        sll     $t0, $t0, 8
        ori     $t1, $zero, 0x1388
        sll     $t1, $t1, 4
        ori     $t2, $zero, 0x61A8
        sll     $t2, $t2, 4
        div     $t0, $t2
        mflo    $t0
        mult    $t0, $t1
        mflo    $t0          

# End of file
