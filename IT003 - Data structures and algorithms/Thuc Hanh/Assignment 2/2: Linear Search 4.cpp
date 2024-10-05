
#include <iostream>

using namespace std;
int main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int b[100000];

    int n;
    cin >> n;

    int d;
    cin >> d;

    int a[n];
    for (int j = 0; j < n; j++)
    {
      cin >> a[j];
      b[a[j]]++;
    }

    int left = 0;
    int right = 0;

    for (int j = 0; j < n; j++)
    {
      if (b[a[j]] >= 2)
      {
        left++;
        right++;
      }
      else
        left+=b[a[j]];
      b[a[j]] = 0;
    }

    bool flag = 1;

    if (left > 2 * d || left + right < 2 * d)
      flag = 0;

    if (flag == 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
