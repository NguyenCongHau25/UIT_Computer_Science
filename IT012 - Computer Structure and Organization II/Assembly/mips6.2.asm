.data
	a: .word 6
	b: .word 5
	c: .space 4
	d: .space 4
.text

	lw $t0, a
	lw $t1, b
	
	add $t2, $t0, $t1
	sub $t3, $t0, $t1
	
	sw $t2, c
	sw $t3, d
