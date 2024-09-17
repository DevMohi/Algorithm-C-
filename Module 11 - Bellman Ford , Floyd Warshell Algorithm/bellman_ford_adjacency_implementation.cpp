#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pii> adj[N];
// vector<int> dist(N, INF); 

//pair of pair
vector<pair<pii,int>> list_of_edges; 
int dist[N];
int n,m;


void bellman_ford(int s){
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    dist[s] = 0; 

    //Loop cholbe n-1 times with relaxation
    for(int i=1; i<n; i++){
        //all edges relaxation  
        //This code is like for n nodes, aita n-1 cholbe and for each node and its child aita run hobe 
        for(int u= 1; u<=n; u++){
            for(pii vpair: adj[u]){
                int v = vpair.first;
                int w = vpair.second; 

                if(dist[u]!= INF &&  dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main(){ 
    cin>>n>>m;
    while(m--){
        int u, v,w;
        cin>> u>> v>> w;
        adj[u].push_back({v,w});
    }

    bellman_ford(1);

    for(int i=1; i<=n;i++){
        cout<<"Distance of "<<i;
        cout<<": "<<dist[i]<<endl;
    }
    return 0;
}

//O(nm)
//O(n*n) sparse hoile
//Edges beshi thakle o(ncube)