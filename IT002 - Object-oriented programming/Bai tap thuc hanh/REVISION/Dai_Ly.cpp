#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class NhanVien
{
    protected:

        string Ma;
        string HoTen;
        int LuongCoBan;
        int LuongHangThang;
    
    public:

        NhanVien()
        {
            Ma = "";
            HoTen = "";
            LuongCoBan = 0;
            LuongHangThang = 0;
        }

        NhanVien(string _Ma, string _HoTen, int _LuongCoBan, int _LuongHangThang)
        {
            Ma = _Ma;
            HoTen = _HoTen;
            LuongCoBan = _LuongCoBan;
            LuongHangThang = _LuongHangThang;
        }

        virtual ~NhanVien()
        {

        }

        virtual void Nhap()
        {
            cout << "Nhap ma nhan vien: ";
            getline(cin, Ma);
            cout << "Nhap ho ten nhan vien: ";
            getline(cin, HoTen);
            cout << "Nhap luong co ban: ";
            cin >> LuongCoBan;
        }

        virtual void Xuat()
        {
            cout << left << setw(10) << Ma << setw(10) << HoTen << setw(10) << LuongCoBan << setw(15) << LuongHangThang << setw(15);
        }

        virtual void TinhLuong() = 0;

        string GetMa()
        {
            return Ma;
        }

        int GetLuongHangThang()
        {
            return LuongHangThang;
        }

        void SetLuongCoBan(int LuongCapNhat)
        {
            LuongCoBan = LuongCapNhat;
        }

        int GetLuongCoBan()
        {
            return LuongCoBan;
        }

        virtual bool isNhanVienSanXuat()
        {
            return 0;
        }

};

class VanPhong: public NhanVien
{
    private:
        
        int SoGioLam;
        int TroCap;

    public:

        VanPhong()
        {
            SoGioLam = 0;
            TroCap = 0;
        }

        VanPhong(int _SoGiolam, int _TroCap)
        {
            SoGioLam = _SoGiolam;
            TroCap = _TroCap;
        }

        ~VanPhong(){}

        void Nhap()
        {
            NhanVien::Nhap();
            cout << "Nhap so gio lam: ";
            cin >> SoGioLam;
        }

        void Xuat()
        {
            NhanVien::Xuat();
            cout << SoGioLam << setw(15) << endl;
        }

        void TinhLuong()
        {
            if (SoGioLam > 100)
                TroCap = 5000000;
            else 
                TroCap = 0;
            
            LuongHangThang = LuongCoBan + SoGioLam * 220000 + TroCap;
        }
};

class SanXuat: public NhanVien
{
    private:

        int SoSanPham;
        int ThuongThem;

    public:

        SanXuat()
        {
            SoSanPham = 0;
            ThuongThem = 0;
        }

        SanXuat(int _SoSanPham, int _ThuongThem)
        {
            SoSanPham = _SoSanPham;
            ThuongThem = _ThuongThem;
        }

        ~SanXuat(){}

        void Nhap()
        {
            NhanVien::Nhap();
            cout << "Nhap so san pham: ";
            cin >> SoSanPham;
        }

        void Xuat()
        {
            NhanVien::Xuat();
            cout << SoSanPham << setw(15) << endl;
        }

        void TinhLuong()
        {
            LuongHangThang = LuongCoBan + SoSanPham*175000;

            if (SoSanPham > 150)
            {
                ThuongThem = 0.2*LuongHangThang;
                LuongHangThang += ThuongThem;
            }
        }

        bool isNhanVienSanXuat()
        {
            return 1;
        }
};

class QuanLi: public NhanVien
{
    private:

        double HeSoChucVu;
        int Thuong;
    
    public:

        QuanLi()
        {
            HeSoChucVu = 0;
            Thuong = 0;
        }

        QuanLi(double _HeSoChucVu, int _Thuong)
        {
            HeSoChucVu = _HeSoChucVu;
            Thuong = _Thuong;
        }

        ~QuanLi(){}
        
        void Nhap()
        {
            NhanVien::Nhap();
            cout << "Nhap he so chuc vu: ";
            cin >> HeSoChucVu;
            cout << "Nhap thuong them: ";
            cin >> Thuong;
        }
        
        void Xuat()
        {
            NhanVien:: Xuat();
            cout << HeSoChucVu << setw(15) << Thuong << setw(15) << endl;
        }

        void TinhLuong()
        {
            LuongHangThang = LuongCoBan*HeSoChucVu + Thuong;
        }
};

class DaiLy
{
    private:

        int n;
        NhanVien **NV;
        int TienLuongTrungBinhDaiLy;
        string MaSo;
        int Min;
        int Max;

    public:

        DaiLy()
        {
            n = 0;
            NV = new NhanVien*[0];
            TienLuongTrungBinhDaiLy = 0;
            MaSo = "";
            Min = 0;
            Max = 0;
        }

        DaiLy(int _n, int _TienLuongTrungBinhDaiLy, int _MaSo, int _Min, int _Max)
        {
            n = _n;
            NV = new NhanVien*[n];
            TienLuongTrungBinhDaiLy = _TienLuongTrungBinhDaiLy;
            MaSo = _MaSo;
            Min = _Min;
            Max = _Max;
        }

