#include<bits/stdc++.h>
using namespace std;

const int INF = 100;

int main(){
    int n;
    cin>>n;

    int dis[n+1][n+1];
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n; j++){
            cin>>dis[i][j]; 
            if(i == j){
                dis[i][j] = 0;
            }
        }
    }

    // while(n--){
    //     int a,b,w;
    //     cin>>a>>b>>w;
    //     dis[a][b] = w;
    // }

    for(int k = 1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n ; j++){
                if(dis[i][k] + dis[k][j] <dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                } 
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}