/*

    August 19, 2026
    D. Solve The Maze (Codeforces Round 648, Division 2)
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
    visited[i][j] = 1;
    int ans = (grid[i][j] == 2) ? 1 : 0;
    if (i > 0 && visited[i - 1][j] == 0 && grid[i - 1][j] != 1) {
        ans += dfs(grid, visited, i - 1, j);
    }
    if (j > 0 && visited[i][j - 1] == 0 && grid[i][j - 1] != 1) {
        ans += dfs(grid, visited, i, j - 1);
    }
    if (i < grid.size() - 1 && visited[i + 1][j] == 0 && grid[i + 1][j] != 1) {
        ans += dfs(grid, visited, i + 1, j);
    }
    if (j < grid[0].size() - 1 && visited[i][j + 1] == 0 && grid[i][j + 1] != 1) {
        ans += dfs(grid, visited, i, j + 1);
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid (n, vector<int> (m));
    vector<vector<int>> visited (n, vector<int> (m, 0));

    int countGood = 0;
    for (auto& a : grid) {
        for (auto& b : a) {
            char k;
            cin >> k;
            if (k == '.') b = 0;
            if (k == '#') b = 1;
            if (k == 'G') b = 2;
            if (k == 'B') b = 3;

            if (b == 2) countGood++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 3) {
                if (i > 0 && grid[i - 1][j] == 0) {
                    grid[i - 1][j] = 1;
                }
                if (j > 0 && grid[i][j - 1] == 0) {
                    grid[i][j - 1] = 1;
                }
                if (i < n - 1 && grid[i + 1][j] == 0) {
                    grid[i + 1][j] = 1;
                }
                if (j < m - 1 && grid[i][j + 1] == 0) {
                    grid[i][j + 1] = 1;
                }

                if (i > 0 && grid[i - 1][j] == 2) {
                    cout << "No" << '\n'; return;
                }
                if (j > 0 && grid[i][j - 1] == 2) {
                    cout << "No" << '\n'; return;
                }
                if (i < n - 1 && grid[i + 1][j] == 2) {
                    cout << "No" << '\n'; return;
                }
                if (j < m - 1 && grid[i][j + 1] == 2) {
                    cout << "No" << '\n'; return;
                }
            }
        }
    }

    int counter = (grid[n - 1][m - 1] != 1) ?  dfs(grid, visited, n - 1, m - 1) : 0;

    if (counter == countGood) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}