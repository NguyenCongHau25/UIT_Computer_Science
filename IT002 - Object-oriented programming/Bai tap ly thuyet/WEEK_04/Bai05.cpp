#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class cHocSinh
{
    private:
        string Id;
        string Name;
        string GioiTinh;
        int NamSinh;
        int DTB;
        
    public:
        static int count;
        cHocSinh(){};

        cHocSinh(string _Id, string _Name, string _GioiTinh, int _NamSinh, int _DTB)
        {
            Id = _Id;
            Name = _Name;
            GioiTinh = _GioiTinh;
            NamSinh = _NamSinh;
            DTB = _DTB;
            this -> count++;
        };
        
        void Nhap();
        static int Getcount()
        {
            return count;
        }
        void SoSanhDTB(cHocSinh b);
        void SoSanhTuoi(cHocSinh b);    
        ~cHocSinh(){};   
};
int cHocSinh::count = 0;

void cHocSinh::Nhap()
{
    cin >> Id;
    cin >> Name;
    cin >> GioiTinh;
    cin.ignore();
    cin >> NamSinh;
    cin >> DTB;
    this -> count++;
}

void cHocSinh::SoSanhDTB(cHocSinh b)
{
    if (DTB - b.DTB > 0)
            cout << Name;
    else  
            cout << b.Name;
    cout << endl;

}

void cHocSinh::SoSanhTuoi(cHocSinh b)
{  
    if (NamSinh - b.NamSinh > 0)
                cout << Name;
    else
            cout << b.Name;
}

int main()
{
    cHocSinh a;
    cHocSinh b;

    a.Nhap();
    b.Nhap();

    a.SoSanhDTB(b);
    a.SoSanhTuoi(b);
    cout << endl;
    cout << cHocSinh::Getcount();

    return 0;
}