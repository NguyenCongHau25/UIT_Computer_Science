#include <iostream>
#include <string>
using namespace std;

class CBook
{
    private:
        int ID;
        string Name;
        int Publish_Year;
        int SPage;
    public:
        friend class cListBook;

        CBook()
        {
            ID = 0;
            Name = "";
            Publish_Year = 0;
            SPage = 0;
        }

        void setInfo(int c, string t, int y, int pages)
        {
            ID = c;
            Name = t;
            Publish_Year = y;
            SPage = pages;
        }

        void Nhap()
        {
            cout << "Nhap ma sach: ";
            cin >> ID;
            cout << endl;

            cin.ignore();

            cout << "Nhap ten sach: ";
            getline(cin, Name);
            cout << endl;

            cout << "Nhap nam xuat ban: ";
            cin >> Publish_Year;
            cout << endl;

            cout << "Nhap so trang: ";
            cin >> SPage;
        }

        void Xuat()
        {
            cout << ID << "\t|" << Name << "\t|" << Publish_Year << "\t|" << SPage << endl;
        }

};

class cListBook
{
    private:
        int n;
        CBook *a;
    public:
        cListBook(){}
        ~cListBook()
        {
            delete []a;
        }
        void NhapDanhSach()
        {
            cout << "Nhap So Luong Sach: ";
            cin >> n;
            cout << endl;

            a = new CBook[n];
            for (int i = 0; i < n; i++)
                a[i].Nhap();
        }
        void XuatDanhSach()
        {
            cout << "ID" << "\t|" << "Name" << "\t|" << "Public_Year" << "\t|" << "Sum of Pages" << endl;
            for (int i = 0; i < n; i++)
                a[i].Xuat();
        }
        void SachMoiXuatBan()
        {
            CBook max = a[0];
            for (int i = 1; i < n; i++)
                if ( a[i].Publish_Year > max.Publish_Year)
                    max = a[i];
            cout << "Thong tin sach xuat ban gan nhat: \n";
            max.Xuat();
        }

};

int main()
{
    cListBook* L = new cListBook;
    L->NhapDanhSach();
    L->XuatDanhSach();
    L->SachMoiXuatBan();
    return 0;
}