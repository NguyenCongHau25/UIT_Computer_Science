#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() 
{
    long long n, chiphi;
    vector<long long> cut;

    cin >> n >> chiphi;

    for (int i = 0; i < n; i++) 
    {
        long long tmp;
        cin >> tmp;
        cut.push_back(tmp);
    }

    long long tong;

    priority_queue<long long, vector<long long>, greater<long long> > k(cut.begin(), cut.end());

 
    for (int i=0; i < n - 2; ++i) 
    {
        tong = k.top();
        k.pop();
        tong = tong + k.top();
        k.pop();
        chiphi += tong;
        k.push(tong);
    }

    cout << chiphi;
    return 0;
}