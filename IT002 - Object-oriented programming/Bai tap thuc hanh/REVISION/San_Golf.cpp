#include <iostream>
using namespace std;

class Ve
{
    protected:

        int TienVe;
        
    public:

        Ve(){}

        virtual ~Ve(){}

        virtual void Nhap() = 0;

        void Xuat()
        {
            TinhTienVe();
            cout << TienVe << endl;
        }

        virtual void TinhTienVe(){};

        virtual int GetTienVe()
        {
            return TienVe;
        }

        virtual bool isVeTap()
        {
            return 0;
        }

        virtual bool isVeThuong()
        {
            return 0;
        }

        virtual int GetSoDichVu()
        {
            return 0;
        }
};

class VeVip: public Ve
{ 
    public:

        VeVip(){}

        ~VeVip(){}  

        void Nhap()
        {
            TienVe = 4000000;
        } 
};

class VeThuong: public Ve
{ 
    private:
        int TienDanhGolf;
        int TienDichVu;
        int SoDichVu;
    public:

        VeThuong()
        {
            TienDanhGolf = 1800000;
        }

        ~VeThuong(){}

        void Nhap()
        {
            cout << "Nhap so dich vu them:  " << endl;
            cin >> SoDichVu;
            TienDichVu = SoDichVu*600000;
        }

        void TinhTienVe()
        {
            TienVe = TienDanhGolf + TienDichVu;
        }

        bool isVeThuong()
        {
            return 1;
        }

        int GetSoDichVu()
        {
            return SoDichVu;
        }
};

class VeTap: public Ve
{
    private:

        int ChiPhiTap;
        int SoGioTap;

    public:

        VeTap()
        {
            ChiPhiTap = 1700000;
        }

        ~VeTap(){}

        void Nhap()
        {
            cout << "Nhap so gio tap: " << endl;
            cin >> SoGioTap;
        }

        void TinhTienVe()
        {
            TienVe = SoGioTap*ChiPhiTap;
        }

        bool isVeTap()
        {
            return 1;
        }
    
};

class DanhSachVeDaBan
{
    private:
        int SoVeDaBan;
        Ve** V;
        int TongTienVeNguoiTapChoi;
        int VeThuongMenhGiaCaoNhat;
    public:

        DanhSachVeDaBan()
        {
            SoVeDaBan = 0;
            V = new Ve*[0];
            TongTienVeNguoiTapChoi = 0;
            VeThuongMenhGiaCaoNhat = 0;
        }

        ~DanhSachVeDaBan()
        {
            for (int i = 0; i < SoVeDaBan; i++)
            {
                delete V[i];
            }
            delete V;
        }

        void Nhap()
        {
            cout << "Nhap so luong ve da ban: ";
            cin >> SoVeDaBan;
            V = new Ve*[SoVeDaBan];
            int LuaChon;
            for (int i = 0; i < SoVeDaBan; i++)
            {
                do
                {
                    cout << "Nhap loai ve(1. Ve Vip, 2. Ve Thuong, 3. Ve Tap): "<< endl;
                    cin >> LuaChon;
                    if (LuaChon != 1 && LuaChon != 2 && LuaChon != 3)
                        cout << "Nhap sai vui long nhap lai!" << endl;
                } while (LuaChon != 1 && LuaChon != 2 && LuaChon != 3);

                switch (LuaChon)
                {
                    case 1:
                        V[i] = new VeVip;
                        break;
                    case 2:
                        V[i] = new VeThuong;
                        break;
                    case 3:
                        V[i] = new VeTap;
                        break;
                }
                V[i]->Nhap();
            }
        }

        void Xuat()
        {
            cout << "Danh sach cac ve da nhap: " << endl;

            cout << "VeVip: " << endl;
            for (int i = 0; i < SoVeDaBan; i++)
                if(!V[i]->isVeTap() && !V[i]->isVeThuong())
                    V[i]->Xuat();
            cout << "Ve Thuong: " << endl;
            for (int i = 0; i < SoVeDaBan; i++)
                if (V[i]->isVeThuong())
                    V[i]->Xuat();
            cout << "Ve Tap: " << endl;
            for (int i = 0; i < SoVeDaBan; i++)
                if (V[i]->isVeTap())
                    V[i]->Xuat();
        }

        void TinhTienVe()
        {
            for (int i = 0; i < SoVeDaBan; i++)
                V[i]->TinhTienVe();
        }

        void TinhTongTienVeBanChoNguoiMoiChoi()
        {
            for (int i = 0; i < SoVeDaBan; i++)
                if (V[i]->isVeTap())
                    TongTienVeNguoiTapChoi += V[i]->GetTienVe();
            cout << "Tong tien ve da ban cho nguoi moi choi: " << TongTienVeNguoiTapChoi << endl;
        }

        void TinhSoDichVuTrungBinhVeThuong()
        {
            int SoDichVu = 0;
            int SoVeThuong = 0;
            float TrungBinhSoDichVu = 0;
            for (int i = 0; i < SoVeDaBan; i++)
                if(V[i]->isVeThuong())
                {
                    SoVeThuong++;
                    SoDichVu += V[i]->GetSoDichVu();
                }
            TrungBinhSoDichVu = SoDichVu/SoVeThuong;
            cout << "Trung binh moi ve khach chon them " << TrungBinhSoDichVu << " dich vu " << endl;
        }

        void TimVeThuongCoMenhGiaCaoNhat()
        {
            int ViTri = 0;
            bool KiemTra = 0;
            for (int i = 0; i < SoVeDaBan; i++)
            {
                if (V[i]->isVeThuong())
                {
                    if (!KiemTra)
                    {
                        ViTri = i;
                        KiemTra = 1;
                    }
                    else
                    {
                        if (V[i]->GetTienVe() > V[ViTri]->GetTienVe())
                            ViTri = i;
                    } 
                }
            }

            if (!KiemTra)
                cout << "KHONG CO NHAN VIEN SAN XUAT NAO TRONG DAI LY\n";
            else
            {
                cout << "Menh gia ve thuong lon nhat la: " << V[ViTri]->GetTienVe() << endl;
            }
        } 
        
};


int main()
{
    DanhSachVeDaBan KingGolf;
    KingGolf.Nhap();
    KingGolf.Xuat();
    KingGolf.TinhTienVe();
    KingGolf.TinhTongTienVeBanChoNguoiMoiChoi();
    KingGolf.TinhSoDichVuTrungBinhVeThuong();
    KingGolf.TimVeThuongCoMenhGiaCaoNhat();
    return 0;
}