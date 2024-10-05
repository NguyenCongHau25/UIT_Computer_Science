#include <iostream>
#include <string>
using namespace std;

class CNhanVien
{
    protected:
        string HoTen;
        string NgaySinh;
        long Luong;
    public:
        CNhanVien()
        {
            HoTen = "";
            NgaySinh = "";
            Luong = 0;
        }

        CNhanVien(string _HoTen, string _NgaySinh, long _Luong)
        {
            HoTen = _HoTen;
            NgaySinh = _NgaySinh;
            Luong = _Luong;
        }

        ~CNhanVien(){}
        void NhapThongTin()
        {
            cout << "Nhap ho ten nhan vien: ";
            getline(cin, HoTen);

            cout << "Nhap ngay sinh nhan vien: ";
            getline(cin, NgaySinh);
        }
        
        void XuatThongTin()
        {
            cout << HoTen << "\t" << NgaySinh << "\t";
        }
        

        long getLuong()
        {
            return Luong;
        }
};

class CNhanVienSanXuat: public CNhanVien
{
    private:
        int SoSanPham;
        long LuongCoBan;
    public:
        CNhanVienSanXuat()
        {
            SoSanPham = 0;
            LuongCoBan = 0;
        }

        CNhanVienSanXuat(int _SoSanPham, long _LuongCoBan)
        {
            SoSanPham = _SoSanPham;
            LuongCoBan = _LuongCoBan;
        }
        ~CNhanVienSanXuat(){}

        void Nhap()
        {
            CNhanVien::NhapThongTin();
            cout << "Nhap so san pham: ";
            cin >> SoSanPham;
            cout << "Nhap luong co ban: ";
            cin >> LuongCoBan;
            cin.ignore();
        }

        void Xuat()
        {
            CNhanVien::XuatThongTin();
            cout << SoSanPham << "\t" << "\t" <<LuongCoBan << "\t" << TinhLuong() << endl;

        }

        long TinhLuong()
        {
            return Luong = LuongCoBan + SoSanPham*5000;
        }
};

class CNhanVienVanPhong: public CNhanVien
{
    private:
        int SoNgayLamViec;
    public:

        CNhanVienVanPhong()
        {
            SoNgayLamViec = 0;
        }

        CNhanVienVanPhong(int _SoNgayLamViec)
        {
            SoNgayLamViec = _SoNgayLamViec;
        }

        ~CNhanVienVanPhong(){}

        void Nhap()
        {
            CNhanVien::NhapThongTin();
            cout << "Nhap so ngay lam viec: ";
            cin >> SoNgayLamViec;
            cin.ignore();
        }

        void Xuat()
        {
            CNhanVien::XuatThongTin();
            cout << SoNgayLamViec << "\t" << TinhLuong() << endl;
        }

        long TinhLuong()
        {
           return Luong = SoNgayLamViec*100000; 
        }
};
class QuanLyNhanVien
{
    private:
        int SoNhanVienSanXuat;
        int SoNhanVienVanPhong;
        CNhanVienSanXuat *SX;
        CNhanVienVanPhong *VP;
    public:

        QuanLyNhanVien()
        {
            SoNhanVienSanXuat = 0;
            SoNhanVienVanPhong = 0;

            SX = new CNhanVienSanXuat[0];
            VP = new CNhanVienVanPhong[0];
        }

        QuanLyNhanVien(int _SoNhanVienSanXuat, int _SoNhanVienVanPhong)
        {
            SoNhanVienSanXuat = _SoNhanVienSanXuat;
            SoNhanVienVanPhong = _SoNhanVienVanPhong;

            SX = new CNhanVienSanXuat[SoNhanVienSanXuat];
            VP = new CNhanVienVanPhong[SoNhanVienVanPhong];
        }

        ~QuanLyNhanVien()
        {
            delete [] SX;
            delete [] VP;
        }

        void NhapThongTinNhanVien()
        {
            cout << "Nhap so nhan vien san xuat: ";
            cin >> SoNhanVienSanXuat;

            cout << "Nhap so nhan vien van phong: ";
            cin >> SoNhanVienVanPhong;

            cin.ignore();

            SX = new CNhanVienSanXuat[SoNhanVienSanXuat];
            VP = new CNhanVienVanPhong[SoNhanVienVanPhong];

            cout << "Nhap thong tin nhan vien san xuat: " << endl;
            for (int i = 0; i < SoNhanVienSanXuat; i++)
                SX[i].Nhap();

            cout << "Nhap thong tin nhan vien van phong: " <<  endl;
            for (int i = 0; i < SoNhanVienVanPhong; i++)
                VP[i].Nhap();

        }

        void TinhTongLuong()
        {
            long TongLuong = 0;
            for (int i = 0; i < SoNhanVienSanXuat; i++)
            {
                SX[i].TinhLuong();
                TongLuong += SX[i].getLuong();
            }

            for (int i = 0; i < SoNhanVienVanPhong; i++)
            {
                VP[i].TinhLuong();
                TongLuong += VP[i].getLuong();
            }

            cout << "Tong luong cong ty can phai tra: " << TongLuong;
        }

        void LuongCaoNhat()
        {
            CNhanVienVanPhong CaoNhatVP = VP[0];
            CNhanVienSanXuat CaoNhatSX = SX[0];
           
            for (int i = 1; i < SoNhanVienSanXuat; i++)
                if (SX[i].getLuong() > CaoNhatSX.getLuong())
                    CaoNhatSX = SX[i];

            for (int i = 1; i < SoNhanVienVanPhong; i++)
                if (VP[i].getLuong() > CaoNhatVP.getLuong())
                    CaoNhatVP = VP[i];

            cout << "\nNhan vien sx co luong cao nhat: " << endl;
                CaoNhatSX.XuatThongTin();
            cout << "\nNhan vien vp co luong cao nhat: " << endl;
                CaoNhatVP.XuatThongTin();
        }

        void LuongThapNhat()
        {
            CNhanVienVanPhong ThapNhatVP = VP[0];
            CNhanVienSanXuat ThapNhatSX = SX[0];
           
            for (int i = 1; i < SoNhanVienSanXuat; i++)
                if (SX[i].getLuong() < ThapNhatSX.getLuong())
                    ThapNhatSX = SX[i];

            for (int i = 1; i < SoNhanVienVanPhong; i++)
                if (VP[i].getLuong() < ThapNhatVP.getLuong())
                    ThapNhatVP = VP[i];

            cout << "\nNhan vien sx co luong thap nhat: " << endl;
                ThapNhatSX.Xuat();
            cout << "\nNhan vien vp co luong thap nhat: " << endl;
                ThapNhatVP.Xuat();
        }

        void XuatThongTinNhanVien()
        {
            cout << "Thong tin nhan vien san xuat: " << endl;
            for (int i = 0; i < SoNhanVienSanXuat; i++)
                SX[i].Xuat();

            cout << "Thong tin nhan vien van phong: " << endl;
            for (int i = 0; i < SoNhanVienVanPhong; i++)
                VP[i].Xuat();
        }
};

int main()
{
    QuanLyNhanVien UIT;
    UIT.NhapThongTinNhanVien();
    UIT.XuatThongTinNhanVien();
    UIT.TinhTongLuong();
    UIT.LuongCaoNhat();
    UIT.LuongThapNhat();

    return 0;
}