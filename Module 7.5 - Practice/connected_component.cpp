//Bfs implementation and level 

#include<bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];


void dfs(int u){
    visited[u] = true;
    for(int v: adjList[u]){
        if(visited[v]) continue;
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
        
        for(int v: adjList[u]){
            if(visited[v] == true) continue;
            q.push(v);
            visited[v] = true; 
        }

    
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
    int cc =0;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        //either u can use dfs or bfs 
        dfs(i);
        cc++;
    }

    cout<<"Number of connected components: "<<cc;


    return 0;
}


//sample input
// 7  
// 5
// 1 2
// 1 3
// 2 3
// 2 4
// 5 6

