#include <iostream>
using namespace std;

void InputArray(int a[], int &n);
void OutputArray(int a[], int n);
void SelectionSort(int a[], int n);

void InputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void OutputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}



void SelectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min] )
                min = j;
        if (min != i)
        {
            swap(a[i], a[min]);
            OutputArray(a,n);
        }
    }
    
}

int main()
{
    int a[200];
    int n;
    
    InputArray(a,n);
    SelectionSort(a,n);
    //OutputArray(a,n);
    return 0;
}