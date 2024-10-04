#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n,m;
char a[N][N];
bool vis[N][N];
vector <pair<int,int>> path = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int ci, int cj){
    if(ci >=0 && ci <n && cj>=0 && cj<m && a[ci][cj] == '.'){
        return true;
    }
    else{
        return false; 
    }
}

int cnt;
void dfs(int si, int sj){
    vis[si][sj] = true;
    cnt++; 

    for(int i=0; i<4; i++){
        pair<int, int> p = path[i];
        int ci = si + p.first;
        int cj = sj + p.second;

        if(isValid(ci,cj) && !vis[ci][cj]){
            dfs(ci,cj); 
        }
    }
}

int main(){
    cin>>n>>m;
    int mn = INT_MAX; 

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && a[i][j] == '.'){
                cnt = 0; 
                dfs(i,j);
                mn = min(cnt,mn);
            }
        }
    }

    if(cnt == 0){
        cout<<-1<<endl; 
    }
    else{
        cout<<mn<<endl;
    }

    return 0;
}