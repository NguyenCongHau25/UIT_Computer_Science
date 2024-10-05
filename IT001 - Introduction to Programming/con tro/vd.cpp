#include <iostream>
using namespace std;
hamf(int a[], int n)
hamf(int *a, int n)

int main()
{
    int a;//bien tinh
    int *p=new int; //bien dong kieu int
    *p=7;
    cout << *p; 

    int a[100];//mang tinh
    int *p= new int[100]; //mang dong

    int n;
    cin >> n;
    int *p=new int [n];

    for ()
        cin >> p[i];
    hamf(p,n);
    delete []p;
    
    return 0;
}
