#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double s1 = 0;
    double s2 = 0;
    double s3 = 0;
    int n;
    cin >>n;
    long giaithua = 1;
    double tong = 0;
    for (int i = 1; i <=n; i++)
    {   
        s1+=pow(i,i);
    }
    cout << s1<< endl;
  for (int i = 1; i <=n; i++)
    {
        
        giaithua=giaithua*i;
        s2+=giaithua;
    }
    cout << s2<<endl; 
    for (int i=1;i<=n;i++)
    {   
        tong+=i;
        s3=s3+(1.0/tong);
    }
    cout << s3<< endl;
    return 0;
}