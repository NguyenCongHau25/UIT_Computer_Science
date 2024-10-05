/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

void tamGiacVuong_4()
{
//###INSERT CODE HERE -
    int h;
    cin >> h;
    if (h>=3 && h<=10)
    {
        for (int i = 1; i<=h; i++)
        {   
        for (int j=1;j <= h; j ++)
            {
                if (j >= i)
                cout << "* ";
                else cout << "  ";
            }
        cout <<endl;
        }
    }
    else cout << "Khong thoa dieu kien nhap.";
}
int main()
{

    tamGiacVuong_4();
    return 0;
}
