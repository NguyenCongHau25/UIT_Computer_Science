#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
/*
10 11
1 2
1 3
1 10
2 4
3 5
3 6
5 8
5 10
6 7
7 3
8 9

*/
vector <int> adj[1001];
bool visited[1001];
void Input()
{
    int n, m;
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

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int x: adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    Input();
    BFS(1);
    return 0;
}

void BFS(int u)
{
    queue <int> q;
    q.push(u);
    visited[u] = true;
    while(q.empty())
    {
        int v = q.front();
        q.pop();
        for(int x: adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}