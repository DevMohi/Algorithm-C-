//Bfs implementation and level 

#include<bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
int level[N];

void bfs(int s){
    queue<int> q;
    q.push(s); //Push kore felle q visited
    visited[s] = true; 
    level[s] = 0; 

    while(!q.empty()){
        //Pop a node from the queue and insert unvisited neighbours from the queu
        int u = q.front();
        q.pop();
        cout<<"Visiting node: "<<u<<endl; 
        
        for(int v: adjList[u]){
            //section 2 : chhild processing
            if(visited[v] == true) continue;
            level [v] = level[u] + 1; 
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
    bfs(1);

    for(int i=1; i<=n; i++){
        cout<<"Level of node "<<i<<" : "<<level[i]<<endl;
    }

    return 0;
}


//sample input
// 12
// 11
// 1 2 
// 1 3
// 1 10
// 2 4
// 2 5
// 3 9
// 5 6
// 5 7 
// 7 8
// 10 11
// 10 12 

