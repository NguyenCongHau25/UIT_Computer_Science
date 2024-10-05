#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector<int> b(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
        if (a[i] <= count)
        {
            while (b[count] != 0)
            {
                count++;
            }
        }
        cout << count << " ";
    }
    return 0;
}