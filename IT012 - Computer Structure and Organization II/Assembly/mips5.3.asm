.data
array: .space 40 #Khai bao mang chua 10 phan tu nguyen, 40 byte
size:  .word 0

Nhapn: .asciiz "Nhap kich thuoc mang: "
Nhapmang: .asciiz "Nhap mang: "
Nhapi: .asciiz "Nhap i: "
Nhapj: .asciiz "Nhap j: "
newline: .asciiz "\n"
space: .asciiz " "
error_msg: .asciiz "Error!\n"

.text

main:

    #in thong bao nhap m
    li $v0, 4      
    la $a0, Nhapn
    syscall  
     
    #Doc gia tri kich thuoc mang
    li $v0, 5
    syscall
    sw $v0, size
    
    #Lay dia chi nen, kich thuoc mang va vi tri i
    la $t0, array
    lw $t1, size
    li $t2, 0
    
    #Thong bao nhap mang
    li $v0, 4      
    la $a0, Nhapmang
    syscall   

#Nhap mang 
read_array_loop:
    bge $t2, $t1, end_read_array

    li $v0, 5
    syscall
    sw $v0, 0($t0)
    
    addi $t0, $t0, 4
    addi $t2, $t2, 1
    j read_array_loop

end_read_array:

#Lay dia chi, kich thuoc, i = 0
    la $s0, array
    lw $t1, size
    li $t2, 0

#In mang
print_array_loop:
    bge $t2, $t1, end_print_array

    lw $a0, 0($s0)
    li $v0, 1
    syscall
    
    li $v0, 4
    la $a0, space
    syscall
    
    addi $s0, $s0, 4
    addi $t2, $t2, 1
    j print_array_loop

end_print_array:
    li $v0, 4
    la $a0, newline
    syscall

#Thong bao nhap i
    li $v0, 4
    la $a0, Nhapi
    syscall 
    
#Nhap gia tri i
    li $v0, 5
    syscall
    move $s0, $v0
    
# Thong bao nhap j
    li $v0, 4
    la $a0, Nhapj
    syscall
       
#Nhap gia tri j
    li $v0, 5
    syscall
    move $s1, $v0

#Chuyen cau lenh C
	blt $s0, $s1, if_true #Kiem tra dieu kien i < j
	
if_false:
    # else A[i] = j;
    sll $t0, $s0, 2      # t0 = i * 4
    la $t1, array        # t1 = &A
    add $t1, $t1, $t0    # t1 = &A[i]
    sw $s1, 0($t1)       # A[i] = j
    j end_if

if_true:
    # A[i] = i;
    sll $t0, $s0, 2      # t0 = i * 4
    la $t1, array        # t1 = &A
    add $t1, $t1, $t0    # t1 = &A[i]
    sw $s0, 0($t1)       # A[i] = i

end_if:

    #Tinh A[i]
    sll $t0, $s0, 2      # t0 = i * 4
    la $t1, array        # t1 = &A
    add $t1, $t1, $t0    # t1 = &A[i]
    lw $a0, 0($t1)       # $a0 = A[i]
    li $v0, 1           
    syscall

    #Xuong dong
    li $v0, 4
    la $a0, newline
    syscall
    
 #Lay dia chi mang, kich thuoc, i = 0
    la $s0, array
    lw $t1, size
    li $t2, 0

#vong lap in mang
print_array_loop1:
    bge $t2, $t1, end_print_array1

    lw $a0, 0($s0)
    li $v0, 1
    syscall
    
    li $v0, 4
    la $a0, space
    syscall
    
    addi $s0, $s0, 4
    addi $t2, $t2, 1
    j print_array_loop1

end_print_array1:
    li $v0, 4
    la $a0, newline
    syscall
    
exit:
    li $v0, 10
    syscall
