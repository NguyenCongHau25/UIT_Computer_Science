#include <iostream>
using namespace std;

class CDate
{
    private:
        int ngay, thang, nam;
    public:
        CDate(){}
        ~CDate(){}
        friend istream& operator>>(istream& is, CDate &a)
        {
            is >> a.ngay >> a. thang >> a.nam;
            return is;
        }

        friend ostream& operator<<(ostream& os, CDate &a)
        {
            os << a.ngay << "/" << a.thang << "/" << a.nam << endl;
            return os;
        }

        int songay()
        {
            if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
                return 31;
            else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
                return 30;
            else if ((nam%4==0&&nam%100!=0)||nam%400==0)
                return 29;
            else
                return 28;
        }

        CDate operator+(int n)
        {
            CDate a = *this;
            a.ngay += n;
            while (a.ngay > a.songay())
            {
                a.ngay -= a.songay();
                a.thang++;
                if (a.thang > 12)
                {
                    a.thang -= 12;
                    a.nam++;
                }
            }
            return a;
        }

        CDate operator-(int n)
        {
            CDate a = *this;
            a.ngay -=n;
            while (a.ngay < 1)
            {
                a.thang--;
                if (a.thang < 1)
                {
                    a.thang += 12;
                    a.nam--;
                }
                a.ngay += a.songay();
            }
            return a;
        }
};

int main()
{
    CDate SinhNhat;
    cin >> SinhNhat;
    cout << SinhNhat;
    CDate A;
    A = SinhNhat + 30;
    cout << A;
    A = SinhNhat - 30;
    cout << A;
    return 0;
}