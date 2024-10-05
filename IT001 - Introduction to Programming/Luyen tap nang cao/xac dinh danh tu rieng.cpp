#include <iostream>
using namespace std;



int main()
{
    char s[300];
    cin.getline(s,300);
    
    for (int i=0; i<strlen(s); i++)
    {
        if (s[i]>='A' && s[i] <= 'Z')
        {
            cout << s[i];
            i++;
            while (s[i]>='a' && s[i] <='z')
            { 
                cout << s[i];
                i++;
            }
            cout << ' ';
            if (s[i+1] <= 'A' || s[i+1] >= 'Z')
                cout << endl;
            
        }
    }
    return 0;
}