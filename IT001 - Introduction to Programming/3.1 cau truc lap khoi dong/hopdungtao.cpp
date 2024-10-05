#include <iostream>
using namespace std;
int main () {

    int k,tv,tc;
   tv =0;
   tc =0;
   cin >> k ;
   int i=1;
   while (i <= k)
    {
      if (i%2 !=0)
       tv+=i*i;
      else 
        tc+=i*i;
    i++;
    }
   cout << tc -tv;
    return 0;
}