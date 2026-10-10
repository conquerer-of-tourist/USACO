/*

    USACO Silver - Switching on the Lights
    P2 2015 December

    Hengsheng Wang
    October 10, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int n, m;

void dfs(ve<ve<int>>& grid, ve<ve<int>>& visited, int a, int b, map<int, ve<int>>& adj) {
    for (auto& k : adj[1000 * a + b]) {
        grid[k / 1000][k % 1000] = 1;

        if (visited[k / 1000][k % 1000] == 1) continue;

        if ((k / 1000 > 0 && visited[k / 1000 - 1][k % 1000] == 1) ||
            (k % 1000 > 0 && visited[k / 1000][k % 1000 - 1] == 1) ||
            (k / 1000 < n - 1 && visited[k / 1000 + 1][k % 1000] == 1) ||
            (k % 1000 < n - 1 && visited[k / 1000][k % 1000 + 1] == 1)) {
            visited[k / 1000][k % 1000] = 1;
            dfs(grid, visited, k / 1000, k % 1000, adj);
        }
    }
    if (a > 0 && visited[a - 1][b] == 0 && grid[a - 1][b] == 1) {
        visited[a - 1][b] = 1;
        dfs(grid, visited, a - 1, b, adj);
    }
    if (a < n - 1 && visited[a + 1][b] == 0 && grid[a + 1][b] == 1) {
        visited[a + 1][b] = 1;
        dfs(grid, visited, a + 1, b, adj);
    }
    if (b > 0 && visited[a][b - 1] == 0 && grid[a][b - 1] == 1) {
        visited[a][b - 1] = 1;
        dfs(grid, visited, a, b - 1, adj);
    }
    if (b < n - 1 && visited[a][b + 1] == 0 && grid[a][b + 1] == 1) {
        visited[a][b + 1] = 1;
        dfs(grid, visited, a, b + 1, adj);
    }
}

int main()
{
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    ve<ve<int>> visited (n, ve<int> (n, 0));
    ve<ve<int>> grid (n, ve<int> (n, 0));

    map<int, ve<int>> adj;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        adj[1000 * a + b].push_back(1000 * c + d);
    }

    visited[0][0] = 1;
    grid[0][0] = 1;
    dfs(grid, visited, 0, 0, adj);

    int answer = 0;
    for (auto& abab : grid) {
        for (auto& cdcd : abab) {
            answer += cdcd;
        }
    }
    cout << answer << '\n';
}