#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector <int> adj[N];

void dfs(int s){
    vis[s] = true;
    cout<<s<<endl;

    for(int i=0; i<adj[s].size(); i++){
        int child = adj[s][i];
        if(vis[child] == false){
            dfs(child);
        }
    }
}
//Comment
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);        
        adj[v].push_back(u);        

    }
    dfs(1);
    return 0;
}

// 5 4
// 1 2 
// 1 3
// 2 4
// 4 5