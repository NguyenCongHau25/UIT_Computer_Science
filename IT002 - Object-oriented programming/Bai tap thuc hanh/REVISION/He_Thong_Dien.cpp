#include <iostream>
using namespace std;

class NguonDien
{
    protected:

        double HieuSuat;

    public:

        NguonDien()
        {
            HieuSuat = 0;
        }

        virtual ~NguonDien(){}

        virtual void Nhap()
        {
            cout << "Nhap vao hieu suat: ";
            cin >> HieuSuat;
        }
};

class ThuyDien: public NguonDien
{
    private:

        int SoLuongToMay;
        bool TichNang;
        //int SoDienTichDuoc;

    public:

        void Nhap()
        {
            NguonDien::Nhap();
            cout << "Nhap so luong to may: ";
            cin >> SoLuongToMay;
            cout << "Xac dinh tich nang: ";
            cin >> TichNang;
        }

};

class NhietDien: public NguonDien
{
    private:

        int SoLuongThan;

    public:

        void Nhap()
        {
            cout << "Nhap so luong than: ";
            cin >> SoLuongThan;
        }

};

class DienGio: public NguonDien
{
    private:

        int HieuSuatDanhDinh;
        int SoLuongTuaBin;
        //int TocDoGioHienTai;
        int TocDoGioToiDa;

    public:

        void Nhap()
        {
            cout << "Nhap Hieu Suat Danh Dinh: ";
            cin >> HieuSuatDanhDinh;
            cout << "Nhap so luong tua bin: ";
            cin >> SoLuongTuaBin;
            cout << "Toc do gio toi da: ";
            cin >> TocDoGioToiDa;
        }

};

class DienMatTroi: public NguonDien
{
    private:

        int DienTichPin;
        int SoPin;

    public:

        void Nhap()
        {
            cout << "Dien tich pin: ";
            cin >> DienTichPin;
            cout << "So pin: ";
            cin >> SoPin;
        }
};

class HeThongDien
{
    private:

        int n;
        NguonDien **D;
        int SoGio;
        int Gio;
        int TocDoGio;
        bool ThoiTiet;
        int CongSuatTieuThu;

    public:

        void Nhap()
        {
            cout << "Nhap vao so nguon dien: ";
            cin >> n;

            int LuaChon;
            D = new NguonDien *[n];
            for (int i = 0; i < n; i++)
            {
                do
                {
                    cout << "Chon cac dich vu (1. Thuy Dien, 2. Nhiet Dien, 3. Dien Gio, 4. Dien Mat Troi): " << endl;
                    cin >> LuaChon;
                    if (LuaChon != 1 && LuaChon != 2 && LuaChon != 3 && LuaChon != 4)
                        cout << "Nhap sai vui long nhap lai!" << endl;
                } while (LuaChon != 1 && LuaChon != 2 && LuaChon != 3 && LuaChon != 4);

                switch (LuaChon)
                {
                case 1:
                    D[i] = new ThuyDien;
                    break;

                case 2:
                    D[i] = new NhietDien;
                    break;

                case 3:
                    D[i] = new DienGio;
                    break;
                
                case 4:
                    D[i] = new DienMatTroi;
                    break;
                }

                D[i]->Nhap();
            }

            cout << "Nhap So Gio: ";
            cin >> SoGio;
            for (int i = 0; i < SoGio; i++)
            {
                cin >> Gio;
                cin >> TocDoGio;
                cin >> ThoiTiet;
                cin >> CongSuatTieuThu;
            }
        }

        
};

int main()
{   
    HeThongDien A;
    A.Nhap();
    
    return 0;
}