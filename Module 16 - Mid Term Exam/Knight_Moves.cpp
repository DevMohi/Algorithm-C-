#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int n,m;
char a[N][N];
bool vis[N][N];
int dis[N][N];

vector <pair<int,int>> path = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool isValid(int ci, int cj){
    if(ci >=0 && ci <n && cj>=0 && cj<m){
        return true;
    }
    else{
        return false; 
    }
}

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;

    while(!q.empty()){
        pair<int, int> parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();

        for(int i=0; i<8; i++){
            pair<int,int> p = path[i];
            int ci = pi + p.first;
            int cj = pj + p.second; 

            if(isValid(ci,cj) && !vis[ci][cj]){
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[pi][pj] + 1;
            }
        }
    }
}

void reset(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dis[i][j] = 0;
            vis[i][j] = false; 
        }
    }
}


int main(){

    int t;
    cin>>t;

    while(t--){
        cin>>n>>m;
        int si,sj, qi, qj;
        cin>>si>>sj>>qi>>qj; 
        reset();
        bfs(si,sj);
        if(vis[qi][qj]){
            cout<<dis[qi][qj]<<endl; 
        }
        else{
            cout<<-1<<endl; 
        }
    }
    return 0;
}