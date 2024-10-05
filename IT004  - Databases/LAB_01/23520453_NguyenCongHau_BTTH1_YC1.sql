CREATE DATABASE QuanLyKhachHang
USE QuanLyKhachHang

CREATE TABLE SACH
(
	MaSach char(5) PRIMARY KEY,
	TenSach NVARCHAR(20) NOT NULL,
	TheLoai NVARCHAR(50),
	NXB NVARCHAR(20)
)
 
CREATE TABLE KHACHHANG
(
	MaKH CHAR(5) PRIMARY KEY,
	HoaTen NVARCHAR(25),
	NgaySinh SMALLDATETIME,
	DiaChi NVARCHAR(50),
	SDT NVARCHAR(15),
	NgDK SMALLDATETIME,
)

create table PHIEUMUA
(
	MaPM CHAR(5) PRIMARY KEY,
	MaKH CHAR(5),
	NgayMua SMALLDATETIME,
	SoSachMua INT
)

alter table PHIEUMUA add constraint fk_pm_kh foreign key (MaKH) references KhachHang(MaKH)

CREATE TABLE CHITIET_PHIEUMUA
(
	MaSach CHAR(5),
	MaPM CHAR(5),
	constraint pk_ctpm primary key (MaSach, MaPM)
)