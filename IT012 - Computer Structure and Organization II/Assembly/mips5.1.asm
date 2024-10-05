	.data
array1: .word 5, 6, 7, 8, 1, 2, 3, 9, 10, 4
size1: 	.word 10

array2: .byte 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
size2: .word 16

array3: .space 8
size3: .word 8

Nhapm: .asciiz "Nhap mang can tim: "
Nhapn: .asciiz "Nhap vi tri n can tim: "
newline: .asciiz "\n"
space: .asciiz " "
out_of_bounds: .asciiz "Chi so ngoai gioi han\n"
invalid_selection: .asciiz "Lua chon khong phu hop\n"

	.text
main: 

#Lay dia chi nen cua mang, kich thuoc mang, vi tri i =  0
la $t0, array1
lw $t1, size1    
li $t2, 0    

#Vong lap for de in mang 
#so sanh neu dieu kien sai thi dung, mac khac thi thuc hien cau lenh in sau do tang gia tri i va a[i]
print_array1_loop:
    bge $t2, $t1, end_print_array1

    lw $a0, 0($t0)

    li $v0, 1
    syscall

    li $v0, 11       
    li $a0, ' ' 
    syscall

    addi $t0, $t0, 4 
    addi $t2, $t2, 1
    j print_array1_loop

end_print_array1:

#xuong dong
li $v0, 11
li $a0, '\n'
syscall

#Lay dia chi mang, kich thuoc mang, gia tri i = 0
la $s0, array2   
lw $s1, size2    
li $s2, 0    

#vong lap for de in ra mang 2
#so sanh dieu kien, neu sai thi ket thuc, nguoc lai thi in ra va tang gia tri i, b[i]
print_array2_loop:
    bge $s2, $s1, end_print_array2

    lb $a0, 0($s0)

    li $v0, 1 
    syscall

    li $v0, 11   
    li $a0, ' '   
    syscall

    addi $s0, $s0, 1 
    addi $s2, $s2, 1
    j print_array2_loop

end_print_array2:

#xuong dong
li $v0, 11
li $a0, '\n'
syscall

#Lay dia chi nen mang2, mang3, kich thuoc mang2, mang3, gia tri i = 0
la $s0, array2       
lw $s1, size2      
la $s3, array3       
lw $s4, size3       
li $t0, 0            

#vong lap de tinh gia tri va gan vao mang3
compute_array3_loop:
    # so sanh dieu kien vong lap for
    bge $t0, $s4, end_compute_array3   

    #Tinh toan gia tri array2[size2 - 1 - i]
    lb  $t3, 0($s0)       
    sub $t4, $s1, $t0     
    subi $t2, $t2, 1   

    # Tinh array3[i] = array2[i] + array2[size2 - 1 - i]
    add $t5, $t3, $t4

    # Luu vao mang 3
    sb $t5, 0($s3)

    # di chuyen den phan tu ke tiep
    addi $s0, $s0, 1
    addi $t0, $t0, 1
    addi $s3, $s3, 1
    j compute_array3_loop

end_compute_array3:

#Tuong tu in mang 1, mang 2
#Lay cac gia tri dia chi nen, kich thuong mang, bien i = 0
    la $s3, array3   
    lw $s2, size3
    li $s4, 0    
#Vong lap for in mang3
print_array3_loop:
    bge $s4, $s2, end_print_array3

    lb $a0, 0($s3)
    li $v0, 1
    syscall

    li $v0, 11
    li $a0, ' '
    syscall

    addi $s3, $s3, 1 
    addi $s4, $s4, 1
    j print_array3_loop

end_print_array3:

#in xuong dong
li $v0, 11
li $a0, '\n'
syscall
	
    #in thong bao nhap m
    li $v0, 4      
    la $a0, Nhapm 
    syscall           
    
    #Nhap gia tri m
    li $v0, 5        
    syscall        
    move $s0, $v0  
    
    #in thong bao nhap n
    li $v0, 4      
    la $a0, Nhapn
    syscall         
    
    #Nhap gia tri n
    li $v0, 5        
    syscall        
    move $s1, $v0  
	
    #Kiem tra dieu kien giong switch case 
    li $t7, 1        
    beq $s0, $t7, case_A
    li $t7, 2
    beq $s0, $t7, case_B
    li $t7, 3      
    beq $s0, $t7, case_C  
    j default_case

case_A:

    #Kiem tra chi so va in mang1
    li $t8, 10       #Kich thuoc mang1
    bgeu $s1, $t8, out_of_bounds_case  #Neu n>= 10 thi in thong bao khong hop le
    
    la $t9, array1        # Lay dia chi mang1
    sll $t0, $s1, 2  
    add $t9, $t9, $t0  #Lay dia chi array1[n]
    lw $a0, 0($t9)   # Lay gia tri array1[n]
    li $v0, 1      
    syscall          
    j exit          

case_B: 
    #Kiem tra chi so va in mang2
    li $t8, 16       #Kich thuoc mang2
    bgeu $s1, $t8, out_of_bounds_case  #Neu n >= 16 thi in thong bao khong hop le
    
    la $t9, array2       #Lay dia chi mang2
    add $t9, $t9, $s1  #tinh dia chi array2[n]
    lb $a0, 0($t9)   #Lay du lieu array2[n] vao thanh ghi $a0
    li $v0, 1     
    syscall       
    j exit           

case_C:
    #kiem tra chi so va in mang3
    li $t8, 8        #Kich thuoc mang3
    bgeu $s1, $t8, out_of_bounds_case  #Neu n >= 8 thi in ra thong bao khong hop le
    
    la $t9, array3        #Lay dia chi mang3

    add $t9, $t9, $s1  #Tinh dia chi array3[n]
    lb $a0, 0($t9)   #Lay gia tri array3[n]
    li $v0, 1     
    syscall
    j exit           

#in thong bao khong co vi tri phu hop
out_of_bounds_case:
    li $v0, 4      
    la $a0, out_of_bounds 
    syscall         
    j exit         

#in thong bao khong co mang phu hop
default_case:
    li $v0, 4        
    la $a0, invalid_selection 
    syscall        
    j exit   

exit:
    li $v0, 10    
    syscall
