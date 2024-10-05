#include <iostream>
#include <vector>
using namespace std;

void BinarySearch(vector<int> a, int n, int m)
{
    int left = 0, right = n - 1;
    int Count = 0, Check = -1;
    while (left <= right)
    {
        int mid = (left + right)/2;
        Count++;
        if (a[mid] == m)
        {
            cout << mid << endl;
            cout << Count << endl;
            Check = 1;
            break;
        }
        else if(a[mid] > m)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (Check == -1)
        cout << Check << endl;

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
    int m;
    cin >> m;
    BinarySearch(a, n, m);
    return 0;
}
