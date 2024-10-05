#include <iostream>
using namespace std;
int main()
{


int h;
    cin>>h;
if (h>=3 && h<=10)
    for(int i=1;i<=h;i++){
            for(int j=1;j<=i;j++)
            {
                cout<<"* ";
            }
        cout<<endl;}
else cout<<"Khong thoa dieu kien nhap.";
return 0;
}
