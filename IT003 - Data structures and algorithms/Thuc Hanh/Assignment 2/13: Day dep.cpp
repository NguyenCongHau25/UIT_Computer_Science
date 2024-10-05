#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a)
        cin >> x;
    
    sort(a.begin(), a.end());

    if (a[0] == a[n - 1])
    {
        if (n == a[0])
            cout << 0;
        else if (n < a[0])
            cout << n;
        else
            cout << n - a[0];
        return 0;
    }
 
    int count = 0;
    int i = 0;
    while (i < n)
    {
        int dem = 0; 
        int j = i;
        while (a[i] == a[j])
        {
            j++;
            dem++;
            if (n <= j)
                break;
        }
        
        if (dem == a[i])
            i = j;

        else if (dem < a[i])
        {
            count += dem;
            i = j;
        }
        else 
        {
            count+=abs(a[i] - dem);
            i = j;
        }
    }
    cout << count;
    return 0;
}
