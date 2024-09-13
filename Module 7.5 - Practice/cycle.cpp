// Question: You will be given an undirected graph as input. Now print “YES” if there is a cycle and print “NO” if there isn’t any cycle. Consider root as 1.


#include<bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

bool dfs(int u, int p = -1){
    visited[u] = true;
    bool cycleExist = false;

    //v hocce child, child can go back to its parent tai continue korse 
    for(int v: adjList[u]){
        if(v == p){
            continue;
        }
        if(visited[v]) return true;
        cycleExist = dfs(v,u); 
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

    for(int i=1; i<=n; i++){
        cout<<"Node "<<i<<": ";
        for(int j: adjList[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    bool isCycle = false;

    for(int i=1; i<=n ; i++){
        // cout<<i<<endl; 
        if(visited[i]) continue;
        else{
            isCycle = dfs(i);
        }
    }

    if(isCycle){
        cout<<"Cycle detected";
    }
    else{
        cout<<"No cycle";
    }
   
    return 0;
}