 #include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentSize[1000];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

int mx = 0; 
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
            mx = max(mx, parentSize[leaderA]); 
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
            mx = max(mx, parentSize[leaderB]); 
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    //Node 5 ta hoile component 5 ta g
    int cmp = n;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        //Jokon different group 
        if(leaderA != leaderB){
            cmp--;
            dsu_union(a, b);
            
        }
        cout<<cmp<<" "<<mx<<endl;
    }
    // cout << dsu_find(6); ss last
    return 0;
}

// 7 4
// 1 2 
// 2 3 
// 4 5 
// 6 5 
//2 2 