#include <iostream>
#include <cstring>
using namespace std;

void demtu(char s[])
{
    int dem=0;
    if (s[0]!=' ')
    {
        int d=0;
        int z=0;
        while (s[z]!=' ')
        {
            if (s[z] >= '0' && s[z] <='9')
                d++;
            z++;
        }
    if (d==0)
        dem++; 
    }

    for (int i=0; i<strlen(s); i++)
        {   
                
            if ((s[i]!=' ' && s[i-1]==' '))
                {
                    cout << s[i] << " ";
                    int j=i;
                    int flag=0;
                    while (s[j]!=' ')
                    {

                        if (s[j] >= '0' && s[j] <='9' )
                        {
                            flag++;
                        }
                        j++;
                    }
                    if (flag == 0)
                            dem++;  
                }
        }
    cout << dem;
}
int main()
{
    char s[300];
    cin.getline(s,256);
    cin.ignore();
    demtu(s);
    return 0;
}