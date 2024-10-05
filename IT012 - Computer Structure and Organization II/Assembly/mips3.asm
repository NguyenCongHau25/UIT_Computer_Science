	.data
msg_input1: .asciiz "Nhap a: \n"
msg_input2: .asciiz "Nhap b:\n"
msg_output: .asciiz "Tong hai so nguyen la: \n"
buffer: .space 64

	.text
main:
#thong bao nhap so nguyen a
li $v0, 4
la $a0, msg_input1
syscall

#nhap so nguyen a
li $v0, 5
syscall
move $t0, $v0

#thong bao nhap so nguyen b
li $v0, 4
la $a0, msg_input2
syscall

#nhap so nguyen 2
li $v0, 5
syscall
move $t1, $v0

#tinh tong so nguyen
move $t2, $v0
addu $t0, $t0, $t1

#thong bao xuat tong 
li $v0, 4
la $a0, msg_output
syscall

#in ket qua tong 2 so nguyen
move $a0, $t0
li $v0, 1
syscall
