#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n ; i++)
        cin >> a[i];
    
    vector<int> b(n);
    int count  = 0 ;

    for (int i = 0; i < n; i++)
        {
            b[a[i]]++;
            if (count >= a[i])
                {
                    while (b[count] != 0)
                        count++;
                }
            cout << count << " ";
        }
}