
        .text
        .globl  main
main:

# Exercise 1
        li      $t0, 456   
        li      $t1, -229  
        li      $t2, 325  
        li      $t3, -552 
        add     $t0, $t0, $t1
        add     $t0, $t0, $t2
        add     $t0, $t0, $t3 

# Exercise 2
        li      $t0, 0
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096
        addi    $t0, 4096  

        li      $t1, 4096
        sll     $t1, $t1, 4 

        li      $t2, 4096
        add     $t2, $t2, $t2
        add     $t2, $t2, $t2
        add     $t2, $t2, $t2
        add     $t2, $t2, $t2 

# Exercise 3
        li      $t1, 0x7000
        sll     $t1, $t1, 16
        addu    $t1, $t1, $t1 

        li      $t2, 0x7000
        sll     $t2, $t2, 16
        add     $t2, $t2, $t2

# End of file
