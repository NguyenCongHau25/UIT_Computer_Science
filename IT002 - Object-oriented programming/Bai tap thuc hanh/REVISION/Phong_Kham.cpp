#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class NhanVien
{
    protected:

        string HoTen;
        string NgaySinh;
        string MaSoThue;
        int Luong;

    public:

        NhanVien()
        {
            HoTen = "";
            NgaySinh = "";
            MaSoThue = "";
            Luong = 0;
        }

        NhanVien(string _HoTen, string _NgaySinh, string _MaSoThue, int _Luong)
        {
            HoTen = _HoTen;
            NgaySinh = _NgaySinh;
            MaSoThue = _MaSoThue;
            Luong = _Luong;
        }

        virtual ~NhanVien(){}

        virtual void Nhap()
        {
            cout << "Nhap ho ten nhan vien: " << endl;
            getline(cin, HoTen);
            cout << "Nhap ngay sinh cua nhan vien: " << endl;
            getline(cin, NgaySinh);
            cout << "Nhap ma so thue cua nhan vien: " << endl;
            getline(cin, MaSoThue);
        }

        virtual void Xuat()
        {
            cout << left << setw(15) << HoTen << setw(15) << NgaySinh << setw(15) << MaSoThue;
        }

        virtual bool isBacSi()
        {
            return 0;
        }

        virtual bool isNhanVienChamSoc()
        {
            return 0;
        }

        virtual void TinhLuong() = 0;
        
        virtual int GetLuong()
        {
            return Luong;
        }
};

class BacSi: public NhanVien
{
    private:

        int LuongCoBan;
        int GioTangCa;
        bool TangCaCuoiTuan;

    public:

        BacSi():NhanVien()
        {
            LuongCoBan = 0;
            GioTangCa = 0;
            TangCaCuoiTuan = 0;
        }

        BacSi(int _LuongCoBan, int _GioTangCa, bool _TangCaCuoiTuan):NhanVien()
        {
            LuongCoBan = _LuongCoBan;
            GioTangCa = _GioTangCa;
            TangCaCuoiTuan = _TangCaCuoiTuan;
        }

        ~BacSi(){}

        void Nhap()
        {
            NhanVien::Nhap();
            cout << "Nhap luong co ban: " << endl;
            cin >> LuongCoBan;
            cout << "Nhap vao so gio tang ca: " << endl;
            cin >> GioTangCa;
            cout << "Lua chon tang ca va cuoi tuan hay trong tuan (0. Trong tuan, 1. Cuoi Tuan): " << endl;
            cin >> TangCaCuoiTuan;
        }

        void Xuat()
        {
            NhanVien::Xuat();
            cout << setw(15) << LuongCoBan << Luong << endl;
        }

        bool isBacSi()
        {
            return 1;
        }

        void TinhLuong()
        {
            if (TangCaCuoiTuan == 1)
                Luong = LuongCoBan + GioTangCa*300000;
            else 
                Luong = LuongCoBan + GioTangCa*200000;
        }
};

class KyThuatVien: public NhanVien
{ 
    private:
        
        int CongLamViec;

    public:

        KyThuatVien():NhanVien()
        {
            CongLamViec = 0;
        }

        KyThuatVien(int _CongLamViec):NhanVien()
        {
            CongLamViec = _CongLamViec;
        }

        ~KyThuatVien(){}

        void Nhap()
        {
            NhanVien::Nhap();
            cout << "Nhap so cong lam viec: " << endl;
            cin >> CongLamViec;
        }

        void Xuat()
        {
            NhanVien::Xuat();
            cout << setw(15) << CongLamViec << Luong << endl;
        }

        void TinhLuong()
        {
            Luong = CongLamViec*300000;
        }
};

class NhanVienChamSoc: public NhanVien
{
    private:
        
        int CongLamViec;

    public:

        NhanVienChamSoc():NhanVien()
        {
            CongLamViec = 0;
        }

        NhanVienChamSoc(int _CongLamViec):NhanVien()
        {
            CongLamViec = _CongLamViec;
        }

        ~NhanVienChamSoc(){}

        void Nhap()
        {
            NhanVien::Nhap();
            cout << "Nhap so cong lam viec: " << endl;
            cin >> CongLamViec;
        }

