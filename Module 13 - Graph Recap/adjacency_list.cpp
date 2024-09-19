#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    //array of vector ek ghor barti nibo 
    vector<int> adj[n+1];

    while(e--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    for(int i=0; i<=n; i++){
        cout<<"Index "<<i<<": ";
        for(int v: adj[i]){
            cout<<v<<" ";
        } 
        cout<<endl; 
    }

    return 0;
}