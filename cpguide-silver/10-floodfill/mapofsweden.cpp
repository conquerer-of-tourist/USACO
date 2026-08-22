/*

    August 20, 2026
    Map of Sweden - Kattis IO
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int swedenSize = 0;
int r, c, u, s1, s2;

void dfs(vector<vector<int>>& grid,
         vector<vector<int>>& visited,
         int i, int j) {

    if (i < 0 || i >= r || j < 0 || j >= c) return;
    if (grid[i][j] == 0) return;
    if (visited[i][j]) return;

    visited[i][j] = 1;
    swedenSize++;

    dfs(grid, visited, i - 1, j);
    dfs(grid, visited, i + 1, j);
    dfs(grid, visited, i, j - 1);
    dfs(grid, visited, i, j + 1);
}

int main()
{
    cin >> r >> c >> u;
    vector<vector<int>> grid (r, vector<int> (c, 0));
    vector<vector<int>> visited (r, vector<int> (c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char a;
            cin >> a;
            if (a == '.') grid[i][j] = 0;
            if (a == '#') grid[i][j] = 1;
            if (a == 'S') {
                grid[i][j] = 2;
                s1 = i;
                s2 = j;
            }
        }
    }
    dfs(grid, visited, s1, s2);
    cout << swedenSize << '\n';
    
    while (u--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        grid[a][b] = 1;

        bool connectsToSweden = false;

        if (a > 0 && visited[a - 1][b])     connectsToSweden = true;
        if (b > 0 && visited[a][b - 1])     connectsToSweden = true;
        if (a < r - 1 && visited[a + 1][b]) connectsToSweden = true;
        if (b < c - 1 && visited[a][b + 1]) connectsToSweden = true;

        if (connectsToSweden == true) {
            dfs(grid, visited, a, b);
        }

        cout << swedenSize << '\n';
    }
}