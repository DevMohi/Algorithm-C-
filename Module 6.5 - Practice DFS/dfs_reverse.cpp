// You will be given an undirected graph. Print its DFS traversal in reverse order. Consider root as 1.

//Sample input
// 4
// 4
// 1 2
// 4 3
// 3 2
// 2 4

#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;;
vector<int> adj[N];

bool visited[N];
vector<int> dfs_order;

void dfs(int u){
    //Section 1 -> actions after entering the node
    visited[u] = true;
    // cout<<"Visitng Node"<<u<<endl; 
    dfs_order.push_back(u); // One way 
    
    for(int v: adj[u]){
        // cout<<"Visiting Node"<<v<<endl;
        if(visited[v] == true){
            continue;
        }
        else{
            dfs(v);
        }
    }
    //Section 4 - actions before exiting node u //Another way  
    cout<<u<<" ";
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

    // for(int i=1; i<=n; i++){
    //     cout<<"Node: "<<i<<": ";
    //     for(int j: adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(1);

    //ANother way of reversing 
    // for(int i= dfs_order.size() - 1; i>=0; i--){
    //     cout<<dfs_order[i]<<endl;
    // }


    return 0;
}