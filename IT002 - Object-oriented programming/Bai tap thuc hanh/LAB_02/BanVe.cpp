#include <iostream>

using namespace std;

class VE
{  
    private:
        int SoLuongVe;
        int SoLuongTroChoi;
        int TongTroChoi;
        int TongTien;
    public:
        VE()
        {
            SoLuongVe = 0;
            SoLuongTroChoi = 0;
            TongTroChoi = 0;
        }
        void Nhap();
        void XuatTongTien();
};

void VE::Nhap()
{
    cout << "Nhap vao so luong ve: ";
    cin >> SoLuongVe;
    for (int i = 1; i <= SoLuongVe; i++)
    {
        cout << "Nhap vao so troi choi nguoi thu " << i << ": ";
        cin >> SoLuongTroChoi;
        TongTroChoi += SoLuongTroChoi;
    }
}

void VE::XuatTongTien()
{
    TongTien = SoLuongVe*70000 + TongTroChoi*20000;
    cout << TongTien << "VND";
}


int main()
{
    VE A;
    A.Nhap();
    A.XuatTongTien();
    return 0;

}