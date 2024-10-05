#include <iostream>
using namespace std;

class PhanSo
{
    private:
        int tuso;
        int mauso;
    public:
        PhanSo(int t = 0, int m = 1);
        PhanSo(const PhanSo &p);
        int LayTu();
        int LayMau();
        void GanTu(int t);
        void GanMau(int m);
        void Nhap();
        void Xuat();
        bool operator>(PhanSo);
        PhanSo operator+(PhanSo);
        PhanSo operator-(PhanSo);
};

class DSPhanSo
{
    private:
        int n;
        PhanSo* a;
    public:
        DSPhanSo(){};
        void NhapDSPhanSo();
        void PhanSoLonNhat();
        void TongDSPhanSo();
        ~DSPhanSo(){};
};

PhanSo::PhanSo(int t, int m)
{
    tuso = t;
    mauso = m;
};

PhanSo::PhanSo(const PhanSo &p)
{
    tuso = p.tuso;
    mauso = p.mauso;
}

int PhanSo::LayTu()
{
    return tuso;
}

int PhanSo::LayMau()
{
    return mauso;
}

void PhanSo::GanTu(int t)
{
    tuso = t;
}

void PhanSo::GanMau(int m)
{
    mauso = m;
}

void PhanSo::Nhap()
{
    cout <<"Nhap tu so: ";
    cin >> tuso;

    cout << endl;
    cout << "Nhap mau so: ";
    cin >> mauso;
}

void PhanSo::Xuat()
{
    cout << tuso << "/" << mauso;
}

bool PhanSo::operator> (PhanSo b)
{
    return (double) tuso/mauso > (double) b.tuso/b.mauso;
}

PhanSo PhanSo::operator+(PhanSo b)
{
    b.tuso = tuso*b.mauso + b.tuso*mauso;
    b.mauso = mauso*b.mauso;
    return b;
}

PhanSo PhanSo::operator-(PhanSo b)
{
    b.tuso = tuso*b.mauso - b.tuso*mauso;
    b.mauso = mauso*b.mauso;
    return b;
}

void DSPhanSo::NhapDSPhanSo()
{
    cout << "Nhap so luong phan so: ";
    cin >> n;

    a = new PhanSo[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan so thu " << i + 1<< ": " << endl;
        a[i].Nhap();
    };
}

void DSPhanSo::PhanSoLonNhat()
{
    PhanSo Max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > Max)
            Max = a[i];
    Max.Xuat();
}

void DSPhanSo::TongDSPhanSo()
{
    PhanSo Sum = 0;
    for (int i = 0; i < n; i++)
        Sum = Sum + a[i];
    Sum.Xuat();
}

int main()
{
    DSPhanSo A;
    A.NhapDSPhanSo();
    cout << "Phan so co gia tri lon nhat: ";
    A.PhanSoLonNhat();
    cout << "\nTong cac phan so: ";
    A.TongDSPhanSo();

    return 0;
}
