/*

    August 18, 2026
    USACO 2019 Silver January - Problem 2. Icy Perimeter
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

int n;
int curArea = 0;
int curPerim = 0;

void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
    visited[i][j] = 1;
    curArea++;
    if (i == 0) curPerim++;
    if (j == 0) curPerim++;
    if (i == n - 1) curPerim++;
    if (j == n - 1) curPerim++;

    if (i < n - 1 && grid[i + 1][j] == 0) curPerim++;
    if (j < n - 1 && grid[i][j + 1] == 0) curPerim++;
    if (i > 0 && grid[i - 1][j] == 0) curPerim++;
    if (j > 0 && grid[i][j - 1] == 0) curPerim++;
    
    if (i > 0 && grid[i - 1][j] == 1 && visited[i - 1][j] == 0) {
        dfs(grid, visited, i - 1, j);
    }
    if (j > 0 && grid[i][j - 1] == 1 && visited[i][j - 1] == 0) {
        dfs(grid, visited, i, j - 1);
    }
    if (i < n - 1 && grid[i + 1][j] == 1 && visited[i + 1][j] == 0) {
        dfs(grid, visited, i + 1, j);
    }
    if (j < n - 1 && grid[i][j + 1] == 1 && visited[i][j + 1] == 0) {
        dfs(grid, visited, i, j + 1);
    }
}

int main()
{
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    vector<vector<int>> grid (n, vector<int> (n));
    vector<vector<int>> visited (n, vector<int> (n, 0));
    for (auto& a : grid) {
        for (auto& b : a) {
            char c; cin >> c;
            if (c == '#') b = 1;
            else b = 0;
        }
    }
    int bestArea = 0;
    int bestPerim = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0 && grid[i][j] == 1) {
                dfs(grid, visited, i, j);
            }
            if (curArea > bestArea) {
                bestArea = curArea;
                bestPerim = curPerim;
            }
            else if (curArea == bestArea) {
                bestPerim = min(bestPerim, curPerim);
            }
            curArea = 0;
            curPerim = 0;
        }
    }
    cout << bestArea << " " << bestPerim << '\n';
    return 0;
}