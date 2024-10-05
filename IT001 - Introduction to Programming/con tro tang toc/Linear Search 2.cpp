/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
void inputArray(int *(&a), int &n)
{
    cin >> n;
    a= new int [n];
    for (int i=0; i<n; i++)
        cin >> a[i];
}
int findOneElements(int *a, int n, int x)
{
    for (int i=0; i<n; i++)
        {
            if (a[i]==x)
                    return i;     
        }
    return -1;
}
void findElements(int *a, int n, int &m)
{
    cin >> m;
    for (int i=0; i<m; i++)
        {
            int x;
            cin >> x;
            cout << findOneElements(a,n,x) << endl;

        }
}
int main()
{
    int n,m;
    int *a=NULL;
    inputArray(a,n);
    findElements(a,n,m);

    return 0;
}
