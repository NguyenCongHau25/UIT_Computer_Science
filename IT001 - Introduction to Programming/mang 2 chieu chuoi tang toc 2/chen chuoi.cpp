/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
strlen
strcat
string
strcmp
strcpy
memmove
strstr
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
	char s[MAX], s1[MAX];
	cin.getline(s, 299);
	cin.getline(s1, 299);
	int k;
	cin >> k;
	if (k < 0 || k>myStrlen(s, 0))
		cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
	else
	{
		 
//###INSERT CODE HERE -

	ChenChuoiTaiVitriK(s,s1,k);
	}
}
int myStrlen(char s[], int k)
{
	int i=0;
	int d=0;
	while (s[i]!='\0')
	{
		d++;
		i++;
	}
	return d;
}
bool myStrcat(char s1[], char s2[])
{
	if (myStrlen(s1,0)+myStrlen(s2,0)>254)
		return 0;
	return 1;
}
void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{
	int d=k;
	if (myStrcat(s,s1))
	{
		for (int i=0; i<myStrlen(s1,0); i++)
			{
				{
					for (int j=myStrlen(s,0)+1; j >= i+k+1; j--)
					s[j]=s[j-1];
				}
				s[d]=s1[i];
				d++;	
			}
	}
	cout << s;
}
