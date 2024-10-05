#include <iostream>
using namespace std;
int main()
{
    int v1, w1, v2, w2, w;
    cin >> v1 >> w1 >> v2 >> w2 >> w;
    if (w1 + w2 <=w)
        cout << v1+v2;
    else if (w1 > w && w2>w)
        cout << 0;
    else if (v1>=v2)
    {
        if (w1 <= w) 
            cout << v1;
        else cout << v2;
    }
    else if (v2>v1)
    {
        if (w2<w) 
            cout << v2;
        else cout << v1;
    }
    return 0;
}