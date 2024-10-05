#include <iostream>
#include <vector>
using namespace std;

int n;

void InputArray(long long a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void OutputArray(long long a[], int p, int q, int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i == p)
            cout << "[ ";
        if (i == q + 1)
            cout << "] ";
        if (i != n)
            cout << a[i] << " ";
    }
    cout <<"\n";

}

void Merge(long long a[], int p, int q, int r)
{
    vector <int> L(a + p, a + q + 1);
    vector <int> R(a + q + 1, a + r + 1);

    int i = 0;
    int j = 0;
    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[i])
        {
            a[p] = L[i];
            i++;
            p++;
        }
        else 
        {
            a[p] = R[j];
            j++;
            p++;
        }
    }

    while (i < L.size())
    {
        a[p] = L[i];
        i++;
        p++;
    }

    while (j < R.size())
    {
        a[p] = R[j];
        j++;
        p++;
    }

}

void MergeSort(long long a[], int p, int q)
{
    if (p >= q)
    return;
    
        int r = (p + q)/2;

        MergeSort(a, p, r);
        MergeSort(a, r + 1, q);
        Merge(a, p, q, r);
        OutputArray(a,p,q,n);
    
}

int main()
{
    long long a[200];
    
    InputArray(a, n);
    MergeSort(a, 0, n - 1);
    return 0;
}