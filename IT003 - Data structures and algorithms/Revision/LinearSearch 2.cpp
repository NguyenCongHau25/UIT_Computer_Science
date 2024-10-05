#include <iostream>
#include <vector>

using namespace std;

void LinearSearch(vector<int> a, int n, int x)
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            check++;
        }
    }
    if (check == 0)
        cout << 0;
    else
    {
        cout << check << endl;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
                cout << i << " " << i + 1 << endl;
        }
    }
}

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int x;
    cin >> x;
    LinearSearch(a, n, x);
    return 0;
}