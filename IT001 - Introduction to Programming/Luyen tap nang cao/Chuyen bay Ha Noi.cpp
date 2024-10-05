#include <iostream>
#include <cstring>
using namespace std;

struct NGAY
{
    int Ngay;
    int Thang;
    int Nam;
};

typedef struct CHUYENBAY
{
    char Ma[35];
    NGAY Ngay_bay;
    float Gio_bay;
    char Noi_den[35];
}CB;

void mot_chuyen_bay(CB &Chuyen_bay)
{
 
    cin.getline(Chuyen_bay.Ma,35);
    cin >> Chuyen_bay.Ngay_bay.Ngay >> Chuyen_bay.Ngay_bay.Thang >> Chuyen_bay.Ngay_bay.Nam;
    cin >> Chuyen_bay.Gio_bay;
    cin.ignore();
    cin.getline(Chuyen_bay.Noi_den,35);
}

void nhieu_chuyen_bay(CB Chuyen_bay[], int &n)
{
    for (int i=0; i<n; i++)
        mot_chuyen_bay(Chuyen_bay[i]);
}

void chuyen_bay_HN(CB Chuyen_bay[], int n)
{
    char s[]={'H','a',' ','N','o','i','\0'};
    for (int i=0; i<n; i++)
        if (strcmp(Chuyen_bay[i].Noi_den,s)==0)
            cout << Chuyen_bay[i].Ma << '\t' << Chuyen_bay[i].Ngay_bay.Ngay <<"/"<< Chuyen_bay[i].Ngay_bay.Thang <<"/"<< Chuyen_bay[i].Ngay_bay.Nam << '\t' 
            << Chuyen_bay[i].Gio_bay << '\t' << Chuyen_bay[i].Noi_den << endl;

}

float thoi_gian_lau_nhat(CB Chuyen_bay[], int n)
{
    float max=Chuyen_bay[0].Gio_bay;
    for (int i=0; i<n; i++)
        if (Chuyen_bay[i].Gio_bay>max)
            max=Chuyen_bay[i].Gio_bay;
    return max;
}

void CB_TG_Lau_Nhat(CB Chuyen_bay[], int n)
{
    for (int i=0; i<n; i++)
        if (Chuyen_bay[i].Gio_bay==thoi_gian_lau_nhat(Chuyen_bay,n))
            cout << Chuyen_bay[i].Ma << '\t' << Chuyen_bay[i].Ngay_bay.Ngay <<"/"<< Chuyen_bay[i].Ngay_bay.Thang <<"/"<< Chuyen_bay[i].Ngay_bay.Nam << '\t' 
            << Chuyen_bay[i].Gio_bay << '\t' << Chuyen_bay[i].Noi_den << endl;
}
bool kiemtra_Giang(CB Chuyen_bay[], int n)
{
    char s1[]={'G','i','a','n','g','\0'};
    char s2[]=
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    CB Chuyen_bay[100];
    nhieu_chuyen_bay(Chuyen_bay,n); 
    cout << "Machuyen " << "|Ngaybay " << "|Giobay " << "|Noiden" << endl;
    chuyen_bay_HN(Chuyen_bay,n);
    cout << endl;
    CB_TG_Lau_Nhat(Chuyen_bay,n);
    return 0;
}