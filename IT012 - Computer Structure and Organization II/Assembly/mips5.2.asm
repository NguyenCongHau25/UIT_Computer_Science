.data
array: .space 40 #Khai bao mang chua 10 phan tu nguyen, 40 byte
size:  .word 0

Nhapn: .asciiz "Nhap kich thuoc mang: "
Nhapmang: .asciiz "Nhap mang: "
Nhapm: .asciiz "Nhap vi tri can tim gia tri: "
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

#Lay dia chi mang, kich thuoc, i = 0
    la $t0, array
    lw $t1, size
    li $t2, 0
#In mang
print_array_loop:
    bge $t2, $t1, end_print_array

    lw $a0, 0($t0)
    li $v0, 1
    syscall
    
    li $v0, 4
    la $a0, space
    syscall
    
    addi $t0, $t0, 4
    addi $t2, $t2, 1
    j print_array_loop

end_print_array:
    li $v0, 4
    la $a0, newline
    syscall

#Tim gia tri lon nhat nho nhat
    la $t0, array
    lw $t1, 0($t0)      # Gan max = A[0]
    lw $t2, 0($t0)      # Gan min = A[0]
    
    lw $t3, size
    li $t4, 1
    
#tim max min
find_max_min_loop:
    bge $t4, $t3, end_find_max_min

    lw $t5, 4($t0)  #Gia tri A[i]
    blt $t1, $t5, update_max #Kiem tra neu lon hon thi gan max, nho hon thi kiem tra va gan min
    j check_min
#Cap nhat gia tri max
update_max:
    move $t1, $t5
    
check_min:
    bgt $t2, $t5, update_min
    j next_element
    
#Cap nhat gia tri min
update_min:
    move $t2, $t5

#Nhay den a[i++]
next_element:
    addi $t0, $t0, 4
    addi $t4, $t4, 1
    j find_max_min_loop

end_find_max_min:

    #In max
    move $a0, $t1
    li $v0, 1
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    #In min
    move $a0, $t2
    li $v0, 1
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    #Tin tong cac phan tu cua mang
    la $t0, array
    lw $t1, size
    li $t2, 0
    li $t3, 0

sum_array_loop:
    bge $t2, $t1, end_sum_array

    lw $t4, 0($t0)
    add $t3, $t3, $t4
    
    addi $t0, $t0, 4
    addi $t2, $t2, 1
    j sum_array_loop

end_sum_array:

    #In tong
    move $a0, $t3
    li $v0, 1
    syscall
    li $v0, 4
    la $a0, newline
    syscall

    #Thong bao nhap vi tri m
    li $v0, 4
    la $a0, Nhapm
    syscall
    
    #Nhap m
    li $v0, 5
    syscall
    move $s0, $v0

    #In ra gia tri tai vi tri m
    lw $t1, size
    bge $s0, $t1, error_case
    bltz $s0, error_case
    
    la $t2, array
    sll $t3, $s0, 2
    add $t2, $t2, $t3
    lw $a0, 0($t2)
    li $v0, 1
    syscall
    j exit

error_case:
    li $v0, 4
    la $a0, error_msg
    syscall
    j exit

exit:
    li $v0, 10
    syscall
