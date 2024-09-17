#include<bits/stdc++.h>
using namespace std;


typedef pair<int,int> pii;
const int N = 1e3 + 7;
const int INF = 1e9 + 7; 
vector <pii> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int source){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source],source});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(pii vpair: adj[u]){
            int v = vpair.first;
            int w = vpair.second; 

            if(visited[v]) continue;;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w; 
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
    }

    int s,d; 
    cin>>s>>d;

	dijkstra(s);
	
	for(int i=1;i<=n;i++)
    {
		if(i== d){
			cout<<"Distance of node";
			cout<<" : "<<dist[i]<<endl;
		}
    }

    return 0;
}

// 6 9
// 1 2 5
// 2 3 2
// 1 3 10
// 3 4 1
// 4 1 5
// 1 5 9
// 5 6 1
// 2 6 4
// 2 5 2