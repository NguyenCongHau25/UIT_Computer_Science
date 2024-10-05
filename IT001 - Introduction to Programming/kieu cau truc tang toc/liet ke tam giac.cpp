#include <iostream>
#include <math.h>
using namespace std;
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
float khoangcach(D a, D b)
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
void kiemtra( D a[], int n)
{
    for (int i=0; i<n;i++)
        for (int j=i+1; j<n; j++)
            for (int z=j+1; z<n; z++)
                {
                    float b=khoangcach(a[i],a[j]);
                    float c=khoangcach(a[j],a[z]);
                    float d=khoangcach(a[i],a[z]);
                    if (b+c>d && b+d>c && d+c>b)
                        cout << "[(" << a[i].x <<", "<<a[i].y<<"), ("<<a[j].x<<", "<<a[j].y<<"), ("<<a[z].x<<", "<<a[z].y<<")]" << endl;
                }
}

int main()
{
    int n;
    Diem a[100];
    nhapDSDiem(a,n);
    kiemtra(a,n);
    return 0;
}