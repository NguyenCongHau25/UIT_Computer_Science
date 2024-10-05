#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    getline(cin, a);
    
    while (a[0] == a[1])
        a.erase(0,2);

    int d = a.length();

    for (int i = 1; i < d; )
    {
        if(a[i] == a[i - 1])
        {
            a.erase(i - 1, 2);
            d -= 2;
            i--;
        }
        else
            i++;
    }
      
    cout << d;
    return 0;
}
