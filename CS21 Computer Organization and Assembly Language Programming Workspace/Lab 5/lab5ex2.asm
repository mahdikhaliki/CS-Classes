
	.data
space:	.asciiz " "
size:	.word 12
array:	.word 50, 53, 52, 49, 48, 51, 99, 45, 53, 47, 47, 50
result:	.word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

# $t0 = counter
# $t1 = left
# $t2 = middle
# $t3 = right
# $t4 = hold average of left middle right
# $t5 = the constant value 3 (for dividing)

	.text
	.globl	main
main:
	li	$t0, 0
	li	$t5, 3
loop:
	beq	$t0, 0, noavg		#no average needed(first element)
	nop
	beq	$t0, 44, noavg		#no average needed(last element)
	nop
	bge	$t0, 48, printoutresult
	nop
	addi	$t0, $t0, -4
	lw	$t1, array($t0)
	addi	$t0, $t0, 4
	lw	$t2, array($t0)
	nop
	addi	$t0, $t0, 4
	lw	$t3, array($t0)
	nop
	add	$t4, $t1, $t2
	add	$t4, $t4, $t3
	div	$t4, $t5
	mflo	$t4
	addi	$t0, $t0, -4
	sw	$t4, result($t0)
	addi	$t0, $t0, 4
	j	loop
	nop

noavg:
	lw	$t1, array($t0)
	nop
	sw	$t1, result($t0)
	addi	$t0, $t0, 4
	j	loop
	nop	

printoutresult:
	li	$t0, 0
froop:
        addi    $t8, $t8, 1
	beq	$t0, 48, end
	lw	$t1, result($t0)
	nop
	or	$a0, $t1, $zero
	li	$v0, 1
	syscall
	addi	$t0, $t0, 4

	la	$a0, space
	li	$v0, 4
	syscall
	j	froop

end:
	li	$v0, 10
	syscall
