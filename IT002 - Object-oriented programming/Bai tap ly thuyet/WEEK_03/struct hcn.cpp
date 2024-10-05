#include <iostream>

using namespace std;

struct HCN
{
    int w;
    int l;
};
void nhap(HCN &x)
{
    cin >> x.w >> x.l;
}
int area(HCN x)
{
    return x.w*x.l;
}
int main()
{
    HCN x;
    nhap(x);
    cout << area(x);
    return 0;
}