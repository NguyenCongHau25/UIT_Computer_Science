#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    int k = 0;
    cin >> T;
    while(k < T)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int min_sec = a[0];
        int max_sec = a[n-1];
        for (int i = 1; i < n; i++)
        {
            if (a[i] > min_sec)
                min_sec = a[i];
            break;
        }
        for (int i = n - 2; i > 0; i++)
        {
            if (a[i] < max_sec)
            max_sec = a[i];
            break;
        }
        cout << "\n" << (a[n - 1] - a[0]) + (max_sec - min_sec);
        k++;
    }
    return 0;
}