#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int> > a(n);

    //nhap gia tri vao first
    //vi tri gan cho second
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    bool flag = 0;

    //duyet mang theo cap dau va cap cuoi den vi tri trung tam
    for (int i = 0; i < n - 3; ++i)
    {
        for (int j = i + 1; j < n - 2; ++j)
        {
            int l = j + 1;
            int r = n - 1;

            while (l < r)
            {
                int sum = a[i].first + a[l].first+ a[j].first + a[r].first;
                if (sum == x)
                {
                    cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second << endl;
                    flag = 1;
                    return 0;
                }
                else if (sum >= x)
                    r--;
                else
                    l++;
            }
        }
    }

    if (!flag)
        cout << "IMPOSSIBLE" << endl;

    return 0;
}