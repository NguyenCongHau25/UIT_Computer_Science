#include <iostream>
using namespace std;
void kiemtra(int a[], int na, int b[], int nb )
{
    for (int i=0; i<na; i++)
    {
        int x=0;
        for (int j=0; j<nb; j++)
            {
                if (a[i]!=b[j])
                   x++; 
            }
        if (x==nb) cout << a[i] << " ";
    }
        

}
int main()
{
    int a[1000], b[1000];
    int na, nb;
    cin >> na;
    cin >> nb;
    for (int i=0; i<na; i++)
        cin >> a[i];
    for (int i=0; i<nb; i++)
        cin >> b[i];
    kiemtra(a,na,b,nb);
    return 0;
}