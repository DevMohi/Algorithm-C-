//Solved 
#include<bits/stdc++.h>
using namespace std;

const int N = 1001; 
vector<int> adj[N];
bool visited[N];

void dfs(int u, int & size){
    visited[u] = true;
    size++; 

    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v, size);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    //Reading the edges 
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> sizes;

    int cc = 0;
    for(int i=0; i<N; i++){
        if(!visited[i]){
            int size = 0; 
            dfs(i, size);
            //Do not store single nodes 
            if(size > 1){
                sizes.push_back(size);
                cc++;
            }
        }
    }

    // cout<<cc<<endl; 

    sort(sizes.begin(),sizes.end());

    for(int size: sizes){
        cout<<size<<" ";
    }

    return 0;
}

