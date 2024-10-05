#include <iostream>
#include <string.h>
using namespace std;

class Candidate
{
    private:
        string id;
        string name;
        string date_month;
        float Toan;
        float Van;
        float Anh;
    public:
        Candidate()
        {

        };
        void Nhap();
        float TinhDiemTong();
        bool TongLonHon15();
        void InThongTinThiSinh();
        ~Candidate(){};
};

class TestCandidate
{
    private:
        int n;
        Candidate *a;
    public:
        TestCandidate(){}
        void NhapCandidate();
        void LonHon15();
        ~TestCandidate()
        {
            delete []a;
        }
    
};



void Candidate::Nhap()
{
    cin.ignore();
    //cout << "\nNhap ma so: ";
    getline(cin, id);

   //cout <<"\nNhap ten: ";
    getline(cin, name);

    //cout <<"\nNhap ngay thang nam sinh: ";
    getline(cin, date_month);

    //cout << "\nNhap diem Toan: ";
    cin >> Toan;

    //cout << "\nNhap diem Van: ";
    cin >> Van;

    //cout << "\nNhap diem Anh: ";
    cin >> Anh;
}

float Candidate::TinhDiemTong()
{
    return Toan + Van + Anh;
}

bool Candidate::TongLonHon15()
{
    return TinhDiemTong() > 15;
}

void TestCandidate::NhapCandidate()
{
    cin >> n;

    a = new Candidate[n];
    for (int i = 0; i < n; i++)
        a[i].Nhap();

}

void Candidate::InThongTinThiSinh()
{
    cout << id  << "\t" << name << "\t" << date_month << "\t" << TinhDiemTong() << "\n";
}

void TestCandidate::LonHon15()
{
    for (int i = 0; i < n; i++)
    {
      if (a[i].TongLonHon15())
            a[i].InThongTinThiSinh();
    }
}

int main()
{
    TestCandidate *L = new TestCandidate;
    L -> NhapCandidate();
    L -> LonHon15();
    return 0;
}