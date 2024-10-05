#include <iostream>
#include <vector>
using namespace std;

int TruLuong_Min(vector<vector<int> > arr )
{
    int min = 0;
    for (int i = 0; i <= arr.size()-3; i++)
    {
        for (int j = 0; j <= arr[i].size()-3; j++)
            {
                int s = 0;
                s = arr[i][j] + arr[i][j+1] + arr[i][j+2]
                + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2]
                + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
                if (i == 0 && j==0 )
                    min = s;
                else
                    if (min > s)
                        min = s;
            }
    }
    return min;
}

int main()
{

    int r, c;
    cin >> r >> c;
    
    vector<vector<int> > arr(r);

    for(int i = 0; i < r; i++)
    {
        arr[i] = vector<int>(c);
        for(int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    int kq = TruLuong_Min(arr);
    cout << kq;

    return 0;
}