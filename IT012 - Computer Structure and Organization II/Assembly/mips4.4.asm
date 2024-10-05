	.data
msg_input1: .asciiz "Nhap a: \n"
msg_input2: .asciiz "Nhap b:\n"
lonhon: .asciiz "\nSo lon hon: "
tong: .asciiz "\nTong a va b: "
hieu: .asciiz "\nHieu a va b: "
tich: .asciiz "\nTich a va b: "
thuong: .asciiz "\nThuong a va b: "
khong_chia_duoc: .asciiz "\nLoi phep chia"
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

#nhap so nguyen b
li $v0, 5
syscall
move $t1, $v0

# In so lon hon
lon_hon:
move $s0, $t0
bgt $s0, $t1, greater

move $s0, $t1
greater:
li $v0, 4
la $a0, lonhon
syscall
move $a0, $s0
li $v0, 1
syscall

tinh:

#tinh tong so nguyen
add $s0, $t0, $t1

#in ket qua tong 2 so nguyen
li $v0, 4
la $a0, tong
syscall
move $a0, $s0
li $v0, 1
syscall

#tinh hieu so nguyen
sub $s1, $t0, $t1

#in ket qua hieu 2 so nguyen
li $v0, 4
la $a0, hieu
syscall
move $a0, $s1
li $v0, 1
syscall

#tinh tich 2 so nguyen
mul $s2, $t0, $t1

#thong bao nhap so nguyen a
li $v0, 4
la $a0, tich
syscall
move $a0, $s2
li $v0, 1
syscall

#tin thuong hai so nguyen
beqz $t1, khong_chia
div $s3, $t0, $t1
li $v0, 4
la $a0, thuong
syscall
move $a0, $s3
li $v0, 1
syscall
j exit

khong_chia:
li $v0, 4
la $a0, khong_chia_duoc
syscall

exit:

