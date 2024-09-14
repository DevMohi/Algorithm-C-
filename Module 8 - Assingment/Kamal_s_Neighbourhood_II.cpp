#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

int dfs(int u)
{
    visited[u] = true;
    int house = 1;

    for (int v : adj[u]) 
    {
        if (!visited[v])
        {
            house += dfs(v);
        }
    }
    return house;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int root;
    cin >> root;


    int house = dfs(root);

    //minus korsi coz nijer ta toh diff
    cout << house - 1 << endl;

    // for(int i=0 ;i<n; i++){
    //     cout<<"Node "<<i<<": ";
    //     for(int j: adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}