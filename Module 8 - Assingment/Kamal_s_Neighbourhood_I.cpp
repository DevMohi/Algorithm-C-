//Solved 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin>>k;

    vector<int> result;
    for(int i=0; i<n; i++){
        if(k == i){ // k aikane 2 
            for(int j: adj[i]){
                result.push_back(j);
            }
        }
    }
    cout<<result.size();

    return 0;
}