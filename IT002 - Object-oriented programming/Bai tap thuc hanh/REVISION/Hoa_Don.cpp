#include<iostream>
#include <string>
using namespace std;

class SanPham
{
    protected:
        long Gia;
        string MaSo;
        string TieuDe;
    public:
        virtual void Nhap() = 0;
        virtual void Xuat() = 0;
        long GetGia();
};

class Tranh: public SanPham
{
    private:
        int Cao, Rong;
        string HoaSi;
    public:
        void Nhap();
        void Xuat();
};

class CD: public SanPham
{
    private:
        string CaSi;
        string DonVi;
    public:

        void Nhap();
        void Xuat();
};

class Ngay
{
    private:
        int Ngay, Thang, Nam;
    public:
        void Nhap();
        void Xuat();
};

class Nguoi
{
    private:
        int MaKH;
        string Ten;
        string SDT;
    public:
        void Nhap();
        void Xuat();
        int GetMaKH();
};

class HoaDon
{
    private:
        string MaDon;
        Nguoi Khach;
        Ngay NgayCap;
        int n;
        SanPham **SP;
        long TongGia;
    public:
        void Nhap();
        void Xuat();
        int GetTongGia();
        Nguoi GetKhach();
};

class DanhSachHoaDon
{
    private:
        int size;
        HoaDon *DS;
        long TongThuNhap();
    public:
        void Nhap();
        void Xuat();
        long ThuNhap();
        void TimKiemMax();
};

void SanPham::Nhap()
{
    cout << "Nhap gia san pham: "<< endl;
    cin >> Gia;
    cout << "Nhap ma so san pham: " << endl;
    getline(cin, MaSo);
    cout << "Nhap Tieu de san pham: " << endl;
    getline(cin, TieuDe);
}

void SanPham::Xuat()
{
    cout << "Gia san pham: " << Gia << endl;
    cout << "Ma so: " << MaSo << endl;
    cout << "Tieu de: " << TieuDe << endl;
}

long SanPham:: GetGia()
{
    return Gia;
}

void Tranh::Nhap()
{
    SanPham::Nhap();
    cout << "Nhap chieu cao: " << endl;
    cin >> Cao;
    cout << "Nhap chieu rong: " << endl;
    cin >> Rong;
    cout << "Nhap ten hoa si: " << endl;
    getline(cin, HoaSi);
}

void Tranh::Xuat()
{
    SanPham::Xuat();
    cout << "Chieu cao: " << Cao << endl;
    cout << "Chieu rong: " << Rong << endl;
    cout << "Ten hoa si: " << HoaSi << endl;
}

void CD::Nhap()
{
    SanPham::Nhap();
    cout << "Nhap ten ca si: " << endl;
    getline(cin, CaSi);
    cout << "Nhap ten don vi phat hanh: " << endl;
    getline(cin, DonVi);
}

void CD::Xuat()
{
    SanPham::Xuat();
    cout << "Ca si: " << CaSi << endl;
    cout << "Don Vi: " << DonVi << endl;
}

void Ngay::Nhap()
{
    cout << "Nhap ngay: " << endl;
    cin >> Ngay;
    cout << "Nhap thang: " << endl;
    cin >> Thang;
    cout << "Nhap nam: " << endl;
    cin >> Nam;
}

void Ngay::Xuat()
{
    cout  << Ngay << "/" << Thang << "/" << Nam << endl;
}

void Nguoi:: Nhap()
{
    cout << "Nhap ma khach hang: " << endl;
    cin >> MaKH;
    cout << "Nhap ten khach hang: " << endl;
    getline(cin, Ten);
    cout << "Nhap so dien thoai khach hang: " << endl;
    getline(cin, SDT);
}

void Nguoi::Xuat()
{
    cout << "Ma KH: " << MaKH << endl;
    cout << "Ten KH: " << Ten << endl;
    cout << "So dien thoai: " << SDT << endl;
}

int Nguoi::GetMaKH()
{
    return MaKH;
}

void HoaDon::Nhap()
{
    cout << "Nhap vao ma hoa don: " << endl;
    getline(cin, MaDon);
    cout << "Nhap thong tin khach hang: " << endl;
    Khach.Nhap();
    cout << "Nhap ngay thang nam: " << endl;
    NgayCap.Nhap();
    cout << "Nhap vao so luong san pham: " << endl;
    cin >> n;
    SP = new SanPham*[n];
    int LuaChon;

    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Nhap lua chon san pham: (1. Tranh, 2.CD): " << endl;
            cin >> LuaChon;
            if (LuaChon != 1 && LuaChon != 2)
                cout << "Nhap sai vui long nhap lai!";
        } while (LuaChon != 1 && LuaChon != 2);

        switch (LuaChon)
        {
            case 1:
                SP[i] = new Tranh;
                break;
            
            case 2:
                SP[i] = new CD;
                break;
        }

        SP[i]->Nhap();
    }
}

void HoaDon::Xuat()
{  
    cout << "Ma hoa don: " << MaDon << endl;
    cout << "Thong tin khach hang: " << endl;
    Khach.Xuat();
    cout << "Ngay thang: " << endl;
    NgayCap.Xuat();
    cout << "Thong tin san pham: " << endl;
    for (int i = 0; i < n; i++)
    {
        SP[i]->Xuat();
    }
}

int HoaDon::GetTongGia()
{
    int TongGia = 0;
    for (int i = 0; i < n; i++)
        TongGia += SP[i]->GetGia();
    return TongGia;
}

Nguoi HoaDon::GetKhach()
{
    return Khach;
}

void DanhSachHoaDon::Nhap()
{
    cout << "Nhap so luong hoa don: " << endl;
    cin >> size;
    DS = new HoaDon[size];
    cout << "Nhap thong tin hoa hoa don: " << endl;
    for (int i = 0; i < size; i++)
    {
        DS[i].Nhap();
    }
}

void DanhSachHoaDon::Xuat()
{
    for (int i = 0; i < size; i++)
    DS[i].Xuat();
}

long DanhSachHoaDon::ThuNhap()
{
    int TongThuNhap = 0;
    for (int i = 0; i < size; i++)
        TongThuNhap += DS[i].GetTongGia();
    cout << TongThuNhap << endl;
    return TongThuNhap;
}

void DanhSachHoaDon::TimKiemMax()
{
    int Max = DS[0].GetTongGia();
    for (int i = 1; i < size; i++)
        if (DS[i].GetTongGia() > Max)
            Max = DS[i].GetTongGia();
    for (int i = 0; i < size; i++)
        if (DS[i].GetTongGia() == Max)
            DS[i].GetKhach();
}

int main()
{
    DanhSachHoaDon CloudCoffee;
    CloudCoffee.Nhap();
    CloudCoffee.Xuat();
    CloudCoffee.ThuNhap();
    CloudCoffee.TimKiemMax();
    return 0;
}
