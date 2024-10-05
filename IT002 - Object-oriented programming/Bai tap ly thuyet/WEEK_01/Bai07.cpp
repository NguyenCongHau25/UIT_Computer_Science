#include <iostream>

using namespace std;

struct NGAY
{
    int Date;
    int Month;
    int Year;

};

void Nhap(NGAY &x)
{
    cout << "Nhap ngay: " << endl;
    cin >> x.Date;

    cout << "Nhap Month: " << endl;
    cin >> x.Month;

    cout << "Nhap Year: " << endl;
    cin >> x.Year;
}

void Xuat(NGAY x)
{
    cout << x.Date << "/" << x.Month << "/" << x.Year;
}
bool KtNhuan(NGAY x)
{
    if (x.Year % 4 == 0 && x.Year % 100 != 0)
		return 1;
	if (x.Year % 400 == 0)
		return 1;
	return 0;
}

int SoNgayToiDa(NGAY x)
{
    int LastDay;
    switch (x.Month)
    {
    case 4: case 6: case 9: case 11:
        LastDay = 30;
        break;
    case 2: 
        {
            if (KtNhuan(x))
                LastDay = 29;
            else 
                LastDay = 28;
        }
        break;
    default:
        LastDay = 31;
    }
    return LastDay;
}
bool laNgayThangHopLe(NGAY x)
{
    if (x.Year < 0)
        return 0;
    if (x.Month < 1 || x.Month > 12)
        return 0;
    if (x.Date < 1 || x.Date > SoNgayToiDa(x))
        return 0; 
    return 1;
}
NGAY NextDay(NGAY &x)
{
    x.Date++;
    if (x.Date > SoNgayToiDa(x))
        {
            x.Date = 1;
            x.Month++;
            if (x.Month > 12)
                {
                    x.Month = 1;
                    x.Year++;
                }
        }
    return x;
}


int main()
{
    NGAY x;

    Nhap(x);
    
    if(!laNgayThangHopLe(x))
        cout << "Du lieu khong hop le " << endl;
    else 
    {
        cout << "Ngay ke tiep: " << endl;
        NGAY NgayKeTiep = NextDay(x);
        Xuat(NgayKeTiep);
    }
    
    return 0;
}