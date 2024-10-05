#include <iostream>
#include <string>
using namespace std;

class SIM
{
    protected:
        string seri;
        string nm;
        string sdt;
        bool trangthai;
    public:
        virtual~SIM(){};
        virtual void Nhap();
        virtual void Xuat();
        virtual double TinhKM() = 0;
        string GetTenNM();
        virtual int GetSoGN() = 0;
        virtual bool isTT();
};

class TT: public SIM
{
    private:
        int SoDu;
        int SoNap;
    public:
        void Nhap();
        void Xuat();
        double TinhKM();
        int GetSoGN();
        bool isTT();
};

class TS: public SIM
{
    private:
        string Cuoc;
        int SoGN;
    public:
        void Nhap();
        void Xuat();
        double TinhKM();
        int GetSoGN();
};

class QuanLy
{
    private:
        int n;
        SIM**S;
    public:
        ~QuanLy();
        void Nhap();
        void Xuat();
        void TinhTongKM();
        void TinhGNMax();
};

void SIM::Nhap()
{
    getline(cin,seri);
    cout << "+001: verizon, +002: AT&T, +003: sprint " << endl;
    getline(cin, nm);
    getline(cin, sdt);
    cout << "0. Non-actived, 1. Active" << endl;
    cin >> trangthai;
}

void SIM::Xuat()
{
    cout << seri << nm << sdt << trangthai << endl;
}

string SIM::GetTenNM()
{
    return nm;
}

void TT::Nhap()
{
    SIM::Nhap();
    cin >> SoDu >> SoNap;
}

void TT::Xuat()
{
    SIM::Xuat();
    cout << SoDu << SoNap;
}

double TT::TinhKM()
{
    int TienNap;
    cin >> TienNap;

    if (SoNap < 5) 
        return TienNap*0.1;
    if (SoNap >= 5 && SoNap <= 10) 
        return TienNap*0.2;
    if (SoNap > 10) 
        return TienNap*0.5;
}

int TT::GetSoGN()
{
    return 0;
}

void TS::Nhap()
{
    SIM::Nhap();
    cin >> SoGN;
    getline(cin, Cuoc);
}

void TS::Xuat()
{
    SIM::Xuat();
    cout << Cuoc << SoGN << endl;
}

double TS::TinhKM()
{
    int TienTra;
    cin >> TienTra;
    if (Cuoc == "LCAP") 
        return 0.05*TienTra;
    if (Cuoc == "MCAP") 
        return 0.1*TienTra;
    if (Cuoc == "HCAP") 
        return 0.15*TienTra;
}

int TS::GetSoGN()
{
    return SoGN;
}

void QuanLy::Nhap()
{
    cin >> n;
    S = new SIM*[n];
    int LC;
    for (int i = 0; i < n; i++)
    {
        cin >> LC;
        if (LC == 1)
            S[i] = new TT;
        else 
            S[i] = new TS;
        S[i]->Nhap();
    }
}

void QuanLy::Xuat()
{
    for (int i = 0; i < n; i++)
        S[i]->Xuat();
}

QuanLy::~QuanLy()
{
    for (int i = 0; i < n; i++)
        delete S[i];
    delete[]S;
}

bool SIM::isTT()
{
    return 0;
}
bool TT::isTT()
{
    return 1;
}

void QuanLy::TinhTongKM()
{
    double Tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (S[i]->isTT() && S[i]->GetTenNM() == "AT&T")
            Tong += S[i]->TinhKM();
    }
    cout << Tong;
}

void QuanLy::TinhGNMax()
{
    int Max = S[0]->GetSoGN();
    for (int i = 1; i < n; i++)
        if (Max < S[i]->GetSoGN())
            Max = S[i]->GetSoGN();
    for (int i = 0; i < n; i++)
    {
        if (S[i]->GetSoGN() == Max)
            S[i]->Xuat();
    }
}

int main()
{
    QuanLy A;
    A.Nhap();
    A.Xuat();
    A.TinhTongKM();
    A.TinhGNMax();
    return 0;
}