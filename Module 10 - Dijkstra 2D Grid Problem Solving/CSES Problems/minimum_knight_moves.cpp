#include<bits/stdc++.h>
using namespace std;


typedef pair<int, int> pii;
vector <string> g;
const int N = 1e3 + 10;
int level[N][N];
bool visited[N][N]; 
vector<pii> direction = {{1,2},{1,-2},{-1,2},{-1,-2}, {2,1} , {2,-1}, {-2,1}, {-2,-1}};

void reset_level_vis(){
    for(int i=0; i<8; i++){
        for(int j =0 ; j<8 ; j++){
            level[i][j] = 0;
            visited[i][j] = false; 
        }
    }
}

// ai scope er modde ase naki check 
bool isValid(int i, int j){
    return (i >= 0 && i < 8 && j >= 0 && j <8);
}

void bfs(int si, int sj){
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty()){
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for(auto d: direction){
            int ni = i + d.first;
            int nj = j + d.second; 

            if(isValid(ni,nj) && !visited[ni][nj]){
                q.push({ni,nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                
            }
        }
    }
}

int main(){
    int n;
    cin>>n; 

    for(int i=0; i<n; i++){
        string x , y;
        cin>>x >> y;
        int si, sj, di, dj;
        si = x[0] - 'a';
        sj = x[1] - '1';
        di = y[0] - 'a';
        dj = y[1] - '1';
        // cout<<si<<endl;
        // cout<<sj<<endl;
        // cout<<di<<endl;
        // cout<<dj<<endl;

        //shortest path
        bfs(si,sj);
        cout<<level[di][dj]<<endl;

        //Multiple tai shobaike zero kore diba
        

    }

    return 0;
}