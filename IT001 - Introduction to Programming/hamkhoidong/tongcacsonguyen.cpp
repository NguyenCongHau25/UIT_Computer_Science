cout << sumMany(n);
}
int sumMany (int n)
{
    int a, s=0;
    for (int i=1;i<=n; i++)
    {
        cin >>a;
        s=s+a;
    }
    return s;
}