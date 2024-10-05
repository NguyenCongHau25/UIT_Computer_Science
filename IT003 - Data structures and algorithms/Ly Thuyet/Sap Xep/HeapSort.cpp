
#include <iostream>
using namespace std;

void Heapify(int *a,  int k, int n)
{
    int j = 2*k + 1;
    while (j < n)   
        {
            if (j + 1 < n)
                 if (a[j] < a[j+1])
                    j = j+1;
            if (a[k] > a[j])
                return ;
            swap (a[j], a[j]);
            k = j;
            j = 2*k + 1;
        }
}

void buildHeap(int *a, int n)
{
    int i;
    i = (n - 1) / 2;
    while (i >= 0)
    {
        Heapify(a, i, n)
            i--;
    }
}

void heapSort (int *a, int n)
{
    buildHeap(a,n);
    while (n > 0)
    {
        n = n - 1;
        swap(a[0], a[n]);
        Heapify(a,0,n);
    }
}
int main()
{
    int a
}