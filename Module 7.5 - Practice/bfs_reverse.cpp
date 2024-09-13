#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool visited[N];
stack<int> st;

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
  

    while(!q.empty()){
        int u = q.front();
        q.pop();
        st.push(u);
        // cout<<"Visiting node: "<<u<<endl; 

        for(int v: adj[u]){
            if(visited[v] == true) continue;
            q.push(v);
            visited[v] = true; 
            
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

    // for(int i=1; i<=n; i++){
    //     cout<<"Node "<<i<<": ";
    //     for(int j: adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl; 
    // }
    bfs(1);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}