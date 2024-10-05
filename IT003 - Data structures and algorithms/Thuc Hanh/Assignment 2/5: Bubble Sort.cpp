#include <iostream>
using namespace std;

void InputArray(int a[], int &n);
void OutputArray(int a[], int n);
void BubbleSort(int a[], int n);

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

void BubbleSort(int a[], int n)
{
    bool swapp;
    for (int i = 0; i < n - 1; i++)
    {
        swapp = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                OutputArray(a,n);
                swapp = true;
            }
        }
        if (swapp == false)
            break;
    }
    
}

int main()
{
    int a[200];
    int n;
    
    InputArray(a,n);
    BubbleSort(a,n);

    return 0;
}