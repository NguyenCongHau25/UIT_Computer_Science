#include <iostream>
using namespace std;

void InputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
}

void BinarySearch(int a[], int n, int x)
{
    int dem = 1;
    int L = 0; int R = n - 1;
    int mid = 0;
    int vt = 0;
    bool check = 0;
    while (L <= R)
    {
        mid = (L + R)/2;
        if (a[mid] < x)
        {  
            L = mid + 1;
            dem++;
        }
        else if (a[mid] > x)
        {
            R = mid - 1;
            dem++;
        }
        else if (a[mid] == x)
            {
               vt = mid;
               check = 1;
               break;
            }
    }
    if (check)
    {
        cout << vt << endl;
        cout << dem;
    }
    else cout << -1;

}

int main()
{


    int a[32000];
    int n;
    int x;
    InputArray(a,n);
    cin >> x;
    
    
    BinarySearch(a,n,x);
    
    return 0;
}