#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii; 
const int N = 1e3 + 10;
vector<string> g;  // The grid itself
int visited[N][N];  // Visited array
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};  // Directions: left, right, up, down
int n, m;  // Grid dimensions
pii start;  // Coordinates of 's' and 'e'
pii ending; 
bool found = false;  // Flag to check if we found the path

// Check if the current cell is within bounds and is traversable
bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && g[i][j] != 'x' && !visited[i][j]);
}

// Perform DFS from the current cell
void dfs(int i, int j) {
    if (!isValid(i, j)) return;  // If not valid, return

    visited[i][j] = true;  // Mark the current cell as visited

    // If we reached the end 'e', set the flag and return
    if (g[i][j] == 'e') {
        found = true;
        return;
    }

    // Explore all 4 possible directions
    for (auto d : direction) {
        dfs(i + d.first, j + d.second);
        if (found) return;  // If path to 'e' is found, no need to continue
    }
}

int main() {
    cin >> n >> m;

    // Read the grid
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        g.push_back(x);
    }

    // Find the coordinates of 's' and 'e'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 's') start = {i, j};
            if (g[i][j] == 'e') ending = {i, j};
        }
    }

    // Run DFS from the start point 's'
    dfs(start.first, start.second);

    // Output result based on whether we found a path to 'e'
    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
