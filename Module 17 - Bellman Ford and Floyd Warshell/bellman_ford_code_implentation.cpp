#include<bits/stdc++.h>
using namespace std;

class Edge{
    public: 
        int u;
        int v;
        int w; 
        Edge(int u, int v, int w){
            this -> u = u;
            this -> v = v;
            this -> w = w;
        }
};

int main(){
    int n,e;
    vector<Edge> v;
    cin>>n>>e;

    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
        Edge ed(a,b,w);
        // cout<<ed.u<<" "<<ed.v<<" "<<ed.w<<endl; 
        v.push_back(ed);
    }
    //Setting infinity 
    int dis[n+1];
    for(int i=1; i<=n; i++){
        dis[i] = INT_MAX; 
    }
    //Source er value ta 0 hoite hobe
    dis[1] = 0; 

    for(int i=1; i<=n-1; i++){
        for(int j=0; j<v.size();j++){
            Edge ed = v[j]; 
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;

            //Relaxation 
            if(dis[a] + w < dis[b]){
                dis[b] = dis[a] + w; 
            }
        }
    }

    for(int i =1; i<=n; i++){
        cout<<"Node "<<i<<": "<<dis[i]<<endl; 
    }

    return 0;
}