        void Xuat()
        {
            NhanVien::Xuat();
            cout << setw(15) << CongLamViec << Luong << endl;
        }

        bool isNhanVienChamSoc()
        {
            return 1;
        }

        void TinhLuong()
        {
            Luong = CongLamViec*200000;
        }
};

class DanhSachNhanVien
{
    private:

        int SoNhanVien;
        NhanVien **NV;
        int TongLuongCSKH = 0;
        int TongLuongKyThuatVien = 0;

    public:

        DanhSachNhanVien()
        {
            SoNhanVien = 0;
            NV = new NhanVien *[0];
        }

        DanhSachNhanVien(int _SoNhanVien)
        {
            SoNhanVien = _SoNhanVien;
            NV = new NhanVien *[SoNhanVien];
        }

        ~DanhSachNhanVien ()
        {
            for (int i = 0; i < SoNhanVien; i++)
                delete NV[i];
            delete[]NV;
        }

        void Nhap()
        {
            cout << "Nhan so luong nhan vien: ";
            cin >> SoNhanVien;
            int LuaChon;
            for (int i = 0; i < SoNhanVien; i++)
            {
                do
                {
                    cout << "Nhap lua chon nhan vien (0. Bac si, 1. Ky thuat vien, 2. Cham soc khach hang): " << endl;
                    cin >> LuaChon;
                    cin.ignore();
                    if (LuaChon != 0 && LuaChon != 1 && LuaChon != 2)
                        cout << "Nhap sai vui long nhap lai!" << endl;
                } while (LuaChon != 0 && LuaChon != 1 && LuaChon != 2);

                switch (LuaChon)
                {
                case 0:
                    NV[i] = new BacSi;
                    break;
                
                case 1:
                    NV[i] = new KyThuatVien;
                    break;

                case 2:
                    NV[i] = new NhanVienChamSoc;
                    break;
                }
                NV[i]->Nhap();
            }
        }

        void Xuat()
        {
            for (int i = 0; i < SoNhanVien; i++)
                NV[i]->Xuat();
        }

        void TinhLuongChoNhanVien()
        {
            for (int i = 0; i < SoNhanVien; i++)
                NV[i]->TinhLuong();
        }
        
        void TinhTongLuongCSKH()
        {
            
            for (int i = 0; i < SoNhanVien; i++)
                if(NV[i]->isNhanVienChamSoc())
                    TongLuongCSKH += NV[i]->GetLuong();
            cout << "Tong luong cong ty phai tra cho nvcskh " << TongLuongCSKH << endl;
        }

        void TimBacSiCoLuongCaoNhat()
        {
            int ViTri = 0;
            bool KiemTra = 0;
            for (int i = 0; i < SoNhanVien; i++)
            {
                if (NV[i]->isBacSi())
                {
                    if (!KiemTra)
                    {
                        ViTri = i;
                        KiemTra = 1;
                    }
                    else
                    {
                        if (NV[i]->GetLuong() > NV[ViTri]->GetLuong())
                            ViTri = i;
                    } 
                }
            }

            if (!KiemTra)
                cout << "KHONG CO NHAN VIEN SAN XUAT NAO TRONG DAI LY\n";
            else
            {
                NV[ViTri]->Xuat();
            }
        } 

        void TinhThuNhapTrungBinhKyThuatVien()
        {
            int TongLuongKyThuatVien = 0;
            int ThuNhapTrungBinh;
            int Dem = 0;
            for (int i = 0; i < SoNhanVien; i++)
                if(!NV[i]->isBacSi() && !NV[i]->isNhanVienChamSoc())
                {
                    TongLuongKyThuatVien += NV[i]->GetLuong();
                    Dem++;
                }
            ThuNhapTrungBinh = TongLuongKyThuatVien/Dem;
            cout << "Thu nhap trung binh cua ky thuat vien: " << ThuNhapTrungBinh<< endl;
        }
};


int main()
{
    DanhSachNhanVien NamAn;
    NamAn.Nhap();
    NamAn.Xuat();
    NamAn.TinhLuongChoNhanVien();
    NamAn.TimBacSiCoLuongCaoNhat();
    NamAn.TinhTongLuongCSKH();
    NamAn.TinhThuNhapTrungBinhKyThuatVien();
    return 0;
}