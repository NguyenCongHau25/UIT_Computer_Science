#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/*
9 10
1 2
1 3
1 5
2 4
3 6
3 7
5 8
6 7
8 9
9 3
*/
int n, m; 
vector<int> adj[1001];
bool visited[1001];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v: adj[u])
    {
        if (!visited[v])
        {
            DFS(v);
        }
    }
}
int main()
{
    input();
    DFS(1);
    return 0;
}


