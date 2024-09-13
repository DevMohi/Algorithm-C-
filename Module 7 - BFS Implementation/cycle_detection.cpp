//Bfs implementation and level 

#include<bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];


// u hocce node, p hocce parent 
bool dfs(int u , int p = -1){

    bool cycleExist = false; 
    visited[u] = true;
    for(int v: adjList[u]){
        if(v == p){
            continue; 
        }
        if(visited[v]) return true;
        cycleExist  = dfs(v , u);

        //line 21 can be written as 
        // cycleExist = cycleExist | dfs(v, u); 
    }
    return cycleExist; 
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

    // // - 1 disi because shuru tah 1 e rkono parent nai 
    // if(dfs(1 , -1)){
    //     cout<<"Cycle detected";
    // }
    // else{
    //     cout<<"No Cycle";
    // }

    bool isCycle = false;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        isCycle = dfs(i);
        //line 52 can be written ase
        // isCycle |= dfs(i); 
    }

    if(isCycle){
        cout<<"Cycle detected";
    }
    else{
        cout<<"No cycle";
    }

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

