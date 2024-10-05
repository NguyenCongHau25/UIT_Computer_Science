/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>


//###INSERT CODE HERE -
using namespace std;
int reverse(int a)
{   int c,b;
    b=0;
    while (a>0)
    {
        c = a%10;
        b = b*10 + c ;
        a = a/10;
    }
    return b;
}
int main() {
    int n;
    cin >> n;
    cout << reverse(n);
}
