// Question: You will be given an adjacency matrix for a directed graph (index starting from 1) as input. Now, convert it to an adjacency list and print it.


#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adjmat[N][N];

int main(){
    int n,m;
    cin>>n;

    vector<int> adjList[n + 1];

    for(int i=1; i<=n; i++){
        // cout<<"printing"<<endl;  
        for(int j=1; j<=n ; j++){
            int edge;
            cin >>edge;
            // cout<<edge<<" "<<j<<" ";  
            if(edge == 1){
                adjList[i].push_back(j);
            }
        }
        // cout<<endl; 
    }


    //Printing list
    // for(int i = 1; i<=n ; i++){
    //     cout<<"Node "<<i<<": ";
    //     for(int j: adjList[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }


    return 0;
}