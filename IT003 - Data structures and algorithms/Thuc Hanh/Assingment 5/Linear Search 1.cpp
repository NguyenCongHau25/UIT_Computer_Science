#include <iostream>
using namespace std;

void InputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void Timx(int a[], int n, int x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                cout << i << endl;
                cout << i + 1 << endl;
                cout << n - i - 1 << endl;
                cout << n - i << endl;
                break;
            }
            dem ++;
        }
    if (dem == n)
        cout << -1;

}

int main()
{
    int a[10000];
    int n;
    int x;
    InputArray(a,n);
    cin >> x;

    Timx(a,n,x);
    return 0;
}