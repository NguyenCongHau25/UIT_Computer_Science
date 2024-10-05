#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
            for (int k = 0; k < n; k++)
                cout << a[k] << " ";
            cout << endl;
        }
        a[j+1] = key;
        for (int z = 0; z < n; z++)
            cout << a[z] << " ";
        cout << endl;
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

    InsertionSort(a, n);
    return 0;
}