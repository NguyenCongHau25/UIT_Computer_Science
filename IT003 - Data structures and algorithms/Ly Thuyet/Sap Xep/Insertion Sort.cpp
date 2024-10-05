void InsertionSort(int a[], int n)
{
	int pos, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		pos = i;
		while (pos > 0 && x < a[pos - 1])
		{
			a[pos] = a[pos - 1]; 
			pos--;
		}
		a[pos] = x;
	}
}

void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int j = j - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j =  j - 1;
		}
		a[j + 1] = key;
	}
}