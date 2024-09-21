#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> v[N];
int dis[N]; 

void dijkstra(int source){
    queue<int> q;
    q.push(source);
    dis[source] = 0;
    while(!q.empty()){
        int parent =q.front();
        q.pop();

        for(int i=0;i<v[parent].size(); i++){
            //age integer ber hoito ekn pair ber hoi forom parent so 
            pair<int, int> child = v[parent][i]; 
            int childNode = child.first;
            int childCost = child.second; 
            if(dis[parent] + childCost < dis[childNode]){
                dis[childNode] = dis[parent] + childCost; 
                q.push(childNode);
            }
        }
    } 

}

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w}); 
    }

    //Shobai k infinity set kore dibo
    for(int i=1; i<=n; i++){
        dis[i] = INT_MAX;
    }

    dijkstra(1);
    for(int i=1; i<=n; i++){
        cout<<"node"<<i<<": "<<dis[i]<<endl;
    }
    return 0;
}

//Complexity : O(N*E) 
// 5
// 7
// 1 3 2 
// 1 2 10
// 2 3 1 
// 3 4 2
// 4 5 7
// 2 4 3
// 2 5 2

// node1: 0
// node2: 3
// node3: 2
// node4: 4
// node5: 5