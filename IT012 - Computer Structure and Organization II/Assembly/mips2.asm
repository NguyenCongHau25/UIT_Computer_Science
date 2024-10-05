.data
buffer: .space 64
msg_input: .asciiz "Nhap chuoi: \n"
msg_output: .asciiz "Xuat chuoi: \n"
msg_input1: .asciiz "Nhap 2 so nguyen: \n"
msg_output1: .asciiz "Tong 2 so nguyen: \n"
string1: .asciiz "Chao ban! Ban la sinh vien nam thu may? \n"
string2: .asciiz "Hihi, minh la sinh vien nam thu 1 ^-^ \n"

	.text 
main:

#in chuoi 1
li $v0, 4
la $a0, string1
syscall

#in chuoi 2
li $v0, 4
la $a0, string2
syscall

#thong bao nhap chuoi
li $v0, 4
la $a0, msg_input
syscall

#nhap chuoi
li $v0, 8
la $a0, buffer
li $a1, 64
syscall

#thong bao xuat chuoi
li $v0, 4
la $a0, msg_output
syscall 

#xuat chuoi
li $v0, 4
la $a0, buffer
syscall 

#thong bao nhap so nguyen
la $a0, msg_input1
syscall

#nhap so nguyen 1
li $v0, 5
syscall
move $t0, $v0

#nhap so nguyen 2
li $v0, 5
syscall
move $t1, $v0

#tinh tong so nguyen
move $t2, $v0
addu $t0, $t0, $t1

#thong bao xuat tong 
li $v0, 4
la $a0, msg_output1
syscall

#in ket qua tong 2 so nguyen
move $a0, $t0
li $v0, 1
syscall

li $v0, 10
syscall