#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CCanHo
{
    protected:

        string DiaChi;
        int DatCoc;
        int TienThue;
        bool TinhTrang;

    public:

        CCanHo(){}

        virtual ~CCanHo(){}

        virtual void Nhap()
        {
            cout << "Nhap Dia chi: " ;
            cin.ignore();
            getline(cin, DiaChi);
            cout << "Nhap tien coc: ";
            cin >> DatCoc;
            cout << "Nhap tien thue: ";
            cin >> TienThue;
            cout << "Nhap tinh trang can ho (0. Con trong, 1. Dang thue): ";
            cin >> TinhTrang;
            cout << endl;
        }

        virtual void Xuat()
        {
            cout << DiaChi << setw(20) << DatCoc << "\t" << TienThue << "\t" << TinhTrang << "\t";
        }

        virtual int GetTienThue()
        {
            return TienThue;
        }

        virtual bool GetTinhTrang()
        {
            return TinhTrang;
        }

        virtual bool isChungCu()
        {
            return 0;
        }
};

class CChungCu: public CCanHo
{
    private:

        int Tang;

    public:

        CChungCu(){}

        ~CChungCu(){}

        void Nhap()
        {
            CCanHo:: Nhap();
            cout << "Nhap vi tri tang cua can ho: ";
            cin >> Tang;
            cout << endl;
        }

        void Xuat()
        {
            CCanHo:: Xuat();
            cout << setw(15) <<  Tang << endl;
        }

        bool isChungCu()
        {
            return 1;
        }
};

class CThuong: public CCanHo
{
    private:

        int SoTang;

    public:

        void Nhap()
        {
            CCanHo:: Nhap();
            cout << "Nhap so tang cua can ho: ";
            cin >> SoTang;
        }

        void Xuat()
        {
            CCanHo:: Xuat();
            cout << SoTang << endl;
        }
};

class DSCanHo
{
    private:
        int SoLuongCanHo;
        CCanHo **CH;
        int TongTienThue;
    public:
        
        DSCanHo()
        {
            SoLuongCanHo = 0;
            CH = new CCanHo*[0];
            TongTienThue = 0;
        }

        DSCanHo(int _SoLuongCanHo, int _TongTienThue)
        {
            SoLuongCanHo = _SoLuongCanHo;
            CH = new CCanHo*[SoLuongCanHo];
            TongTienThue = _TongTienThue;
        }

        ~DSCanHo()
        {
            for (int i = 0; i < SoLuongCanHo; i++)
                delete CH[i];
            delete []CH;
        }

        void Nhap()
        {
            cout << "Nhap so luong can ho: " << endl;
            cin >> SoLuongCanHo;

            CH = new CCanHo*[SoLuongCanHo];
            int LuaChon;

            cout << "Nhap thong tin can ho: ";
            for (int i = 0; i < SoLuongCanHo; i++)
            {
                do
                {                
                    cout << "Nhap loai can ho (1. Chung Cu, 2. Can ho thuong): ";
                    cin >> LuaChon;
                    if (LuaChon != 1 && LuaChon != 2)
                        cout << "Nhap sai vui long nhap lai!" << endl;
                }
                while(LuaChon != 1 && LuaChon != 2);

                switch(LuaChon)
                {
                    case 1:
                        CH[i] = new CChungCu;
                        break;
                    case 2:
                        CH[i] = new CThuong;
                        break;
                }
                CH[i]->Nhap();
            }
        }

        void Xuat()
        {
            for (int i = 0; i < SoLuongCanHo; i++)
            {
                CH[i]->Xuat();
            }
        }

        void DemCanHoDangThue()
        {
            int CanHoChungCuDangThue = 0;
            int CanHoThuongDangThue = 0;
            for (int i = 0; i < SoLuongCanHo; i++)
            {
                if(CH[i]->GetTinhTrang())
                {
                    if (CH[i]->isChungCu())
                        CanHoChungCuDangThue++;
                    else
                        CanHoThuongDangThue++;
                }
            }
            cout << "So can ho chung cu dang duoc thue: " << CanHoChungCuDangThue << endl;
            cout << "So can ho thuong dang duoc thue: " << CanHoThuongDangThue << endl;
        }

        void DemCanHoDangTrong()
        {
            int CanHoChungCuDangTrong = 0;
            int CanHoThuongDangTrong = 0;
            for (int i = 0; i < SoLuongCanHo; i++)
            {
                if(!CH[i]->GetTinhTrang())
                {
                    if (CH[i]->isChungCu())
                        CanHoChungCuDangTrong++;
                    else
                        CanHoThuongDangTrong++;
                }
            }
            cout << "So can ho chung cu dang trong: " << CanHoChungCuDangTrong << endl;
            cout << "So can ho thuong dang trong: " << CanHoThuongDangTrong << endl;
        }
        
        void TinhTienThue()
        {
            for (int i = 0; i < SoLuongCanHo; i++)
                if (CH[i]->GetTinhTrang() == 1)
                    TongTienThue += CH[i]->GetTienThue();
            cout << "So tien thue nha cong ty thu duoc moi thang: " << TongTienThue << endl;
        }
};

int main()
{
    DSCanHo BeasCon;
    BeasCon.Nhap();
    BeasCon.Xuat();
    BeasCon.TinhTienThue();
    BeasCon.DemCanHoDangThue();
    BeasCon.DemCanHoDangTrong();

    return 0;
}