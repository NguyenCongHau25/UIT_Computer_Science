#include <iostream>
#include <vector>
using namespace std;

void LinearSearch(vector<int> a, int k, int n)
{
    int check = 0;
    int i = 0;
    for (; i < n; i++)
    {
        if (a[i] == k)
        {
            check = 1;
            break;
        }
    }
    if (check != 0)
    {
        cout << i << endl;
        cout << i + 1 << endl;
        cout << n - 1 - i << endl;
        cout << n - i << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i  = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        a.push_back(x);
    }
    int k;
    cin >> k;
    LinearSearch(a,  k, n);
    return 0;
}