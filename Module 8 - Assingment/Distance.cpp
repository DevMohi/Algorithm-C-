#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj_list[N];
bool visited[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v: adj_list[u]) 
        {
            if (visited[v] == true) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int root, search;
        cin >> root >> search;

        // Reset arrays using loops
        for (int i = 0; i < N; i++) {
            visited[i] = false;
            level[i] = -1;
        }

        bfs(root);

        cout << level[search] << endl;
    }

    return 0;
}

//  BFS (Breadth-First Search) is particularly suited for finding the shortest path in an unweighted graph. This is because BFS explores all nodes at the present "depth" (or level) before moving on to nodes at the next depth level.

// In simpler terms, BFS guarantees that when we first reach a node, we have found the shortest path from the source to that node