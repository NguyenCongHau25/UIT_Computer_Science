.data
 	i: .word 0
 	j: .word 0
 	f: .word 0
.text
	lw $s3, i
	lw $s4, j
	
	bne $s3, $s4, else
	add $s0, $s1, $s2
	j end
else: 
	sub $s0, $s1, $s2
end: 
	sw $s0, f
