/*

    August 18, 2026
    CSES Problemset - Counting Rooms
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void dfs(vector<vector<char>>& grid, vector<vector<ll>>& visited, ll i, ll j) {
    visited[i][j] = 1;
    if (i > 0 && grid[i - 1][j] == '.' && visited[i - 1][j] == 0) {
        dfs(grid, visited, i - 1, j);
    }
    if (j > 0 && grid[i][j - 1] == '.' && visited[i][j - 1] == 0) {
        dfs(grid, visited, i, j - 1);
    }
    if (i < grid.size() - 1 && grid[i + 1][j] == '.' && visited[i + 1][j] == 0) {
        dfs(grid, visited, i + 1, j);
    }
    if (j < grid[0].size() - 1 && grid[i][j + 1] == '.' && visited[i][j + 1] == 0) {
        dfs(grid, visited, i, j + 1);
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid (n, vector<char> (m));
    vector<vector<ll>> visited (n, vector<ll> (m, 0));
    for (auto& row : grid) {
        for (auto& cell : row) {
            cin >> cell;
        }
    }

    ll counter = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == '.' && visited[i][j] == 0) {
                counter++;
                dfs(grid, visited, i, j);
            }
        }
    }
    cout << counter << '\n';
    return 0;
}