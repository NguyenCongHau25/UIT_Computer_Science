#include <iostream>
#include <cmath>
using namespace std;
void SelectionSort(int a[], int n)
{
	int min; 
	for (int  i = 0; i < n - 1; i++)
	{
		min = i; 
		for(int j = i + 1; j < n; j++)
	   	   if (a[j] < a[min])
		       min = j; 
		if (min != i)
	   	   swap(a[min], a[i]);
	}
}

void selectionsort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; i++)
		{
			if (a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}
}
int main()
{
    int a[10];
    int n;
    cin >> n;
    SelectionSort(a,n);
}