#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u){


    //Section 1 -> actions just after entering a node
    visited[u] = true;
    cout<<"Visting node: "<<u<<endl;

    for(int v: adj[u]){
        //section2 - actions before entering a new neighbour/child
        if(visited[v] == true){
            continue; //next neighbour er kase jaite paro 
        }
        dfs(v);

        //section 3 - actions after exiting a neighbour
    }
    //section 4 - actions before exiting node u 

}


int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    dfs(1); 

    // for(int i=1; i<=n; i++){
    //     cout<<"Node "<<i<<": ";
    //     for(int j: adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}
