# Farris Tang and Mahdi Khaliki
# Lab 4
# 3/6/18

        .text
        .globl  main
main:
	li	$t9, 10	        # Hardcode value 10 for comparison in 3rd code
        li      $t0, 0          # fragment
        li      $t1, 0
	ble	$t0, $t1, setBto10
	nop
returnHere:
	li	$t1, 0	        # Set B back to 0
	bge	$t0, $t1, setAto20
	nop
        li      $t1, 10
returnHere1:
	li	$t0, 0	        # Set A back to 0
	blt	$t0, $t9, whileAisLessThan10
	nop

whileAisLessThan10:
	add     $t1, $t0, $t1
        addi    $t0, $t0, 1
        blt     $t0, $t9, whileAisLessThan10
	nop

	li	$t0, 0	        # This should set A and B back to 0 after while
	li	$t1, 0	        # loop is finished

DoWhileAisLessThan10:
        add     $t1, $t0, $t1
	addi    $t0, $t0, 1
	blt	$t0, $t9, DoWhileAisLessThan10

	li	$t0, 0  # For loop code fragment
	li	$t1, 0
forloop:
	beq	$t0, $t9, end
	nop
	add	$t1, $t0, $t1
	addi	$t0, $t0, 1
	b	forloop
	nop
end:
	li	$v0, 10
	syscall

setBto10:
	li	$t1, 10
	b	returnHere

setAto20:
	li	$t0, 20
	b	returnHere1
