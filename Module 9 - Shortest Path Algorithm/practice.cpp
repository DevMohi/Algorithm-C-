// #include<bits/stdc++.h>
// using namespace std;


// const int N = 1e3 + 5;
// vector<int> adj[N];
// bool visited[N];
// int level[N];
// int parent[N];

// void bfs(int s){
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;
//     level[s] = 0; 
//     parent[s] = -1; 

//     while(!q.empty()){
//         int u = q.front();
//         q.pop();

//         for(int v: adj[u]){
//             if(visited[v] == true) continue; 
//             q.push(v);
//             visited[v] = true;
//             level[v] = level[u] + 1;
//             parent[v] = u; 
//         }
//     }
// }



// int main(){
//     int n, m;
//     cin>> n >> m;


//     for(int i=0; i<m ; i++){
//         int u,v;
//         cin>>u>>v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int s,d;
//     cin>>s>>d;

//     bfs(s); //1 to 7 distance for example 

//     cout<<"Distance: "<<level[d]<<endl; 

//     vector<int> path;
//     int current = d;
    
//     //backtracking from 7 to 1
//     while(current != -1){
//         path.push_back(current);
//         current = parent[current];
//     }

//     reverse(path.begin(), path.end());

//     cout<<"Path: ";
//     for(int node: path){
//         cout<<node<<" ";
//     }

//     return 0;
// }


//Dijkstra algorithm 

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 1e3+7;
const int INF = 1e9+7;
vector<pii> adj[N];

//Initialize all values of dist with infinity
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source){
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while(!pq.empty()){
        int u = pq.top().second; //1 2 3 4 5 6 7 
        
        pq.pop();
        visited[u] = true; 


        //u er modde ase v ar w 
        for(pii vpair: adj[u]){
            int v = vpair.first;
            int w = vpair.second; 
            if(visited[v]) continue;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w; 
                // cout<<dist[v]<<":"<<dist[u]<<" + "<<w<<endl; 
                pq.push({dist[v], v});    
            }
        } 
    }
}


int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
    	int u,v,w;
    	cin >> u >> v >> w;
    	adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(1);

    for(int i=1;i<=n;i++)
    {
    	cout << "Distance of node " << i;
    	cout << " : " << dist[i] << endl;
    }
    return 0;
}