#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double n,x,a=1,s1=1,s2=1,s3=1;
    cin>>n>>x;

    for(int i=1;i<=n;i++)
    {
        s1+=pow(x,i);
    }
    cout<<s1<<endl;

    for(int i=2;i<=2*n;i+=2)
    {
        s2+=pow(x,i);
    }
    cout<<s2<<endl;

    for(int i=1;i<=n;i++)
    {
        a=a*i;
        s3+=pow(x,i)/a;
    }
    cout<<s3;
    return 0;
}
