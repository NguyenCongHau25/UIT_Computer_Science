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
        if (a[j] >= pivot) 
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


int H_Index(vector<int> a, int n)
{
    for (int i = n; i > 0; i--)
        if (a[i-1] >= i)
            return i;
    return 0;
}

int main()
{
    int n;
    vector<int> a;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    QuickSort(a,0, n - 1);
    //for (int i = 0; i<n ; i++)
    //    cout << a[i] << " ";
    cout << H_Index(a, n);

    return 0;
}