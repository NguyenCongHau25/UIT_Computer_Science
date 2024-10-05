/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
###End banned keyword*/
#include <iostream>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -
typedef struct Diem
{
    int x;
    int y;
} D;
void inputonepoint(D &a)
{
    cin >> a.x;
    cin >> a.y;
}
void outputonepoint(D a)
{
    cout << "("<<a.x<<","<< a.y<<")";
}
void nhapDSDiem(D a[], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        inputonepoint(a[i]);
    cout << endl;
}

void xuatDSDiem(D a[], int n)
{
    for (int i=0; i<n; i++)
    {
        outputonepoint(a[i]);
        cout << " ";
        cout << endl;
    }
}
D diemDoiXungQuaO(D M)
{
    M.x=-M.x;
    M.y=-M.y;
    return M;
    
}
float khoangcach(D a, D b)
{
    float d;
    d= sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
    return d;

}
D khoangCachNhoNhat(D a[], int n, D M)
{

    int vt=0;
    float Min=khoangcach(a[0], M);
    for (int i=1;i<n; i++)
    {
        if (Min > khoangcach(a[i],M))
        {
            Min =khoangcach(a[i],M);
            vt=i;
        }
    }
    return a[vt];
}


int main()
{
    Diem a[100];
    int n;
    nhapDSDiem(a,n); // Nhap danh sach cach diem trong mat phang Oxy
    cout<<"Danh sach diem trong mat phang Oxy:\n";
    xuatDSDiem(a,n); // Xuat danh sach cac diem, moi diem tren 1 dong

    Diem M,N;
    cout<<"\nNhap mot diem de kiem tra khoang cach: ";
    cin>>M.x>>M.y;

    N = diemDoiXungQuaO(M);
    cout<<"\nDiem doi xung voi ("<<M.x<<","<<M.y<<") qua goc toa do O: ("<<N.x<<","<<N.y<<")";

    N = khoangCachNhoNhat(a,n,M);
    cout<<"\nDiem co khoang cach ngan nhat toi ("<<M.x<<","<<M.y<<"): ("<<N.x<<","<<N.y<<")";


    return 0;
}
