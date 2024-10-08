/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct DATE
{
    int day, month, year;
};
typedef struct STUDENT
{
    char id[11];
    char name[35];
    DATE dob;
    float math, phy, chem, aver;

} SV;

//###INSERT CODE HERE -
void inputOneStudent(SV &x)
{
    cin >> x.id;
    cin.ignore();
    cin.getline (x.name, 34);
    cin >> x.dob.day>> x.dob.month>> x.dob.year;
    cin >> x.math >> x.phy >> x.chem;
    x.aver = (x.math + x.chem + x.phy)/3;

}
void outputStudent(SV &x)
{
    cout << x.id << "\t|"<<x.name<<"\t|"<<x.dob.day<<"/"<<x.dob.month<< "/"<<x.dob.year <<
    "\t|" << x.math << "\t|" << x.phy << "\t|"<< x.chem << "\t|" << x.aver;
}
void inputArrayStudents(SV a[], int &n)
{
    cin >>n;
    for (int i=0; i<n; i++)
        inputOneStudent(a[i]);
}


int main()
{
    STUDENT a[100];
    int n,i;
    char name[35];

    inputArrayStudents(a,n);

    sortbyName(a,n);
    cout<<"\nList of students sorted: ";
    cout<<"\nID\t|Fullname\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
    outputArrayStudents(a,n);

    return 0;
}

