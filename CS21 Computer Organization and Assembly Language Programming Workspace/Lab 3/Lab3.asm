# Lab 3
# Nathaniel Chou
# Mahdi Khaliki
# Farris Tang

	.data
prompt:	.asciiz	"\nInput a Value for x = "
result:	.asciiz	"\nResult = "
x:	.word 0
y:	.word 0

	.text
        .globl	main
main:
	la	$a0, prompt
	li	$v0, 4
	syscall

	li	$v0, 5
	syscall

	sw	$v0, x			#Variable x

	lw	$t0, x
	li	$t1, 4
	mult	$t0, $t1
	mflo	$t2
	nop
	nop
	addi	$t2, $t2, 2
	mult	$t2, $t0
	mflo	$t2
	nop
	nop
	addi	$t2, $t2, -5
	mult	$t2, $t0
	mflo	$t2
	nop
	nop
	addi	$t2, $t2, 3
	
	sw	$t2, y			#Variable y
	
	la	$a0, result
	li	$v0, 4
	syscall
	
	lw	$a0, y
	li	$v0, 1
	syscall
	
	li	$v0, 10		#Exit
	syscall
#End of File