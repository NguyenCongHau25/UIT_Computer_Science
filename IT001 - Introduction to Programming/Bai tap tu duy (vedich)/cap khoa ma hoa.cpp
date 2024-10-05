#include <iostream>
using namespace std;

int check (int x)
{
    for (int i=2; i*i<=x ; i++)
        if (x%(i*i)==0)  
            return 0;
    return 1;
}
int ucln(int a, int b)
{
    if (b==0)
        return a;
    return ucln(b,a%b);
}
void xuly(int l, int r)
{
    int dem=0;
    int a[1000];
    int na=0;
    for (int i=l; i<=r; i++)
        if (check (i)==1)
            a[na++]=i;

    for (int x=0; x<na; x++)
        for (int y=x+1; y<na; y++)
            if(ucln(a[x],a[y])==1)
                dem++;       
    cout << dem;
}

int main()
{
    int l,r;
    cin >> l >> r;
    xuly(l,r);
    return 0;
}