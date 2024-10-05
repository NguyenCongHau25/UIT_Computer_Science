-- I. Ngôn ngữ định nghĩa dữ liệu (Data Definition Language):
-- 2. Thêm vào thuộc tính GHICHU có kiểu dữ liệu varchar(20) cho quan hệ SANPHAM.

ALTER TABLE SANPHAM add GHICHU VARCHAR(20);

-- 3. Thêm vào thuộc tính LOAIKH có kiểu dữ liệu là tinyint cho quan hệ KHACHHANG.

ALTER TABLE KHACHHANG add LOAIKH TINYINT;

-- 4. Sửa kiểu dữ liệu của thuộc tính GHICHU trong quan hệ SANPHAM thành varchar(100).

ALTER table SANPHAM ALTER COLUMN GHICHU VARCHAR(100);

-- 5. Xóa thuộc tính GHICHU trong quan hệ SANPHAM.

ALTER TABLE SANPHAM DROP COLUMN GHICHU;

-- 6. Làm thế nào để thuộc tính LOAIKH trong quan hệ KHACHHANG có thể lưu các giá trị là: “Vang lai”, “Thuong xuyen”, “Vip”, …

ALTER TABLE KHACHHANG ALTER COLUMN LOAIKH varchar(30);

-- 7. Đơn vị tính của sản phẩm chỉ có thể là (“cay”,”hop”,”cai”,”quyen”,”chuc”)

ALTER TABLE SANPHAM ADD CHECK (DVT='cay' OR DVT='hop' OR DVT='cai' OR DVT='quyen' or DVT='chuc');

-- 8. Giá bán của sản phẩm từ 500 đồng trở lên.

ALTER TABLE SANPHAM  ADD CHECK (GIA >= 500);

-- 9. Mỗi lần mua hàng, khách hàng phải mua ít nhất 1 sản phẩm.

ALTER TABLE CTHD ADD CHECK (SL>=1);

-- 10. Ngày khách hàng đăng ký là khách hàng thành viên phải lớn hơn ngày sinh của người đó.

ALTER TABLE KHACHHANG ADD CHECK (NGDK>NGSINH);

-- II. Ngôn ngữ thao tác dữ liệu (Data Manipulation Language):
-- 2. Tạo quan hệ SANPHAM1 chứa toàn bộ dữ liệu của quan hệ SANPHAM. Tạo quan hệ KHACHHANG1 chứa toàn bộ dữ liệu của quan hệ KHACHHANG.

SELECT * INTO SANPHAM1 FROM SANPHAM;
SELECT * INTO KHACHHANG1 FROM KHACHHANG;

-- 3. Cập nhật giá tăng 5% đối với những sản phẩm do “Thai Lan” sản xuất (cho quan hệ SANPHAM1)

UPDATE SANPHAM1

SET GIA = GIA + 0.05*GIA

WHERE NUOCSX = 'Thai Lan'

-- 4. Cập nhật giá giảm 5% đối với những sản phẩm do “Trung Quoc” sản xuất có giá từ 10.000 trở xuống (cho quan hệ SANPHAM1).

UPDATE SANPHAM1

SET GIA = GIA - 0.05*GIA

WHERE NUOCSX = 'Trung Quoc' AND GIA <= 10000;


-- 5. Cập nhật giá trị LOAIKH là “Vip” đối với những khách hàng đăng ký thành viên trước 
-- ngày 1/1/2007 có doanh số từ 10.000.000 trở lên hoặc khách hàng đăng ký thành viên từ
-- 1/1/2007 trở về sau có doanh số từ 2.000.000 trở lên (cho quan hệ KHACHHANG1).

UPDATE KHACHHANG1
SET LOAIKH = 'Vip'
where (NGDK < '1/1/2007' and DOANHSO >= 10000000) or (NGDK >= '1/1/2007' and DOANHSO > 2000000);

