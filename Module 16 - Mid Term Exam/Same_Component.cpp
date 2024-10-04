#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n,m;
char a[N][N];
bool vis[N][N];
int dis[N][N];

vector <pair<int,int>> path = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int ci, int cj){
    if(ci >=0 && ci <n && cj>=0 && cj<m && a[ci][cj] == '.'){
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
    vis[si][sj] = 0;

    while(!q.empty()){
        pair<int, int> parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();

        for(int i=0; i<4; i++){
            pair<int,int> p = path[i];
            int ci = pi + p.first;
            int cj = pj + p.second; 

            if(isValid(ci,cj) && !vis[ci][cj]){
                vis[ci][cj] = true;
                q.push({ci,cj});
                dis[ci][cj] =dis[pi][pj] + 1;
            }
        }
    }
}


int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    int si, sj, di, dj;
    cin>> si>> sj >> di >> dj;

    bfs(si, sj);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if(dis[di][dj] != 0){
        cout<<"YES";
    }
    else{
        cout<<"NO"; 
    }

    return 0;
}