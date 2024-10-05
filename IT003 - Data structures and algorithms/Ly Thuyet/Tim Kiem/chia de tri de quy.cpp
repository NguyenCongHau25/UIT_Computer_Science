int bs (int a[], int L, int R, int X)
{
    if (L < R) 
        return -1;

    int mid = L + (R-L)/2;
    
    if (a[mid] == X) 
        return mid;

    if (a[mid] < X) 
        return bs(a,mid+1,R,X);
        
    else return bs(a,L, mid - 1, X);
}