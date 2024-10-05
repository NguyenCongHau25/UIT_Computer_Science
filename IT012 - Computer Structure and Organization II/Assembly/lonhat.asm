.data
A:  .word 5, 1, 2, 4, 1, 0, 6, 9   # Mảng A
n:  .word 8                         # Kích thước mảng

.text
.globl main
main:
    la   $t0, A           # $t0 = địa chỉ của A
    lw   $t1, 0($t0)      # $t1 = A[0] (max ban đầu)
    lw   $t2, n           # $t2 = n (kích thước mảng)
    li   $t3, 1           # $t3 = i (chỉ số vòng lặp, bắt đầu từ 1)

loop:
    beq  $t3, $t2, end_loop # nếu i >= n thì thoát vòng lặp
    sll  $t4, $t3, 2        # $t4 = i * 4 (mỗi phần tử có kích thước 4 byte)
    add  $t4, $t4, $t0      # $t4 = địa chỉ của A[i]
    lw   $t5, 0($t4)        # $t5 = A[i]
    ble  $t1, $t5, update_max # nếu max < A[i] thì cập nhật max
    j    next

update_max:
    move $t1, $t5           # max = A[i]

next:
    addi $t3, $t3, 1        # i++
    j    loop

end_loop:
    li   $v0, 1             # syscall để in số nguyên
    move $a0, $t1           # chuyển max vào $a0 để in
    syscall

    li   $v0, 10            # syscall để thoát chương trình
    syscall