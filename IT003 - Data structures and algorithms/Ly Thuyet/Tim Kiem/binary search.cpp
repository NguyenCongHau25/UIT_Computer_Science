int binarySearch(int A[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (x == A[m])
            return m;
        if (x < A[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}