#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CNhanVien
{
protected:
    string HoTen;
    string NgaySinh;
    long Luong;
    int LuongCoBan;

public:
    CNhanVien()
    {
        HoTen = "";
        NgaySinh = "";
        Luong = 0;
        LuongCoBan = 0;
    }

    CNhanVien(string _HoTen, string _NgaySinh, long _Luong, int _LuongCoBan)
    {
        HoTen = _HoTen;
        NgaySinh = _NgaySinh;
        Luong = _Luong;
        LuongCoBan = _LuongCoBan;
    }

    virtual ~CNhanVien() {}

    virtual void Nhap()
    {
        cin.ignore();
        cout << "Nhap ho ten nhan vien: ";
        getline(cin, HoTen);

        cout << "Nhap ngay sinh nhan vien: ";
        getline(cin, NgaySinh);

        cout << "Nhap luong co ban: ";
        cin >> LuongCoBan;
    }

    virtual void Xuat()
    {
        cout << left << setw(20) << HoTen
             << setw(15) << NgaySinh
             << setw(15) << LuongCoBan;
    }

    virtual long TinhLuong() = 0;

    long GetLuong()
    {
        return Luong;
    }

    string GetTen()
    {
        return HoTen;
    }
};

class CQuanLy : public CNhanVien
{
private:
    int HeSoChucVu;
    long Thuong;

public:
    CQuanLy()
    {
        HeSoChucVu = 0;
        Thuong = 0;
    }

    CQuanLy(int _HeSoChucVu, long _Thuong)
    {
        HeSoChucVu = _HeSoChucVu;
        Thuong = _Thuong;
    }

    ~CQuanLy() {}

    void Nhap()
    {
        CNhanVien::Nhap();

        cout << "Nhap he so chuc vu: ";
        cin >> HeSoChucVu;

        cout << "Nhap thuong: ";
        cin >> Thuong;
    }

    void Xuat()
    {
        CNhanVien::Xuat();
        cout << setw(15) << HeSoChucVu
             << setw(20) << Thuong
             << setw(15) << TinhLuong() << endl;
    }

    long TinhLuong()
    {
        return Luong = LuongCoBan * HeSoChucVu + Thuong;
    }
};

class CSanXuat : public CNhanVien
{
private:
    int SoSanPham;
public:
    CSanXuat()
    {
        SoSanPham = 0;
    }

    CSanXuat(int _SoSanPham)
    {
        SoSanPham = _SoSanPham;
    }

    ~CSanXuat() {}

    void Nhap()
    {
        CNhanVien::Nhap();

        cout << "Nhap so san pham: ";
        cin >> SoSanPham;
    }

    void Xuat()
    {
        CNhanVien::Xuat();
        cout << setw(35) << SoSanPham
             << setw(15) << TinhLuong() << endl;
    }

    long TinhLuong()
    {
        return Luong = LuongCoBan + SoSanPham * 2000;
    }
};

class CVanPhong : public CNhanVien
{
private:
    int SoNgayLamViec;
    long TroCap;

public:
    CVanPhong()
    {
        SoNgayLamViec = 0;
        TroCap = 0;
    }

    CVanPhong(int _SoNgayLamViec, int _TroCap)
    {
        SoNgayLamViec = _SoNgayLamViec;
        TroCap = _TroCap;
    }

    ~CVanPhong() {}

    void Nhap()
    {
        CNhanVien::Nhap();
        cout << "Nhap so ngay lam viec: ";
        cin >> SoNgayLamViec;

        cout << "Nhap tro cap: ";
        cin >> TroCap;
    }

    void Xuat()
    {
        CNhanVien::Xuat();
        cout << setw(15) << SoNgayLamViec
             << setw(20) << TroCap
             << setw(15) << TinhLuong() << endl;
    }

    long TinhLuong()
    {
        return Luong = LuongCoBan + SoNgayLamViec * 200000 + TroCap;
    }
};

class CCongTy
{
private:
    CNhanVien **NV;
    int SoNhanVien;
    long TongLuong;

public:
    CCongTy()
    {
        SoNhanVien = 0;
        TongLuong = 0;

        NV = new CNhanVien *[0];
    }

    CCongTy(int _SoNhanVien, long _TongLuong)
    {
        SoNhanVien = _SoNhanVien;
        TongLuong = _TongLuong;

        NV = new CNhanVien *[SoNhanVien];
    }

    ~CCongTy()
    {
        for (int i = 0; i < SoNhanVien; i++)
            delete NV[i];
        delete[] NV;
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
                cout << "Nhap so 1 neu la nhan vien quan ly" << endl;
                cout << "Nhap so 2 neu la nhan vien san xuat" << endl;
                cout << "Nhap so 3 neu la nhan vien van phong" << endl;
                cout << "Nhap su lua chon: ";
                cin >> LuaChon;
                if (LuaChon != 1 && LuaChon != 2 && LuaChon != 3)
                {
                    cout << "Nhap sai lua chon, vui long nhap lai!" << endl;
                }
            } while (LuaChon != 1 && LuaChon != 2 && LuaChon != 3);

            switch (LuaChon)
            {
            case 1:
                NV[i] = new CQuanLy;
                break;
            case 2:
                NV[i] = new CSanXuat;
                break;
            case 3:
                NV[i] = new CVanPhong;
                break;
            }

            NV[i]->Nhap();
            NV[i]->TinhLuong(); // Tính lương ngay sau khi nhập
            TongLuong += NV[i]->GetLuong();
        }
    }

    void XuatThongTinNhanVien()
    {
        cout << left << setw(20) << "Ho Ten"
             << setw(15) << "Ngay Sinh"
             << setw(15) << "Luong CB"
             << setw(15) << "He So/So SP"
             << setw(20) << "Thuong/Tro Cap"
             << setw(15) << "Luong" << endl;

        for (int i = 0; i < SoNhanVien; i++)
        {
            cout << "=============================================================================================" << endl;
            cout << "Thong tin nhan vien thu: " << i + 1 << endl;
            NV[i]->Xuat();
        }
        cout << "=============================================================================================" << endl;
        cout << "Tong so tien luong ma cong ty phai tra cho nhan vien: " << TongLuong << endl;
    }

    void TimKiemNhanVien()
    {
        cout << "Nhap ten nhan vien can tim: ";
        cin.ignore();
        string Ten;
        getline(cin, Ten);
        int flag = 0;

        for (int i = 0; i < SoNhanVien; i++)
        {
            if (NV[i]->GetTen() == Ten)
            {
                NV[i]->Xuat();
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cout << "Khong tim duoc!" << endl;
    }
};

int main()
{
    CCongTy VNG;
    VNG.NhapThongTinNhanVien();
    VNG.XuatThongTinNhanVien();
    VNG.TimKiemNhanVien();

    return 0;
}
