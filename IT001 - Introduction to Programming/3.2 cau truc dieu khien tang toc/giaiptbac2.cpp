#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a,b,c,delta,x,x1,x2;
    cin>>a>>b>>c;
    delta= b*b-4*a*c;
    if (a==0)
        if (b==0)
            if (c==0)
                cout<<"INF";
            else cout<<"IE";
        else cout<< (double)-c/b+0;
    else if (delta>=0)
    {
        x1= (-b + sqrt(delta)) / (2.0 * a)+0;
        x2= (-b - sqrt(delta)) / (2.0 * a)+0;
            if (x1<x2)
                cout<<x1<< " "<<x2;
            else cout<<x2<< " "<<x1;
    }
    else cout<< "IE";
    return 0;
}