#include<bits/stdc++.h>
using namespace std;
// Weighted graph er por bfs kaaj korena , jodi shortest distance bole use bfs because aita level wise shortest path jai 
const int N = 1e5 + 5;
vector<int> adj[N];
int dis[N];
bool vis[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

    while(!q.empty()){
        int parent = q.front();
        q.pop();
        cout<<parent<<endl;

        //Looping
        //Normally -> replace adj with adj[parent] since its array of vectors 
        // for(int i=0; i<adj.size(); i++){
            
        // }

        //This can be traversed two way either way one or way two 
        for(int i=0; i<adj[parent].size(); i++){
            int child = adj[parent][i]; 
            if(vis[child] == false){
                q.push(child);
                dis[child] = dis[parent] + 1; 
                vis[child] = true; 
            }  
        }

        // for(int child: adj[parent]){
        //     if(vis[child] == true) continue;
        //     q.push(child);
        //     dis[child] = dis[parent] + 1; 
        //     vis[child] = true; 
        // }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    while(e--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    for(int i=1; i<=n; i++){
        cout<<"Node "<<i<<": "<<dis[i]<<endl; 
    }

    return 0;
}
// Weighted graph er por bfs kaaj korena , jodi shortest distance bole use bfs because aita level wise shortest path jai 
// 5 4
// 1 2 
// 1 3
// 2 4
// 4 5