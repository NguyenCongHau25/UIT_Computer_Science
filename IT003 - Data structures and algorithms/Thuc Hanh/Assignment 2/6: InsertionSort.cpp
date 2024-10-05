#include <iostream>
using namespace std;

void InputArray(int a[], int &n);
void OutputArray(int a[], int n);
void InsertionSort(int a[], int n);

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

void InsertionSort(int a[], int n)
{	
	int pos, x, i;
	for(i = 1; i < n; i++)
    { 
		x = a[i]; 
		pos = i - 1;
		while((pos >= 0) && (x < a[pos]))
        {
			a[pos+1] = a[pos];	
            pos--;
            OutputArray(a,n);
		}
		a[pos+1] = x;
        OutputArray(a,n);
	}
}

int main()
{
    int a[200];
    int n;
    
    InputArray(a,n);
    InsertionSort(a,n);

    return 0;
}