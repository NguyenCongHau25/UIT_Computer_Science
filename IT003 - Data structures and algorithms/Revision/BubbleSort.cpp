#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> a, int n)
{
    int i = 0;
    while (i < n - 1)
    {
        int j = 0;
        bool check = 0;
        while (j < n - 1 - i)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                for (int z = 0; z < n; z++)
                    cout << a[z] << " ";
                cout << endl;
                check = 1;
            }
            j++;
        }
        if (check == 0)
            break;
        i++;
    }
}

int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    BubbleSort(a, n);
    return 0;
}