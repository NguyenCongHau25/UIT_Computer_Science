#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;


typedef struct STUDENT
{
    char Yeare[35];
    float math, liter, aver;

} SV;

void inputOneStudent(SV &x)
{
    cin.ignore();
    cin.getline (x.Yeare, 34);
    cin >> x.math >> x.liter;
    x.aver = (x.math + x.liter)/2;
}

void outputOneStudent(SV &x)
{
    cout << x.Yeare << "\t|" << x.math << "\t|" << x.liter << "\t" << "\t|" << x.aver;
}

void inputArrayStudents(SV a[], int&n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        inputOneStudent(a[i]);
}
void outputArrayStudents(SV a[],  int n)
{
    for (int i=0; i<n; i++)
    {
        outputOneStudent(a[i]) ;
        cout << endl;
    }
        
}
void maxaver(SV a[], int n)
{
    SV max = a[0];
    for (int i = 1; i<n; i++)
        {
            if (a[i].aver > max.aver)
                max = a[i];
        }
    outputOneStudent (max);
    cout << endl;
}

void minaver(SV a[], int n)
{
    SV min = a[0];
    for (int i = 1; i<n; i++)
        {
            if (a[i].aver < min.aver)
                min = a[i];
        }
    outputOneStudent (min);
}

int main()
{
    STUDENT a[100];
    int n;

    cout << "Nhap danh sach hoc sinh: " << endl;
    inputArrayStudents(a,n);
    
    cout << "Danh sach hoc sinh da nhap: " << endl;
    cout<<"Full Yeare\t|Maths\t|Literature\t|Average score\n";
    outputArrayStudents(a,n);

    cout << "Hoc sinh co diem trung binh cao nhat: " << endl;
        maxaver(a,n);
    
    cout << "Hoc sinh co diem trung binh thap nhat: " << endl;
        minaver(a,n);
    
    return 0;
}
