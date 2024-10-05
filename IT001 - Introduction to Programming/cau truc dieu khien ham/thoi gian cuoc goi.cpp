#include <iostream>
using namespace std;
int main()
{
    int min1, min2, min3;
    int s,t;
    cin >> min1 >> min2 >> min3 >> s;
    if (s>=min1) 
        {
        t=1;
        s=s-min1;
        }
    if (s>min2*9)
    {
        t=t+9;
        s=s-(min2*9);
    }
    else 
    {
        t=t+(s/min2);
        s=s-((s/min2)*min2);
    }
    if (s>min3)
        t = t + (s/min3);
    cout << t;
    return 0;

}