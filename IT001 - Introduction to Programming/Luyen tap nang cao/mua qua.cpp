#include <iostream>
#define MAX_ARRAY 100000
using namespace std;

int HoanViNhiPhan(int,int HoanVi[],int,int a[],int &dem);
void Xuat(int HoanVi[],int n);
void TimViTri(int &Ha,int &Y,int &Duong,int HoanVi[],int MaSo[],int n);
bool KiemTraKhacNhau(int x,int y,int z, int MaSo[]);

int main()
{
    int n;
    int b[MAX_ARRAY];
    int a[MAX_ARRAY];


    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    int dem = 0;
    // Goi ham
    cout << HoanViNhiPhan(0,b,n,a,dem);


    return 0;
}

int HoanViNhiPhan(int i,int HoanVi[],int n,int a[],int &dem)
{
    for (int j = 0; j <= 1; j++)
    {
        HoanVi[i]=j;
        if(i==n-1)
        {
            int Sum=0;
            for (int k = 0; k < n;k++)
                Sum+=HoanVi[k];
            if (Sum == 3)
            {
                int Ha,Y,Duong;
                TimViTri(Ha,Y,Duong,HoanVi,a,n);
                if (KiemTraKhacNhau(Ha,Y,Duong,a))
                {
                    dem++;
                    //cout << dem;
                }
            }
        }
        else 
            HoanViNhiPhan(i+1,HoanVi,n,a,dem);
    }
    return dem;
}

void Xuat(int a[],int n)
{
    for (int i = 0; i < n;i++)
        cout << a[i] << " ";
    cout << endl;
}

void TimViTri(int &Ha,int &Y,int &Duong,int HoanVi[],int MaSo[],int n)
{
    int temp[MAX_ARRAY];
    int Q_position = 0;
    for (int i = 0; i < n;i++)
        {
            if (HoanVi[i]!=0)
            {
                temp[Q_position++] = i;
            }
        }
    Ha = temp[0];
    Y = temp[1];
    Duong = temp[2];
 
}

bool KiemTraKhacNhau(int x,int y,int z, int MaSo[])
{
    if (MaSo[x] == MaSo[y] || MaSo[y] == MaSo[z] || MaSo[x] == MaSo[z])
        return false;
    return true;
}