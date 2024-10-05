#include <iostream>
using namespace std;
int kiemtranguyento(int n)
{
    for (int i = 2; i<=n-1;i++)
    {
       if (n%i==0)
       return 0;
    }
   if (n == 1 || n==0)
    return 0;
return 1;

}
int main()
{
    int a[50];
    int n;
    cin >> n;
    int dem=0;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        if (kiemtranguyento(a[i])==1)
            dem+=1;
    }
    cout << dem << endl;
    for (int i=0; i<n; i++)
    {
        if (kiemtranguyento(a[i])==1)
        cout <<a[i] << " ";
    }
    return 0;
}