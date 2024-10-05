
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
string
###End banned keyword*/

#include<iostream>
#include<cstring>
using namespace std;

//###INSERT CODE HERE -
typedef struct PROVINCE
{
    int id;
    char name[30];
    int pop;
    float area;

}PR;
void inputOneprovince(PR &x)
{
    cin >> x.id;
    cin.ignore();
    cin.getline(x.name,15);
    cin >> x.pop;
    cin >> x.area;
}
void outputOneprovince(PR x)
{
    cout << x.id << "\t"<<x.name<<"\t"<<x.pop<<"\t"<<x.area;
}
void inputArrayProvinces(PR a[], int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
        inputOneprovince(a[i]);
}
void outputProvincesMore1MillionPop(PR a[], int &n)
{
    for (int i=0; i<n; i++)
        if (a[i].pop>1000)
        {
            outputOneprovince(a[i]);
            cout << endl;
        }
}
int main()
{
    PROVINCE a[100];
    int n;

    inputArrayProvinces(a,n);

    cout<<"ID\t|Province\t|Population\t|Area\n";
    outputProvincesMore1MillionPop(a,n);
    
  
    return 0;
}
