#include <iostream>
#include <vector>

using namespace std;

struct DIEM
{
    int x, y;
};

void merge(vector<DIEM>& arr, int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    vector<DIEM> L(n1), M(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i].x < M[j].x || (L[i].x == M[j].x & L[i].y > M[j].y))
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = M[j];
            j++;
        }
        k++;

    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(vector<DIEM>& arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);


    merge(arr, l, m, r);
    }

}

int main()
{
    
    int n;
    cin >> n;

    vector<DIEM> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }

    mergeSort(a,0,n-1);
    for (int i = 0; i < n; i++)
        cout << a[i].x << " " << a[i].y << endl;
    return 0;
}