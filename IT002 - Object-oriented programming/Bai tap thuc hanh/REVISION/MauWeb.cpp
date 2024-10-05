#include <iostream>
using namespace std;

class ThanhPhan
{
protected:
    int x;
    int y;
    int d;
    int r;

public:
    virtual void Nhap();
    virtual int LayMauNen();
    virtual int LayMauChu();
};
void ThanhPhan::Nhap()
{
    cout <<"Nhap toa do" << endl;
    cin >> x >> y;
    cout <<"Nhap kich thuoc";
    cin >> d >> r;
}
int ThanhPhan::LayMauNen()
{
    return 0;
}
int ThanhPhan::LayMauChu()
{
    return 0;
}

class NutNhan : public ThanhPhan
{
private:
    char NoiDung[50];
    int MauChu;
    int MauNen;
    char Hinh[50];

public:
    void Nhap();
    int LayMauNen();
    int LayMauChu();
};
void NutNhan::Nhap()
{
    ThanhPhan::Nhap();
    int chon = 0;
    do
    {
        cout <<"Chon 1 de dung hinh anh, 2 de hien thi chu(mau chu, mau nen)";
        cin >> chon;
        switch (chon)
        {
        case 1:
            cout <<"Nhap duong dan anh";
            fflush(stdin);
            gets(Hinh);
            MauNen = MauChu = 0;
            break;
        case 2:
            cout <<"Nhap noi dung hien thi";
            fflush(stdin);
            gets(NoiDung);
            MauChu = MauNen = 0;
            do
            {
                cout <<"Chon mau 1.Red 2.Orange 3.Yellow 4.Spring Green 5.Green 6.Turquoise 7.Cyan 8.Ocean 9.Blue 10.Violet 11.Magenta 12.Raspberry";
                cout <<"\nNhap mau chu va mau nen";
                cin >> MauChu >> MauNen;
            } while (MauChu > 0 && MauNen > 0 && MauChu < 12 && MauNen < 12);
            break;
        }  
    }while (chon > 2 || chon < 1);
}
    int NutNhan::LayMauNen()
    {
        return MauNen;
    }
    int NutNhan::LayMauChu()
    {
        return MauChu;
    }

    class Nhan : public ThanhPhan
    {
    private:
        char NoiDung[50];
        int MauChu;
        int MauNen;

    public:
        void Nhap();
        int LayMauNen();
        int LayMauChu();
    };
    void Nhan::Nhap()
    {
        ThanhPhan::Nhap();
        cout <<"Nhap noi dung hien thi";
        fflush(stdin);
        gets(NoiDung);
        MauChu = MauNen = 0;
        do
        {
            cout <<"Chon mau 1.Red 2.Orange 3.Yellow 4.Spring Green 5.Green 6.Turquoise 7.Cyan 8.Ocean 9.Blue 10.Violet 11.Magenta 12.Raspberry";
            cout <<"\nNhap mau chu va mau nen";
            cin >> MauChu >> MauNen;
        } while (MauChu > 0 && MauNen > 0 && MauChu < 12 && MauNen < 12);
    }
    int Nhan::LayMauNen()
    {
        return MauNen;
    }
    int Nhan::LayMauChu()
    {
        return MauChu;
    }

    int main()
    {
        ThanhPhan *A[50];
        int i, n, t;
        // Nhập danh sách các thành phần web
        cout << "Nhap so thanh phan";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cout << "\nChon \n1 de nhap Button \n2 de nhap Label";
            cin >> t;
            switch (t)
            {
            case 1:
                A[i] = new NutNhan();
                break;
            case 2:
                A[i] = new Nhan();
                break;
            }
            A[i]->Nhap();
        }
        // Kiểm tra màu nền và màu chữ của A[0] có phối màu bổ túc trực tiếp
        int color = A[0]->LayMauNen();
        if (color > 0)
        {
            int colortext = A[0]->LayMauChu();
            if (color <= 6)
            {
                if (colortext == (color + 6))
                    cout <<"Mau nen va mau chu phoi bo tuc truc tiep";
            }
            else
            {
                if (colortext == (color - 6))
                    cout <<"Mau nen va mau chu phoi bo tuc truc tiep";
            }
        }

        // Kiểm tra phối màu đơn sắc
        int check = 1;
        color = A[0]->LayMauNen();
        for (i = 1; i < n && A[i]->LayMauNen() == color; i++)
            if (i == n)
                cout <<"Phoi mau sac " << endl;
        // Kiểm tra phối màu tương đồng
        color = A[0]->LayMauNen();
        if (color > 1 && color < 12)
        {
            for (i = 1; i < n; i++)
            {
                int mau = A[i]->LayMauNen();
                if ((mau != color) && (mau != color - 1) && (mau != color + 1))
                    break;
            }
            if (i == n)
                cout <<"phoi mau tuong dong";
        }
        else if (color == 1)
        {
            for (i = 1; i < n; i++)
            {
                int mau = A[i]->LayMauNen();
                if ((mau != 1) && (mau != 12) && (mau != 2))
                    break;
            }
            if (i == n)
                cout <<"Phoi mau tuong dong";
        }
        else // color=12
        {
            for (i = 1; i < n; i++)
            {
                int mau = A[i]->LayMauNen();
                if ((mau != 12) && (mau != 11) && (mau != 1))
                    break;
            }
            if (i == n)
                cout <<"Phoi mau tuong dong";
        }
        // Kiểm tra phối màu bổ túc trực tiếp
        color = A[0]->LayMauNen();
        int check1 = 0;
        int check2 = 0;
        if (color <= 6)
        {
            check1 = color;
            check2 = color + 6;
        }
        else
        {
            check1 = color - 6;
            check2 = color;
        }
        for (i = 1; i < n; i++)
        {
            int mau = A[i]->LayMauNen();
            if (mau != check1 && mau != check2)
                break;
        }
        if (i == n)
            cout <<"Phoi mau bo tuc truc tiep";
    }

