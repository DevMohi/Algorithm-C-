#include<bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int> adj[N];
bool visited[N];
int level[N]; 


void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: adj[u]){
            if(visited[v]) continue;
            visited[v] = true;
            level[v] = level[u] + 1; 
            q.push(v);
        }
    }
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


    int l;
    cin>>l; 

    for (int i = 0; i < N; i++) {
        visited[i] = false;
        level[i] = -1; 
    }


    for (int i = 0; i < N; i++) {
        if (!adj[i].empty()) {  
            bfs(i);
            break;
        }
    }


    bfs(0);

    vector<int> result;

    for(int i=0; i<N; i++){
        if(level[i] == l) result.push_back(i);
    }

    if(result.empty()){
        cout<<"-1"<<endl;
    }
    else{
        sort(result.begin(), result.end());
        for(int x: result){
            cout<<x<<" ";
        }
        cout<<endl; 
    }

    return 0;
}