//Bfs implementation and level 

#include<bits/stdc++.h>
using namespace std;

const int N  = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
int level[N];
int parent[N];


//O(n + m )
void bfs(int s){

    queue<int> q;
    q.push(s); //Push kore felle q visited
    visited[s] = true; 
    level[s] = 0; 
    //initially parent k ekta value set korte hobe
    parent[s] = -1; 

    while(!q.empty()){
        //Pop a node from the queue and insert unvisited neighbours from the queu
        int u = q.front();
        q.pop();
        // cout<<"Visiting node: "<<u<<endl;  
        
        for(int v: adjList[u]){
            //section 2 : chhild processing
            if(visited[v] == true) continue;
            q.push(v);
            visited[v] = true; 
            level [v] = level[u] + 1; 
            parent[v] = u;
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

    //d is destination 
    int s,d; 
    cin>>s>>d;

    bfs(s);

    cout<<"Distance: "<<level[d]<<endl; 


    //Run this to see parent 
    // for(int i=1; i<=n; i++){
    //     cout<<"Parent of "<<i<<": "<<parent[i];
    //     cout<<endl;
    // }


    //Path finding worst case - O(N)
    vector <int> path;
    int current = d;
    while(current != -1){
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());
    
    cout<<"Path: ";
    for(int node: path){
        cout<<node<<" ";
    }

    return 0;
}

//Bfs complexity O(n+m) , same for dfs 
//sample input
// 7 7
// 1 2
// 1 3
// 3 4
// 4 6
// 2 5
// 5 6 
// 5 7
// 1 
// 7


