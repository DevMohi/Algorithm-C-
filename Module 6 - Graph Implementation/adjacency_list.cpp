#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m;i++){
        int u,v;
        cin>>u>>v;
        //For directed
        adj[u].push_back(v);

        // For undirected you need to add this code 
        // adj[v].push_back(u); 
    }

    for(int i=1; i<=n; i++){
        cout<<"List "<<i<<": ";
        for(int j: adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
