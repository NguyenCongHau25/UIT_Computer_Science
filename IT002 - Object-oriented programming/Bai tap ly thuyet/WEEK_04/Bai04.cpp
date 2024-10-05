#include <iostream>

using namespace std;

void Swap(int &a, int &b);


class cArray
{
    private:
        int *a;
        int n;
        int x;
    public:
        cArray(int nn, int xx)
        {
            n = nn;
            a = new int[n];

            cout << "Nhap cac phan tu: \n";
            for (int i = 0; i < n; i++)
                cin >> a[i];
            x = xx;
        }

        ~cArray()
        {
            delete[] a;
        };

        void PrintArray();
        int MaxNagative();
        int CountX();
        bool KtMangGiam();
        void Swap(int &a, int &b);
        void Sort();

};

void cArray::PrintArray()
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int cArray::MaxNagative()
{
    int vt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
        {
            vt = i;
            break;
        }
    if (vt == 0)
        return 0;
    int max = a[vt];
    for (int i = vt+1; i < n; i++)
        if (a[i] < 0 && a[i] > max)
            max = a[i];
    return max;
}

int cArray::CountX()
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            count++;
    return count;
}     

bool cArray::KtMangGiam()
{
    for (int i = 0; i < n-1; i++)
        if (a[i] < a[i+1])
            return 0;
    return 1;
}
void cArray::Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void cArray::Sort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
	        if(a[i] > a[j])
		        Swap(a[i], a[j]);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n,x;
    cout << "Nhap vao kich thuoc mang: \n";
    cin >> n;
    cout << "Nhap vao so nguyen x: \n";
    cin >> x;
    cArray a(n,x);

    cout << "Mang da nhap: " << endl;
    a.PrintArray();
    
    cout << "So nguyen am lon nhat trong mang la: \n";
    if (a.MaxNagative() == 0)
        cout << "Khong co so nguyen am \n";
    else 
        cout << a.MaxNagative() << "\n";
    
    cout << "So lan so nguyen x xuat hien trong mang: \n";
    cout << a.CountX();


    if (a.KtMangGiam() == 1)
        cout << "\nMang giam dan \n";
    else 
       {
            cout << "\nMang khong giam \n";
            cout << "Mang da sap xep \n";
            a.Sort();
        }

    return 0;
}