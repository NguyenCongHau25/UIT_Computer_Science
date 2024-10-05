#Khai bao cac chuoi ky tu thong bao
.data
nhap: .asciiz "Nhap ky tu:"
thuong: .asciiz "\nKy tu thuong"
hoa: .asciiz "\nKy tu hoa"
so: .asciiz "\nKy tu so"
truoc: .asciiz "\nKy tu truoc: "
sau: .asciiz "\nKy tu sau: "
khongcotruoc: .asciiz "\nKhong co ky tu truoc"
khongcosau: .asciiz "\nKhong co ky tu sau"
invalid_type_msg: .asciiz "\nInvalid Type"

.text

main:
    # In ra chuoi "Nhap ky tu: "
    li $v0, 4
    la $a0, nhap
    syscall

    # Nhap ky tu tu nguoi dung
    li $v0, 12
    syscall

    # Luu ky tu vao thanh ghi $s0
    move $s0, $v0
    
check_so:
    # Kiem tra ky tu la chu so ('0' - '9')
    li $t0, '0'
    li $t1, '9'
    blt $s0, $t0, check_thuong
    bgt $s0, $t1, check_thuong
    # Thong bao neu ky tu la so
    li $v0, 4
    la $a0, so
    syscall
     
    #Kiem tra ky tu so khong co truoc
    sub $t6, $s0, 1
    blt $t6, $t0, khong_co_truoc_so
    
    #In ra ky tu so dung truoc 
    li $v0, 4
    la $a0, truoc
    syscall
    li $v0, 11
    move $a0, $t6
    syscall
    
    #Kiem tra ky tu so dung sau
    check_sau_so:
    add $t6, $s0, 1
    bgt $t6, $t1, khong_co_sau
    
    #In ra ky tu so dung sau
    li $v0, 4
    la $a0, sau
    syscall
    li $v0, 11
    move $a0, $t6
    syscall
    j ketthuc
    
check_thuong:
    # Kiem tra ky tu la chu thuong ('a' - 'z')
    li $t2, 'a'
    li $t3, 'z'
    blt $s0, $t2, check_hoa
    bgt $s0, $t3, check_hoa
    # In ra neu ky tu la ky tu thuong
    li $v0, 4
    la $a0, thuong
    syscall
    
    # Kiem tra ky tu thuong o truoc
    sub $t6, $s0, 1
    blt $t6, $t2, khong_co_truoc_thuong
    
    # In ra ky tu thuong o truoc
    li $v0, 4
    la $a0, truoc
    syscall
    li $v0, 11
    move $a0, $t6
    syscall
    
    #Kiem tra ky tu thuong o sau
    check_sau_thuong:
    add $t6, $s0, 1
    bgt $t6, $t3, khong_co_sau
   
    #In ra ky tu thuong o sau
    li $v0, 4
    la $a0, sau
    syscall
    li $v0, 11
    move $a0, $t6
    syscall
    j ketthuc
    
check_hoa:
    # Kiem tra ky tu la chu hoa ('A' - 'Z')
    li $t4, 'A'
    li $t5, 'Z'
    blt $s0, $t4, invalid_type
    bgt $s0, $t5, invalid_type
    
    # In ra neu ky tu la chu hoa
    li $v0, 4
    la $a0, hoa
    syscall
    
    #kiem tra ky tu hoa o truoc
    sub $t6, $s0, 1
    blt $t6, $t4, khong_co_truoc_hoa
    # In ra ky tu hoa o truoc
    li $v0, 4
    la $a0, truoc
    syscall
    li $v0, 11
    move $a0, $t6
    syscall
    # Kiem tra ky tu hoa o sau
    check_sau_hoa:
    add $t6, $s0, 1
    bgt $t6, $t5, khong_co_sau
    # In ra ky tu hoa o sau
    li $v0, 4
    la $a0, sau
    syscall
    li $v0, 11
    move $a0, $t6
    syscall
    j ketthuc

ketthuc:
    # Ket thuc chuong trinh
    li $v0, 10
    syscall

khong_co_truoc_so:
    # In ra thong bao khong co ky tu so truoc
    li $v0, 4
    la $a0, khongcotruoc
    syscall
    j check_sau_so
    
khong_co_truoc_thuong:
    # In ra thong bao khong co ky tu thuong truoc
    li $v0, 4
    la $a0, khongcotruoc
    syscall
    j check_sau_thuong

khong_co_truoc_hoa:
    # In ra thong bao khong co ky tu hoa truoc
    li $v0, 4
    la $a0, khongcotruoc
    syscall
    j check_sau_hoa

khong_co_sau:
    # In ra thong bao khong co ky tu sau
    li $v0, 4
    la $a0, khongcosau
    syscall
    j ketthuc

invalid_type:
    # In ra thong bao ky tu khong hop le
    li $v0, 4
    la $a0, invalid_type_msg
    syscall
    j ketthuc