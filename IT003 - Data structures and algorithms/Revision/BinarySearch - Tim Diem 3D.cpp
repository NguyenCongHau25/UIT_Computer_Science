/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -
#include <iostream>
#include <vector>
using namespace std;

struct Diem
{
    double x, y, z;
};

int KiemTra(Diem a, Diem b)
{
    if (a.x == b.x)
    {
        if (a.y == b.y)
        {
            if (a.z == a.z)
                return 0;
            else if (a.z > a.z)
                return 1;
            else
                return -1;
        }
        else if(a.y > b.y)
            return 1;
        else
            return -1;
    }
    else if (a.x > b.x)
        return 1;
    else
        return -1;
}

int BinarySearch(vector<Diem> &a, int n, Diem x)
{
    int dem = 0;
    int left = 0, right = n - 1;
    
    while(left <= right)
    {
        int mid = (right + left)/2;
            dem++;
        int cmp = KiemTra(x, a[mid]);
        if (cmp == 0)
            return dem;
        else if (cmp == 1)
            left = mid + 1;
        else
            right = mid - 1;
    }
        return 0;
}

int main()
{
   int n, m;
   cin >> n;
   vector<Diem> a;
   for(int i = 0; i < n; i++)
   {
       Diem d;
       cin >> d.x >> d.y >> d.z;
       a.push_back(d);
   }

   cin >> m;
   vector<Diem> b;

   for(int i = 0; i < m; i++)
   {
       Diem d;
       cin >> d.x >> d.y >> d.z;
       b.push_back(d);
   }

   for(int i = 0; i < m; i++)
   {
       if(BinarySearch(a,n, b[i]) == 0)
            cout << "KHONG" << endl;
       else
            cout << BinarySearch(a,n, b[i]) << endl;
   }
   return 0;
}