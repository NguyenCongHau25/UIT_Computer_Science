#include <iostream>
using namespace std;

void InputArray(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void Timx(int a[], int n, int x)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                dem++;
            }
        }
    cout << dem << endl;
    for (int i = 0; i < n; i++)
        {
            if (a[i] == x)    
                cout << i << " " << i + 1 << endl;
        }
}

int main()
{

    clock_t begin = clock();

    int a[10000];
    int n;
    int x;
    InputArray(a,n);
    cin >> x;

    Timx(a,n,x);

    clock_t end = clock(); //ghi lại thời gian lúc sau
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;

}