.data
buffer: .space 100  
newline: .asciiz "\n"   
Nhapchuoi: .asciiz "Nhap chuoi: \n"
.text

main:
	
    #Thong bao nhap chuoi
    li $v0, 4
    la $a0, Nhapchuoi
    syscall
    
    #Nhap vao chuoi
    li $v0, 8       
    la $a0, buffer     
    li $a1, 100         
    syscall             
    
    #Lay do dai cua chuoi
    la $s0, buffer      
    li $t0, 0           

Tim_Chieu_Dai:
    lb $t1, 0($s0)      #Lay dia chi nen cua chuoi 
    beq $t1, $zero, Ket_Thuc_Tim_Chieu_Dai #Neu ky tu roi thi ket thuc

    addi $s0, $s0, 1    #Ky tu tiep theo
    addi $t0, $t0, 1    #Tang bien dem
    j Tim_Chieu_Dai       

Ket_Thuc_Tim_Chieu_Dai:

    #In dao nguoc
    la $s0, buffer      # Lay dia chi nen cua chuoi
    add $s1, $s0, $t0   # Tro den cuoi chuoi
    addi $s1, $s1, -1   # Tro ky tu cuoi

In_Dao_Nguoc:
    blt $t0, 1, Ket_Thuc_In # i < 0, ket thuc

    #In chuoi 
    lb $a0, 0($s1)      
    li $v0, 11       
    syscall 

    addi $s1, $s1, -1   # Giam dia chi con tro xuong 1
    addi $t0, $t0, -1   # Tang bien dem
    j In_Dao_Nguoc     

Ket_Thuc_In:
    #Xuong dong
    li $v0, 4           
    la $a0, newline     
    syscall     

    # Ket thuc
    li $v0, 10          
    syscall  
