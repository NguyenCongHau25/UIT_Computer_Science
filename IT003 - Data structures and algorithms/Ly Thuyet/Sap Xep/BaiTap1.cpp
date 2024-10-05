/*Viet ham in ra ds n diem trong khong gian hai chieu theo thu tu tang dan theo khoang cach toi diem p(px, py) cho truoc*/
#include <iostream>
using namespace std;

struct Point
{
    int x,y;
};

void NhapMotDiem(Point &a)
{
    cout << "Nhap hoanh do: " << endl;
    cin >> a.x;
    cout << "Nhap tung do:" << endl;
    cin >> a.y;
}

void NhapDsDiem(Point a[], int n)
{
    for (int i = 0; i<n; i++)
        {
            cout << "Nhap diem thu " << i + 1<< ": " << endl;
            NhapMotDiem(a[i]);
        }
}
double khoangcach(Point a, Point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void InMotDiem(Point a)
{
    cout << "(" << a.x << "," << a.y << ")" << endl;
}

void PrintList (Point A[], int n, Point p)
{
    int min;
	for(int i=0; i<n-1; i++)
    {
		min = i;
		for(int j=i+1; j<n; j++)
        {
			if (khoangcach(A[j],p) < khoangcach(A[min], p))
				min = j;
			
		}
		swap(A[min], A[i]);
	}

    for (int i = 0; i < n; i++)
        InMotDiem(A[i]);
}


int main()
{
    Point A[100];
    int n;
    cout << "Nhap so diem: " << endl;
    cin >> n;

    NhapDsDiem(A, n);

    Point p;
    cout << "Nhap diem p: " <<  endl;
    NhapMotDiem(p);

    PrintList(A, n, p);
    return 0;
}