#include <iostream>
using namespace std;
int main () 
{
   int n;
   cin >> n;
   while (1)
   {
        char a;
        cin >> a;
		if (a == 'X') break;
		 int i = 0;
	 	 while (i < n)
		 {
		    cout << a << " ";
		    i++;
		 }
	cout << endl;
    }	

    return 0;
}