/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<float> >v;
    vector<vector<float> >a;

    int n;
    int m;
    cin >> n;

    float t;

    for (int i = 0; i < n ; i++)
    {
        vector<float> hang;
        for (int j = 0; j < 3; j++)
        {
            cin >> t;
            hang.push_back(t);
        }
        v.push_back(hang);
    }

    cin >> m;

    for (int i = 0; i < m ; i++)
    {
        vector<float> hang;
        for (int j = 0; j < 3; j++)
        {
            cin >> t;
            hang.push_back(t);
        }
        a.push_back(hang);
    }

    for (int i = 0; i < m; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (a[i][0] == v[j][0] && a[i][1] == v[j][1] && a[i][2] == v[j][2])
            {
                cout << j << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "KHONG" << endl;
    }

    return 0;
}