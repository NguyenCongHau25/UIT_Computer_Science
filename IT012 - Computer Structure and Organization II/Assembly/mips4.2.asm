#Khoi tao gia tri cho cac thanh ghi	
	li $s2, 0
	addi $s0, $0, 1
	addi $s1, $0, 5
#Cau lenh lap:
#Kiem tra neu $s0 lon hon $s1 se ket thuc chuong trinh
#Nguoc lai se thuc hien cau lenh tinh tong, tang gia tri i va lap lai
loop:		bgt  $s0, $s1, exit 
		add $s2, $s2, $s0
		addi $s0, $s0, 1
		j loop

exit:
