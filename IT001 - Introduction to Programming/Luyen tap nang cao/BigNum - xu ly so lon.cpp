#include <iostream>
using namespace std;
int sonhonhat(int a)
{
    int x=a;
    x=x%10;
    while (true)
    {   
        cout << x;
        if(x%10==0)
            break;
        x+=x;
       
    }
    return a=x/10;
}
int main()
{
    int n;
    int a[100000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cout << sonhonhat(a[i]) << endl;
    return 0;
}