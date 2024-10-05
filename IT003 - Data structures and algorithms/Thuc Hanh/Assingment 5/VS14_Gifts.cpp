#include <iostream>
#include <vector>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) 
    {
        if (a[j] <= pivot) 
        {
            i++;
            Swap(a[i], a[j]);
        }
    }
    Swap(a[i + 1], a[high]);
    return (i + 1);
}

void QuickSort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
  }
}

int Search(vector<int> a, int n, int x)
{
    int l = 0;
    int r = n - 1;
    int max = -1;

    while (l < r)
    {
        int sum = a[l] + a[r];
        if (sum <= x)
        {
            if (sum > max)
                max = sum;
            l++;
        }
        else 
            r--;
    }
    return max;
}

int main()
{
    int n,x;
    vector<int> a;

    cin >> n;
    cin >> x;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    QuickSort(a, 0, n-1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " "; 
    
    int  max_sum = Search(a,n,x);   
    cout << max_sum;
    return 0;
}