// You will be given an undirected graph as input. This graph will contain only one connected component. The edge number will be exactly node-1. Then take a node from the input and print its level. Consider root as 1.

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];
int level[N];

void dfs(int u){
    visited[u] = true;
    
    for(int v: adj[u]){
        if(visited[v] == true){
            continue;
        }
        level[v] = level[u] + 1;
        dfs(v);
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: adj[u]){
            if(visited[v] == true) continue; 
            visited[v] = true;
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x;
    cin>>x; 

    bfs(1);

    for(int i=1; i<=n; i++){
        for(int j: adj[i]){
            if(x == j){
                cout<<"level of "<<x<<" : "<< level[j]<<endl;
            }
        }
    }

    // for(int i=1; i<=n; i++){
    //     cout<<"Node "<<i<<": ";
    //     for(int j: adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}