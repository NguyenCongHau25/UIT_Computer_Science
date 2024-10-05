#include <iostream>
using namespace std;
void sapxep(int a[], int n)
{
    int tg=0;
    for(int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
    {
        if(a[i]<a[j])
        {
            tg=a[i];
            a[i]=a[j];
            a[j]=tg;
        }
    }
}
int max(int a[], int n)
{
    int x=-1;
    for (int i=n-1; i>=0; i--)
    {
        if (a[i]<a[0])
            {
                if(a[i]>x)
                x=a[i];
            } 
    }
    if (x==-1) return 0;
    return x;
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i=0; i<n;i++)
    cin >> a[i];
    sapxep(a,n);
    cout << max(a,n);
    return 0;
}