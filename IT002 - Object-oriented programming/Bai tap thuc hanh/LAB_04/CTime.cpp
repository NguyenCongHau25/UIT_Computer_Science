#include <iostream>
using namespace std;

class CTimeSpan
{
    private:
        int Gio, Phut, Giay;
    public: 
        CTimeSpan(int H = 0, int M = 0, int S = 0)
        {
            Gio = H;
            Phut = M;
            Giay = S;
        }

        ~CTimeSpan(){}

        friend istream &operator >>(istream &in, CTimeSpan &DATA)
        {
            cout << "Nhap vao so gio: ";
            in >> DATA.Gio;
            cout << "Nhap vao so phut: ";
            in >> DATA.Phut;
            cout << "Nhap vao so giay: ";
            in >> DATA.Giay;

            return in;
        }
        friend ostream &operator <<(ostream &out, CTimeSpan &DATA)
        {
            while (DATA.Giay >= 60)
            {
                DATA.Giay = DATA.Giay - 60;
                DATA.Phut++;
            }
            while (DATA.Phut >= 60)
            {
                DATA.Phut = DATA.Phut - 60;
                DATA.Gio++;
            }

            out << DATA.Gio << "h" << DATA.Phut << "m" << DATA.Giay << "s";
            return out;
        }

        long TongSoThoiGian()
        {
            return Gio*3600 + Phut*60 + Giay;
        }

        int GetGio()
        {
            return Gio;
        }
        int GetPhut()
        {
            return Phut;
        }
        int GetGiay()
        {
            return Giay;
        }

        int SetGio(int h)
        {
            Gio = h;
            return Gio;
        }

        int SetPhut(int m)
        {
            Phut = m;
            return Phut;
        }

        int SetGiay(int s)
        {
            Giay = s;
            return Giay;
        }

        bool operator>(CTimeSpan &DATA)
        {
            if (this->TongSoThoiGian() > DATA.TongSoThoiGian())
                return 1;
            return 0;
        }

        bool operator>=(CTimeSpan &DATA)
        {
            if (this->TongSoThoiGian() >= DATA.TongSoThoiGian())
                return 1;
            return 0;
        }

        bool operator<(CTimeSpan &DATA)
        {
            if (this->TongSoThoiGian() < DATA.TongSoThoiGian())
                return 1;
            return 0;
        }

        bool operator<=(CTimeSpan &DATA)
        {
            if (this->TongSoThoiGian() <= DATA.TongSoThoiGian())
                return 1;
            return 0;
        }

        bool operator==(CTimeSpan &DATA)
        {
            if (this->TongSoThoiGian() == DATA.TongSoThoiGian())
                return 1;
            return 0;
        }

        bool operator!=(CTimeSpan &DATA)
        {
            if (this->TongSoThoiGian() != DATA.TongSoThoiGian())
                return 1;
            return 0;
        }
};

class CTime
{
    private:
        int Gio, Phut, Giay;
    public:
        CTime(){};
        CTime(int h, int m, int s)
        {
            this->Gio = h;
            this->Phut = m;
            this->Giay = s;
        };
        CTime(const CTime &A)
        {
            this->Gio = A.Gio;
            this->Phut = A.Phut;
            this->Giay = A.Giay;
        };

        ~CTime(){}

        int ThoiGianSangGiay()
        {
            int s = 0;
            s += this->Giay;
            s += this->Phut * 60;
            s += this->Gio * 3600;

            return s;
        }

        CTime GiaySangThoiGian(int sec)
        {
            CTime Temp;

            Temp.Gio = (sec/3600)%24;
            Temp.Phut = (sec%3600)/60;
            Temp.Giay = (sec%3600%60);

            return Temp;
        }

        friend istream &operator>>(istream &in, CTime &DATA)
        {
            cout << "Nhap gio: ";
            in >> DATA.Gio;
            cout << "Nhap phut: ";
            in >> DATA.Phut;
            cout << "Nhap giay: ";
            in >> DATA.Giay;

            return in;
        }

        friend ostream &operator<<(ostream &out, CTime &DATA)
        {
            out << DATA.Gio << "h" << DATA.Phut << "m" << DATA.Giay << "s";

            return out;
        }

