/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#define MAXR 100
#define MAXC 100
void NhapMaTran(int a[][100],int &n)
{
    std::cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            std::cin >> a[i][j];
}
bool isMaTranDonVi(int a[][MAXC], int &n)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            if ( i==j && a[i][i] !=1)
				return false;
			if (i!=j && a[i][j] !=0)
				return false;
        }
	return true;     
}
int main() {
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout <<  std::boolalpha << isMaTranDonVi(a, n);
    return 0;
}
