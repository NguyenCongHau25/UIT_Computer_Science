#include <iostream>
using namespace std;
int check (char a[][2])
{
            if (a[0][1] == '.' && a[1][0]=='.')
                return 0;
            if (a[0][0]=='.' && a[1][1]=='.')
                return 0;
            return 1;
}
int main()
{
    char a[2][2];
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            cin >> a[i][j];
    if (check(a))
        cout << "Yes";
    else cout << "No";
    return 0;

}