        CTime operator+(int &a)
        {
            CTime Temp(*this);
            Temp.Giay += a;
            if (Temp.Giay > 59)
            {
                Temp.Giay -= 60;
                Temp.Phut++;
                if (Temp.Phut > 59)
                {
                    Temp.Phut -= 60;
                    Temp.Gio++;
                    if (Temp.Gio > 23)
                        Temp.Gio = 0;
                }
                
            }
            return Temp;
        }

/*     CTime operator-(int a)
        {
            CTime Temp = *this;
            Temp.Giay -= a;
            if (Temp.Giay < 0)
            {
                Temp.Phut--;
                if (Temp.Phut < 0)
                {
                    Temp.Phut += 59;
                    Temp.Gio--;
                    if (Temp.Gio < 0)
                    {
                        Temp.Gio += 23;
                    }
                }
            }
            return Temp;
        }
*/
        CTime operator-(int &a)
        {
            int s = 0;
            s += this->Giay;
            s += this->Phut * 60;
            s += this->Gio * 3600;

            s -= a;
            CTime Temp;
            Temp.Gio = (s/3600)%24;
            Temp.Phut = (s % 3600)/60;
            Temp.Giay = (s % 3600) % 60;

            return Temp;
        }

        friend CTime operator+(CTime a, CTimeSpan b)
        {
            int sec_1 = a.ThoiGianSangGiay();
            int sec_2 = b.GetGio()*3600+b.GetPhut()*60+b.GetGiay();

            sec_1 = sec_1 + sec_2;

            CTime Temp; 
            Temp.Gio = (sec_1/3600)%24;
            Temp.Phut = (sec_1%3600)%60;
            Temp.Giay = sec_1%3600%60;
            return Temp;
        }

        CTimeSpan operator-(CTime &a)
        {
            CTimeSpan Temp;
            Temp.SetGio(abs(this->Gio - a.Gio));
            Temp.SetPhut(abs(this->Phut - a.Phut));
            Temp.SetGiay(abs(this->Giay - a.Giay));
            return Temp;
        }

        CTime operator++()
        {
            CTime Temp(*this);
            ++Temp.Giay;
            if (Temp.Giay > 59)
            {
                ++Temp.Phut;
                if (Temp.Phut > 59)
                {
                    ++Temp.Gio;
                    if (Temp.Gio > 23)
                        Temp.Gio = 0;
                    Temp.Phut -= 60;
                }
                Temp.Giay -= 60;
            }
            return Temp;
        }

        CTime operator--()
        {
            CTime Temp(*this);
            --Temp.Giay;
            if (Temp.Giay == -1)
            {
                Temp.Giay = 0;
                --Temp.Phut;
                if (Temp.Phut == -1)
                {
                    Temp.Phut = 0;
                    --Temp.Gio;
                    if (Temp.Gio == -1)
                    {
                        Temp.Gio = 23;
                        Temp.Phut = 59;
                        Temp.Giay = 59;
                    }
                    Temp.Phut -= 1;
                }
            }
            return Temp;
        }

};


int main()
{
    CTime ThoiGian;
    cout << "Nhap vao  du lieu thoi gian: " << endl;
    cin >> ThoiGian;
    cout << "Thoi gian sau khi nhap la: " << ThoiGian << endl;

    cout << "Nhap vao giay cong them: ";
    int GiayCongThem;
    cin >> GiayCongThem;
    CTime SauKhiCongGiay = ThoiGian + GiayCongThem;
    cout << "Thoi gian sau khi cong them la: " << SauKhiCongGiay << endl;

    cout << "Nhap vao giay tru di: ";
    int GiayTruDi;
    cin >> GiayTruDi;
    CTime SauKhiTruGiay = ThoiGian - GiayTruDi;
    cout << "Thoi gian sau khi tru di la: " << SauKhiTruGiay << endl;

    cout << "Nhap vao du lieu thoi gian muon tru: " << endl;
    CTime ThoiGianTru;
    cin >> ThoiGianTru;
    cout << "Du lieu vua nhap la: " << ThoiGianTru << endl;
    CTimeSpan KhoangThoiGianTru;
    KhoangThoiGianTru =  ThoiGian - ThoiGianTru;
    cout << "Tru hai thoi gian voi nhau ta duoc: " << KhoangThoiGianTru << endl;

    cout << "Nhap vao du lieu khoang thoi gian muon cong: " << endl;
    CTimeSpan KhoangThoiGianCong;
    cin >> KhoangThoiGianCong;
    cout << "Du lieu vua nhap la: " << KhoangThoiGianCong<< endl;
    CTime ThoiGianCong;
    ThoiGianCong =  ThoiGian + KhoangThoiGianCong;
    cout << "Cong hai thoi gian voi nhau ta duoc: " << ThoiGianCong << endl;

    CTime CongThemGiay = ++ThoiGian;
    cout << "Thoi gian sau khi tang 1 giay: " << CongThemGiay << endl;

    CTime TruDiGiay = --ThoiGian;
    cout << "Thoi gian sau khi tru di 1 giay: " << TruDiGiay << endl;

    return 0;
}