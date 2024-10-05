    .data
array1: .word 5, 6, 7, 8, 1, 2, 3, 9, 10, 4
size1:  .word 10

array2: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
size2:  .word 16

array3: .space 32     # 8 words, mỗi word 4 bytes
size3:  .word 8

newline: .asciiz "\n"
space: .asciiz " "
out_of_bounds: .asciiz "Index out of bounds\n"
invalid_selection: .asciiz "Invalid selection\n"

    .text
    .globl main

main:
    # In các phần tử của array1
    la $t0, array1
    lw $t1, size1    
    li $t2, 0    

print_array1_loop:
    bge $t2, $t1, end_print_array1

    lw $a0, 0($t0)
    li $v0, 1
    syscall

    li $v0, 4       
    la $a0, space 
    syscall

    addi $t0, $t0, 4 
    addi $t2, $t2, 1
    j print_array1_loop

end_print_array1:
    li $v0, 4
    la $a0, newline
    syscall

    # In các phần tử của array2
    la $t0, array2
    lw $t1, size2    
    li $t2, 0    

print_array2_loop:
    bge $t2, $t1, end_print_array2

    lw $a0, 0($t0)
    li $v0, 1 
    syscall

    li $v0, 4   
    la $a0, space   
    syscall

    addi $t0, $t0, 4 
    addi $t2, $t2, 1
    j print_array2_loop

end_print_array2:
    li $v0, 4
    la $a0, newline
    syscall

    # Tính toán và in các phần tử của array3
    la $s0, array2       
    lw $s1, size2      
    la $s3, array3       
    lw $s4, size3       
    li $t0, 0            

compute_array3_loop:
    bge $t0, $s4, end_compute_array3   

    # Tính chỉ số cho array2
    lw  $t3, 0($s0)          # array2[i]
    sub $t4, $s1, $t0
    sub $t4, $t4, 1          # array2[size2 - 1 - i]
    sll $t4, $t4, 2          # Chuyển đổi sang byte offset
    add $t4, $t4, $s1     # Địa chỉ array2[size2 - 1 - i]
    lw  $t4, 0($t4)

    # Tính array3[i] = array2[i] + array2[size2 - 1 - i]
    add $t5, $t3, $t4

    # Lưu kết quả vào array3
    sw $t5, 0($s3)

    # Chuyển sang phần tử tiếp theo
    addi $s0, $s0, 4
    addi $t0, $t0, 1
    addi $s3, $s3, 4
    j compute_array3_loop

end_compute_array3:
    la $s3, array3   
    lw $s2, size3
    li $s4, 0    

print_array3_loop:
    bge $s4, $s2, end_print_array3

    lw $a0, 0($s3)
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, space
    syscall

    addi $s3, $s3, 4 
    addi $s4, $s4, 1
    j print_array3_loop

end_print_array3:
    li $v0, 4
    la $a0, newline
    syscall

    # Đọc giá trị m
    li $v0, 5
    syscall
    move $s0, $v0

    # Đọc giá trị n
    li $v0, 5
    syscall
    move $s1, $v0

    # Xử lý switch-case
    li $t7, 1
    beq $s0, $t7, case_A
    li $t7, 2
    beq $s0, $t7, case_B
    li $t7, 3
    beq $s0, $t7, case_C
    j default_case

case_A:
    # Kiểm tra chỉ số ngoài giới hạn cho array A
    li $t8, 10
    bgeu $s1, $t8, out_of_bounds_case
    la $t9, array1
    sll $t0, $s1, 2
    add $t9, $t9, $t0
    lw $a0, 0($t9)
    li $v0, 1
    syscall
    j exit

case_B: 
    # Kiểm tra chỉ số ngoài giới hạn cho array B
    li $t8, 16
    bgeu $s1, $t8, out_of_bounds_case
    la $t9, array2
    sll $t0, $s1, 2
    add $t9, $t9, $t0
    lw $a0, 0($t9)
    li $v0, 1
    syscall
    j exit

case_C:
    # Kiểm tra chỉ số ngoài giới hạn cho array C
    li $t8, 8
    bgeu $s1, $t8, out_of_bounds_case
    la $t9, array3
    sll $t0, $s1, 2
    add $t9, $t9, $t0
    lw $a0, 0($t9)
    li $v0, 1
    syscall
    j exit

out_of_bounds_case:
    li $v0, 4
    la $a0, out_of_bounds
    syscall
    j exit

default_case:
    li $v0, 4
    la $a0, invalid_selection
    syscall

exit:
    li $v0, 10
    syscall
