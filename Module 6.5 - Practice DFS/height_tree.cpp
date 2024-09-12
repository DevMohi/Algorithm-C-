//  You will be given an undirected graph as input. This graph will contain only one connected component. The edge number will be exactly node-1. Then take a node from the input and print its depth. Consider root as 1.

#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+ 7;
vector<int> adjList[N];
bool visited[N];
int height[N];


void dfs(int u){
    visited[u] = true;

    for(int v: adjList[u]){
        if(visited[v] == true){
            continue;
        }
        dfs(v); 
        // Initially, the height of a leaf node (a node with no children) is 0.
        // As the DFS returns back up the recursion, the height of each node is calculated by finding the maximum height of its children and adding 1.
        height[u] = max(height[u], height[v] + 1); 
        cout<<"This is u ";
        cout<<u<<" "<<endl;
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

    dfs(1);

    int search;
    cin>> search; 

    // for(int i=1; i<=n; i++){
        
    //     if(search == i){
    //         cout<<"height of "<<i<<" = "<<height[i]<<endl; 
    //     }
    // }

    for(int i=1; i<=n; i++){
        cout<<"heiht of Node "<<i<<": "<<height[i]<<endl;
    }
    return 0;
}