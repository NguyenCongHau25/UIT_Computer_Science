/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -
using namespace std;
int input(int &b)
{   
    cin >> b; 
    return b;
}
int input()
{   int a;
    cin >> a;
    return a;
}
int TongUocChung(int i, int j)
{
    int n;
    n = (i<j)?i:j;
    int sum = 0;
    for (int a= 1; a<=n; a++)
        if (i%a==0 && j%a==0) 
        sum+=a;
  return sum;
}
int main(){
    int a, b;
    a=input();
    input(b);
    std::cout << TongUocChung(a, b);
    return 0;
}
