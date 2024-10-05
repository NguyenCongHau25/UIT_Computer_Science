#include <iostream>
#include <string.h>
using namespace std;
void xuly(char a[])
{
    for (int i=0; i<strlen(a); i++)
        if ( a[i]==' ' && a[i+1]!=' ')
        {
            
            cout << " " << endl;
        }            

        else cout << a[i];
}
int main()
{
    char a[10000];
    char b[20];
    cin.getline(a,1000);

    cin.getline(b,20);
    
    
    int i=0;
    while (b[i]!='\0')
    {   
        for (int j=0; j<strlen(a); j++)
            if (a[j]==b[i])
                for (int k=j; k<strlen(a);k++)
                    a[k]=a[k+1];
                    
        i++;
    }
    xuly(a);
    return 0;
}