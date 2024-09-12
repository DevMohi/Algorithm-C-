//  You will be given a directed graph as input. Store this graph in an adjacency list. Now, convert this adjacency list to an adjacency matrix (index starting from 1) and print it. Consider root as 1.

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
const int N2 = 1e3+5;
int adjMatrix[N2][N2] = {0};  // For fixed size, initialize to 0


int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adjList[u].push_back(v);
    }

    //Convert the adjacency list to an adjacency matrix
    for(int i=1; i<=n; i++){
        for(int v: adjList[i]){
            adjMatrix[i][v] = 1;
        }
    }
    

    for(int i=1; i<=n;i++){
        cout<<"Node "<<i<<": ";
        for(int j: adjList[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout << "\nAdjacency Matrix:" << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}