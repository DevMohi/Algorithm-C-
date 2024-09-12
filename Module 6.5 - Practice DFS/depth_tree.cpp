//  You will be given an undirected graph as input. This graph will contain only one connected component. The edge number will be exactly node-1. Then take a node from the input and print its depth. Consider root as 1.

#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+ 7;
vector<int> adjList[N];
bool visited[N];
int depth[N];


void dfs(int u){
    visited[u] = true;

    for(int v: adjList[u]){
        if(visited[v] == true){
            continue;
        }
        depth[v] = depth[u] + 1; 
        dfs(v); 
    }
}



int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m;i++){
        int u,v;
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // for(int i=1; i<=n; i++){
    //     cout<<"Node "<<i<<": ";
    //     for(int j: adjList[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    dfs(1);

    int search;
    cin>> search; 

    for(int i=1; i<=n; i++){
        // cout<<"depth of Node "<<i<<": "<<depth[i]<<endl;
        if(search == i){
            cout<<"Depth of "<<i<<" = "<<depth[i]<<endl; 
        }
    }
    return 0;
}