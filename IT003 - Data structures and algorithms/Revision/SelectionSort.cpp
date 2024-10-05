#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int> &a, int n)
{
    int Min;
    for (int i = 0; i < n - 1; i++)
    {
        Min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[Min])
                Min = j;
        }
        if (Min != i)
        {
            swap(a[i], a[Min]);
            for (int k = 0; k < n; k++)
                cout << a[k] << " ";
            cout << endl;
        }
        
    }
}

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
    SelectionSort(a, n);
    return 0;
}