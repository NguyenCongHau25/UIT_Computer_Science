
#Khoi tao gia tri cho cac thanh ghi
addi $s0, $0, 1
addi $s1, $0, 2
addi $t0, $0, 6
addi $t1, $0, 5

#Dung bne de kiem tra dieu kien khong bang nhau
#Neu $s0 va $s1 khong bang nhau se thuc hien cau lenh trong nhan else
#Neu $s0 va $s1 bang nhau se thuc hien cau lenh o nhan tiep theo la if
	bne $s0, $s1, else
if: 
	add $s2, $t0, $t1
	j exit
else: 
	sub $s2, $t0, $t1
exit: 
	
