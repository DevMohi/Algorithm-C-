#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v: adjList[u]) {
        if (!visited[v]) {
            dfs(v, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Clear adjacency list and visited array for multiple test cases
    for (int i = 0; i < N; i++) {
        adjList[i].clear();
        visited[i] = false;
    }

    // Reading the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int cc = 0;
    vector<vector<int>> components;

    // Finding connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, component);
            components.push_back(component);
            cc++;
        }
    }

    // Output number of connected components
    cout << cc << endl;

    // Print each component
    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << " : ";
        for (int node : components[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
