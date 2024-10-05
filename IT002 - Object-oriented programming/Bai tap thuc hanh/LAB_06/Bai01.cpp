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
        
        virtual ~CNhanVien(){}

        virtual void Nhap()
        {
            cout << "Nhap ho ten nhan vien: ";
            getline(cin, HoTen);

            cout << "Nhap ngay sinh nhan vien: ";
            getline(cin, NgaySinh);

        }
        
        virtual void Xuat()
        {
            cout << HoTen << "\t" << NgaySinh << "\t";
        }
        
        virtual long TinhLuong() = 0;
        virtual long GetLuong()
        {
            return Luong;
        }      
};

class CNhanVienSanXuat: public CNhanVien
{
    private:
        int SoSanPham;
        int LuongCoBan;
    public:

        CNhanVienSanXuat()
        {
            SoSanPham = 0;
            LuongCoBan = 0;
        }

        CNhanVienSanXuat(int _SoSanPham, int _LuongCoBan)
        {
            SoSanPham = _SoSanPham;
            LuongCoBan = _LuongCoBan;
        }

        ~CNhanVienSanXuat(){}

        void Nhap()
        {
            CNhanVien::Nhap();
            cout << "Nhap luong co ban: ";
            cin >> LuongCoBan;

            cout << "Nhap so san pham: ";
            cin >> SoSanPham;
            cin.ignore();
        }

        void Xuat()
        {
            CNhanVien::Xuat();
            cout << SoSanPham << "\t" << TinhLuong() << endl;

        }

        long TinhLuong()
        {
            return Luong = LuongCoBan + SoSanPham*5000;
        }

        long GetLuong()
        {
            return Luong;
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
            CNhanVien::Nhap();
            cout << "Nhap so ngay lam viec: ";
            cin >> SoNgayLamViec;
            cin.ignore();
        }

        void Xuat()
        {
            CNhanVien::Xuat();
            cout << SoNgayLamViec << "\t" << TinhLuong() << endl;
        }

        long TinhLuong()
        {
           return Luong = SoNgayLamViec*100000; 
        }

        long GetLuong()
        {
            return Luong;
        }      
};

class QuanLyNhanVien
{
    private:
        CNhanVien** NV;
        int SoNhanVien;
        long TongLuong;
        long LuongCaoNhat, LuongThapNhat;
        int Max, Min;
    public:
        
        QuanLyNhanVien()
        {
            SoNhanVien = 0;
            TongLuong = 0;
            LuongCaoNhat = 0;
            LuongThapNhat = 0;
            Max = 0;
            Min = 0;
            
            NV = new CNhanVien *[0];
        }

        QuanLyNhanVien(int _SoNhanVien, long _TongLuong, long _LuongCaoNhat, long _LuongThapNhat, int _Max, int _Min)
        {
            SoNhanVien = _SoNhanVien;
            TongLuong = _TongLuong;
            LuongCaoNhat = _LuongCaoNhat;
            LuongThapNhat = _LuongThapNhat;
            Max = _Max;
            Min = _Min;
            
            NV = new CNhanVien *[SoNhanVien];
        }

        ~QuanLyNhanVien()
        {
            for (int i = 0; i < SoNhanVien; i++)
                delete NV[i];
            delete[]NV;
        }

        void NhapThongTinNhanVien()
        {
            cout << "Nhap so luong nhan vien: ";
            cin >> SoNhanVien;

            NV = new CNhanVien *[SoNhanVien];
            int LuaChon = 0;
            
            for (int i = 0; i < SoNhanVien; i++)
            {
                do
                {
                    cout << "==============================" << endl;
                    cout << "Nhap thong tin nhan vien thu: " << i + 1 << endl;
                    cout << "Menu nhap du lieu:" << endl;
                    cout << "Nhap so 1 neu la nhan vien san xuat" << endl;
                    cout << "Nhap so 2 neu la nhan vien van phong" << endl;
                    cout << "Nhap su lua chon: ";
                    cin >> LuaChon;
                    if (LuaChon != 1 && LuaChon != 2)
                    {
                        cout << "Nhap sai lua chon, vui long nhap lai!" << endl;
                    }
                }
                while (LuaChon != 1 && LuaChon != 2);

                switch (LuaChon)
                {
                    case 1:
                        NV[i] = new CNhanVienSanXuat;
                        break;
                    case 2:
                        NV[i] = new CNhanVienVanPhong;
                        break;
                }

                NV[i]-> Nhap();  
                TongLuong += NV[i]->GetLuong();  
            }
        }

        void TinhLuongCaoNhat()
        {
            LuongCaoNhat = NV[0]->GetLuong();

            for (int i = 0; i < SoNhanVien; i++)
            {
                if (NV[i]->GetLuong() > LuongCaoNhat)
                {
                    LuongCaoNhat = NV[i]->GetLuong();
                    Max = i;
                }
            }
        }

        void TinhLuongThapNhat()
        {
            LuongThapNhat = NV[0]->GetLuong();

            for (int i = 0; i < SoNhanVien; i++)
            {
                if (NV[i]->GetLuong() < LuongThapNhat)
                {
                    LuongThapNhat = NV[i]->GetLuong();
                    Min = i;
                }
            }
        }

        void XuatThongTinNhanVien()
        {
            cout << "So luong nhan vien cua cong ty: " << SoNhanVien << endl;
            for (int i = 0; i < SoNhanVien; i++)
            {
                cout << "=================================================" << endl;
                cout << "Thong tin nhan vien thu: " << i + 1 << endl;
                NV[i]->Xuat();
                cout << "Tien luong nhan duoc: " << NV[i]->GetLuong() << endl;
            }
            cout << "======================================================" << endl;
            cout << "Tong so tien luong ma cong ty phai tra cho nhan vien: " << TongLuong << endl;

            cout << "Nhan vien co muc luong cao nhat la: " << endl;
            NV[Max]->Xuat();
            cout << endl;

            cout << "Nhan vien co muc luong thap nhat la: " << endl;
            NV[Min]->Xuat();
            cout << endl;
        }

        void SapXepLuongGD()
        {
            for (int i = 0; i < SoNhanVien - 1; i++)
            {
                for (int j = i + 1; j < SoNhanVien; j++)
                {
                    if (NV[i]->GetLuong() < NV[j]->GetLuong())
                        swap(NV[i], NV[j]);
                }
            }

            cout << "Danh sach nhan vien sau khi sap xep theo luong giam dan:" << endl;
            for (int i = 0; i < SoNhanVien; i++)
            {
                NV[i]->Xuat();
            }
        }
};

int main()
{
    QuanLyNhanVien UIT;
    UIT.NhapThongTinNhanVien();
    UIT.XuatThongTinNhanVien();
    UIT.SapXepLuongGD();

    return 0;
}
