#include <iostream>
#include <string>
using namespace  std;

class cSINHVIEN
{
    protected:
        string MSSV;
        string HoTen;
        string DiaChi;
        int SoTinChi;
        float DiemTrungBinh;
    public:
        cSINHVIEN()
        {
            MSSV = ' ';
            HoTen = ' ';
            DiaChi = ' ';
            SoTinChi = 0;
            DiemTrungBinh = 0;
        }
        ~cSINHVIEN(){}
        void NhapThongTin()
        {
            cout << "Nhap mssv: ";
            getline(cin, MSSV);
            cout << "\nNhap Ho Ten: ";
            getline(cin, HoTen);
            cout << "\nNhap dia chi: ";
            getline(cin, DiaChi);
            cout << "\nNhap so tin chi: ";
            cin >> SoTinChi;
            cout <<  "\nNhap diem trung binh: ";
            cin >> DiemTrungBinh;
        }
        void XuatThongTin()
        {
            cout << MSSV << "\t|" << HoTen << "\t|" << DiaChi << "\t|" << SoTinChi << "\t|" << DiemTrungBinh << "\t|";
        }
};

class cSINHVIENCAODANG: public cSINHVIEN
{
    private:
        float DiemThiTotNghiep;
    public:
        void Nhap()
        {
            cSINHVIEN::NhapThongTin();
            cout << "\nNhap diem thi tot nghiep: ";
            cin >> DiemThiTotNghiep;
            cin.ignore();
        }
        void Xuat()
        {
            cSINHVIEN::XuatThongTin();
            cout << "\t|" << DiemThiTotNghiep << endl;
        }
        bool isTotNghiep()
        {
            return ((SoTinChi >= 120) && (DiemTrungBinh >= 5) && (DiemThiTotNghiep >= 5))? 1 : 0;
        }
};

class cSINHVIENDAIHOC: public cSINHVIEN
{
    private:
        string TenLuanVan;
        float DiemLuanVan;
    public:
        void Nhap()
        {
            cSINHVIEN::NhapThongTin();
            cin.ignore();
            cout << "\nNhap ten luan van: ";
            getline(cin, TenLuanVan);
            cout << "\nNhap diem luan van: ";
            cin >> DiemLuanVan;
        }
        void Xuat()
        {
            cSINHVIEN::XuatThongTin();
            cout << "\t|" << TenLuanVan << "\t|" << DiemLuanVan << endl;
        }
        bool isTotNghiep()
        {
            return ((SoTinChi >= 170) && (DiemTrungBinh >= 5) && (DiemLuanVan >= 5))? 1 : 0;
        }
        
};


int main()
{
    cSINHVIENCAODANG A;
    cSINHVIENDAIHOC B;

    cout << "Nhap thong tin hai sinh vien: " << endl;
    A.Nhap();
    B.Nhap();

    cout << "Thong tin hai sinh vien" << endl;
    cout<<"MSSV\t|HoTen\t|Diachi\t|So tin chi\t|Thong Tin Diem\n";
    A.Xuat();
    B.Xuat();

    if(A.isTotNghiep())
        cout << "A Du dieu kien tot nghiep" << endl;
    else cout << "A khong du dieu kien tot nghiep" << endl;

    if (B.isTotNghiep())
        cout << "B Du dieu kien tot nghiep" << endl;
    else   
        cout << "B khong du dieu kien tot nghiep" << endl;

    return 0;
}