#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[256];
    cin.getline(s,256);

    int i=0;
    int k=0;
    while (s[i]!='\0')
    {
        if (s[i]==' ')
        {
            for (int j=i-1; j>=k; j--)
                cout << s[j];
            cout << " ";  
            k=i+1;
        }
        i++;
    }
    for (int i=strlen(s)-1; i>=0; i--)
    {
        cout << s[i];
        if(s[i]==' ')  
            break;
    }
    return 0;
}