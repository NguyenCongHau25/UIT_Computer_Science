.data
array: .space 40
size:  .word 0

Nhapn: .asciiz "Nhap vao kich thuoc mang: "
Nhapmang: .asciiz "Nhap mang: \n"
xuat_td: .asciiz "Mang tang dan: "
xuat_gd: .asciiz "Mang giam dan: "
newline: .asciiz "\n"
space: .asciiz " "
error_msg: .asciiz "Error!\n"

.text

main:

    #Thong bao nhap kich thuoc mang
    li $v0, 4
    la $a0, Nhapn
    syscall
    
    #Nhap n
    li $v0, 5
    syscall
    sw $v0, size
    
    #Thong bao nhap mang
    li $v0, 4
    la $a0, Nhapmang
    syscall
    
    #Lay dia chi nen, kich thuoc mang, i = 0
    la $s0, array
    lw $t0, size
    li $t2, 0
#Nhap mang   
read_array_loop:
    bge $t2, $t0, end_read_array

    li $v0, 5
    syscall
    sw $v0, 0($s0)
    
    addi $s0, $s0, 4
    addi $t2, $t2, 1
    j read_array_loop

end_read_array:

#Lay dia chi nen, kich thuoc mang, i = 0
    la $s0, array
    lw $t1, size
    li $t2, 0

# Sap xep mang theo thu tu tang dan
		add $t1, $s0, $0		# t1 = dia chi cua arr[0]
		sub $t2, $t0, 1
		sll $t2, $t2, 2
		add $t2, $s0, $t2  		# t2 = dia chi cua arr[n-1]
loop5:	
		bge $t1, $t2, endloop5
		addi $t3, $t1, 4		# $t3 = dia chi cua arr[i+1] (arr[j])
		sll $t4, $t0, 2
		add $t4, $s0, $t4 		# $t4 = dia chi cua arr[n]
loop5_1:
		bge $t3, $t4, endloop5_1
		lw $s1, 0($t1)			# arr[i]
		lw $s2, 0($t3)			# arr[j]
		bgt $s2, $s1, continue3
		
		add $s3, $s1, $0
		sw $s2, 0($t1)
		sw $s3, 0($t3)
continue3:
		addi $t3, $t3, 4
		j loop5_1
endloop5_1:
		addi $t1, $t1, 4
		j loop5
endloop5:
		# Xuat mang vua sap xep tang dan
		li $v0, 4
		la $a0, xuat_td
		syscall
		
		add $t1, $s0, $0		# t1 = dia chi cua arr[0]
		sll $t2, $t0, 2
		add $t2, $s0, $t2  		# t2 = dia chi cua arr[n]
loop6:	
		bge $t1, $t2, endloop6
		lw $t3, 0($t1)			# $t3 = arr[i]
		
		li $v0, 1
		move $a0, $t3
		syscall
		
		li $v0, 4
		la $a0, space
		syscall
		
		addi $t1, $t1, 4
		j loop6
		
endloop6:

		#Xuong dong
		li $v0, 4
		la $a0, newline
		syscall
		
		# Xuat mang theo thu tu giam dan
		li $v0, 4
		la $a0, xuat_gd
		syscall
		
		sub $t1, $t0, 1
		sll $t1, $t1, 2
		add $t1, $s0, $t1  		# t1 = dia chi cua arr[n -1]
		add $t2, $s0, $0		# t2 = dia chi cua arr[0]
loop7:	
		blt $t1, $t2, EXIT
		lw $t3, 0($t1)			# $t3 = arr[i]
		
		li $v0, 1
		move $a0, $t3
		syscall
	
		li $v0, 4
		la $a0, space
		syscall
		
		addi $t1, $t1, -4
		j loop7
EXIT: