#include <iostream>
#include <string>
using namespace std;

class CTheXe
{
    protected:

        int MaSo;
        int LoaiThe;

    public:

        CTheXe()
        {
            MaSo = 0;
            LoaiThe = 0;
        }

        CTheXe(int _MaSo, int _LoaiThe)
        {
            MaSo = _MaSo;
            LoaiThe = _LoaiThe;
        }

        virtual ~CTheXe(){}

        virtual void Nhap()
        {
            cout << "Nhap ma so the: ";
            cin >> MaSo;

            cout << "Nhap loai the (0. Can bo, 1. Sinh Vien, 2. Khach vang lai): ";
            cin >> LoaiThe;
            cout << endl;
        }

        virtual void Xuat()
        {
            cout << MaSo << '\t' << LoaiThe << "\t";
        }

        virtual int GiaThu() = 0; 
        virtual bool isXeMay()
        {
            return 0;
        } 
};

class CTheXeDap: public CTheXe
{
    public:

        ~CTheXeDap(){}

        void Xuat()
        {
            CTheXe:: Xuat();
            cout << endl;
        }

        int GiaThu()
        {
            return 3000*LoaiThe;
        }
};

class CTheXeMay: public CTheXe
{
    private:

        string BienSo;

    public:

        CTheXeMay():CTheXe()
        {
            BienSo = "";
        }

        CTheXeMay(string _BienSo):CTheXe
        {
            BienSo = _BienSo;
        }

        ~CTheXeMay(){}

        void Nhap()
        {
            CTheXe:: Nhap();
            cout << "Nhap bien so xe: ";
            cin >> BienSo;
            cin.ignore();
        }

        void Xuat()
        {
            CTheXe:: Xuat();
            cout << BienSo << endl;
        }
        
        int GiaThu()
        {
            return 5000*LoaiThe;
        }

        bool isXeMay()
        {
            return 1;
        }
};

class DSTheXe
{
    private:

        int SoTheXe;
        CTheXe** TX;
        int TongTien;
        int SoLuongXeMay;
        
    public:

        DSTheXe()
        {
            SoTheXe = 0;
            TX = new CTheXe*[0];
            TongTien = 0;
            SoLuongXeMay = 0;
        }

        DSTheXe(int _SoTheXe, int _TongTien, int _SoLuongXeMay)
        {
            SoTheXe = _SoTheXe;
            TX = new CTheXe*[SoTheXe];
            TongTien = _TongTien;
            SoLuongXeMay = _SoLuongXeMay;
        }

        ~DSTheXe()
        {
            for (int i = 0; i < SoTheXe; i++)
                delete TX[i];
            delete [] TX;
        }

        void Nhap()
        {
            cout << "Nhap So Luong The Xe: ";
            cin >> SoTheXe;

            TX = new CTheXe*[SoTheXe];
            int LuaChon = 0;

            cout << "Nhap thong tin the xe: ";
            for (int i = 0; i < SoTheXe; i++)
            {
                do
                {
                    cout << "Nhap thong tin the xe thu " << i + 1 << endl;
                    cout << "Nhap du lieu: " << endl;
                    cout << "Nhap so 1 neu la xe dap " << endl;
                    cout << "Nhap so 2 neu la xe may " << endl;
                    cout << "Nhap lua chon: ";
                    cin >> LuaChon;
                    if (LuaChon != 1 && LuaChon != 2)
                    {
                        cout << "Nhap sai lua chon vui long nhap lai!" << endl;
                    }
                }
                while(LuaChon != 1 && LuaChon != 2);

                switch(LuaChon)
                {
                    case 1:

                        TX[i] = new CTheXeDap;
                        break;

                    case 2:

                        TX[i] = new CTheXeMay;
                        break;
                }

                TX[i]->Nhap();
            }
        }

        void Xuat()
        {
            for (int i = 0; i < SoTheXe; i++)
                TX[i]->Xuat();
        }

        void TongTienThu()
        {
            for (int i = 0; i < SoTheXe; i++)
                TongTien += TX[i]->GiaThu();

            cout << "Tong tien thu duoc: " << TongTien << endl;
        }

        void DemSoLuongXeMay()
        {
            for (int i = 0; i < SoTheXe; i++)
                if(TX[i]->isXeMay())
                    SoLuongXeMay += 1;

            cout << "So luong xe may co trong bai: " << SoLuongXeMay << endl;
        }
};

int main()
{
    DSTheXe UIT; 
    UIT.Nhap();
    UIT.Xuat();
    UIT.TongTienThu();
    UIT.DemSoLuongXeMay();
    return 0;
}