#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<pair<string, string>> a;

    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        string b, c;
        cin >> b >> c;
        a.push_back({b, c});
    }

    for (int i = 0; i < q; i++)
    {
        string b;
        cin >> b;
        s.push_back(b);
    }

    for (int i = 0; i < q; i++)
    {
        int test = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[i] == a[j].first)
            {
                cout << a[j].second << "\n";
                test = 1;
                break;
            }
        }
        if (test == 0)
            cout << "Chua Dang Ky!" << "\n";
    }
    return 0;   
}