        ~DaiLy()
        {
            for (int i = 0; i < n; i++)
                delete NV[i];
            delete[]NV;
        }

        void Nhap()
        {
            cout << "Nhap so nhan vien: ";
            cin >> n;

            NV = new NhanVien*[n];
            int LuaChon;
            for (int i = 0; i < n; i++)
            {
                do
                {
                    cout << "Nhap lua chon(1. Van Phong, 2. San Xuat, 3. Dai Ly): ";
                    cin >> LuaChon;
                    cin.ignore();
                    if (LuaChon != 1 && LuaChon != 2 && LuaChon != 3)
                        cout << "Nhap sai vui long nhap lai!";
                } while (LuaChon != 1 && LuaChon != 2 && LuaChon != 3);

                switch (LuaChon)
                {
                case 1:
                    NV[i] = new VanPhong;
                    break;
                
                case 2:
                    NV[i] = new SanXuat;
                    break;

                case 3:
                    NV[i] = new QuanLi;
                    break;
                }
                
                NV[i] -> Nhap();
            }
        }

        void Xuat()
        {
            for (int i = 0; i < n; i++)
                NV[i]->Xuat();
        }

        void TinhLuongNhanVien()
        {
            for (int i = 0; i < n; i++)
                NV[i]->TinhLuong();
        }

        void TimKiemNhanVien()
        {
            cin.ignore();
            cout << "Nhap ma so nhan vien can tim: ";
            getline(cin, MaSo);
            bool KiemTra = 0;
            for (int i = 0; i < n; i++)
            {
                if (NV[i]->GetMa() == MaSo)
                {
                    NV[i]->Xuat();
                    KiemTra = 1;
                    break;
                }
            }

            if (!KiemTra)
                cout << "Khong tim thay!" << endl;
        }

        void TinhTienLuongTrungBinhDaiLy()
        {
            for (int i = 0; i < n; i++)
            {
                TienLuongTrungBinhDaiLy += NV[i]->GetLuongHangThang();
            }
            cout << "Tong tien luong dai ly phai tra: " << TienLuongTrungBinhDaiLy << endl;
        }

        void CapNhatLuongTheoMa()
        {
            cout << "Nhap ma so nhan vien can cap nhat luong: ";
            getline(cin, MaSo);

            int LuongCapNhat;
            cout << "Nhap luong can cap nhat: ";
            cin >> LuongCapNhat;
            cin.ignore();

            bool KiemTra = 0;

            for (int i = 0; i < n; i++)
            {
                if (NV[i]->GetMa() == MaSo)
                {
                    NV[i]->SetLuongCoBan(LuongCapNhat);
                    NV[i]->TinhLuong();
                    KiemTra = 1;
                }
            }
            if (!KiemTra)
                cout << "Khong tim thay!" << endl;
        }

        void LuongCoBanThapNhat()
        {
            Min = NV[0]->GetLuongCoBan();
            for (int i = 1; i < n; i++)
            {
                if (NV[i]->GetLuongCoBan() < Min)
                    Min = NV[i]->GetLuongCoBan();
            }
        }
            
        void LuongCoBanCaoNhat()
        {
            Max = NV[0]->GetLuongCoBan();
            for (int i = 1; i < n; i++)
            {
                if (NV[i]->GetLuongCoBan() > Max)
                    Max = NV[i]->GetLuongCoBan();
            }
        }

        void TimNhanVienLuongCoBanCaoNhat()
        {
            for (int i = 0; i < n; i++)
            {
                if (NV[i]->GetLuongCoBan() == Max)
                    NV[i]->Xuat();
            }
        }

        void TimNhanVienLuongCoBanThapNhat()
        {
            for (int i = 0; i < n; i++)
            {
                if (NV[i]->GetLuongCoBan() == Min)
                    NV[i]->Xuat();
            }
        }

        void TimNhanVienSanXuatLuongCaoNhat()
        {
            int ViTri = 0;
            bool KiemTra = 0;
            for (int i = 0; i < n; i++)
            {
                if (NV[i]->isNhanVienSanXuat())
                {
                    if (!KiemTra)
                    {
                        ViTri = i;
                        KiemTra = 1;
                    }
                    else
                    {
                        if (NV[i]->GetLuongHangThang() > NV[ViTri]->GetLuongHangThang())
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
};

int main()
{
    DaiLy NgoGia;

    cout << "Nhap thong tin: " << endl;
    NgoGia.Nhap();
    NgoGia.TinhLuongNhanVien();
    cout << "Thong Tin Nhan vien: " << endl;
    NgoGia.Xuat();

    NgoGia.TinhTienLuongTrungBinhDaiLy();

    NgoGia.TimKiemNhanVien();

    NgoGia.CapNhatLuongTheoMa();

    cout << "Nhan vien co luong co ban cao nhat: " << endl;
    NgoGia.LuongCoBanCaoNhat();
    NgoGia.TimNhanVienLuongCoBanCaoNhat();

    cout << "Nhan vien san xuat co luong cao nhat: " << endl;
    NgoGia.TimNhanVienSanXuatLuongCaoNhat();

    cout << "Nhan vien co luong co ban thap nhat: " << endl;
    NgoGia.LuongCoBanThapNhat();
    NgoGia.TimNhanVienLuongCoBanThapNhat();

    return 0;
}