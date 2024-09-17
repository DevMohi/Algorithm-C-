#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;  // Pair to store coordinates of grid cells
const int N = 1e3 + 10;      // Grid limit
vector<string> g;            // The grid itself
int visited[N][N];           // Visited array
int level[N][N];             // Level array (stores number of steps from start)
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};  // Directions: left, right, up, down
int n, m;                    // Grid dimensions
pii start, ending;           // Coordinates of 's' and 'e'
pii parent[N][N];            // Parent array to store path

// Check if the current cell is within bounds and is traversable
bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && g[i][j] != 'x');
}

// Perform BFS from the start point
void bfs(int i, int j) {
    queue<pii> q;
    q.push({i, j});  // Start BFS from the 's' position
    visited[i][j] = true;
    level[i][j] = 0;  // Starting point has 0 steps
    parent[i][j] = {-1, -1};  // Mark the parent of start as invalid

    while (!q.empty()) {
        pii u_pair = q.front();
        int u = u_pair.first;
        int v = u_pair.second;
        q.pop();

        // Explore the four possible directions
        for (auto d : direction) {
            int ni = u + d.first;
            int nj = v + d.second;

            // If the neighboring cell is valid and unvisited, process it
            if (isValid(ni, nj) && !visited[ni][nj]) {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[u][v] + 1;  // Increment step count
                parent[ni][nj] = {u, v};  // Track parent to reconstruct path
            }
        }
    }
}

int main() {
    // Read grid dimensions
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
            if (g[i][j] == 's') start = {i, j};  // Start point
            if (g[i][j] == 'e') ending = {i, j};  // End point
        }
    }

    // Run BFS from the start point 's'
    bfs(start.first, start.second);

    // Output the number of steps to reach 'e'
    if (visited[ending.first][ending.second]) {
        cout << level[ending.first][ending.second] << endl;  // Steps to 'e'
    } else {
        cout << -1 << endl;  // If 'e' is unreachable, print -1
        return 0;
    }

    // Reconstruct the path
    vector<pii> path;
    pii curr = ending;

    while (curr != start) {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }
    path.push_back(start);  // Add the start node
    reverse(path.begin(), path.end());

    // Output the directions in the form of R, L, U, D
    for (int i = 1; i < path.size(); i++) {
        // Compare consecutive cells to determine direction
        if (path[i - 1].first == path[i].first) {
            if (path[i - 1].second == path[i].second - 1)
                cout << "R";  // Right
            else
                cout << "L";  // Left
        } else {
            if (path[i - 1].first == path[i].first - 1)
                cout << "D";  // Down
            else
                cout << "U";  // Up
        }
    }

    return 0;
}
