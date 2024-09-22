#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+ 5;
int dis[N];
bool vis[N];
int parent[N];
vector<int> v[N];

void bfs(int s){
    queue<int>q;
    q.push(s);
    dis[s] = 0; 
    parent[s] = -1; 
    vis[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int child:v[u]){
            if(!vis[child]){
                q.push(child);
                parent[child] = u;  
                vis[child] = true; 
                dis[child] = dis[u] + 1;
            }
        }
    }
}


int main(){
    int n,e;
    cin>>n>>e;

    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(1);
    // for(int i=1; i<=n; i++){
    //     cout<<"Node "<<i<<": "<<parent[i]<<endl;
    // }

    int d;
    cin>>d;

    if(vis[d]){
        vector<int> path; 
        int x =d; //loop through korbe parents backward 
        while(x!= -1){
            // cout<<endl;  
            path.push_back(x); 
            x = parent[x];
        }
        reverse(path.begin(),path.end()); 
        for(int val: path){
            cout<<val<<" "; 
        }
    }
    else{
        cout<<"Path nai"<<endl; 
    }


    return 0;
}


// 5 5 
// 1 3
// 1 2
// 3 4
// 2 3
// 2 4
// 5