/*

    August 21, 2026
    Cross Country Skiing - January 2014 Silver | Problem 2
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

int m, n, counter = 0;

int dfs(int mid, int i, int j,
        vec<vec<int>>& visited,
        vec<vec<int>>& grid, 
        vec<vec<int>>& waypoints) {

    int ans = 0;
    visited[i][j] = 1;

    if (i > 0 && visited[i - 1][j] == 0 && abs(grid[i][j] - grid[i - 1][j]) <= mid)
        ans += dfs(mid, i - 1, j, visited, grid, waypoints);

    if (j > 0 && visited[i][j - 1] == 0 && abs(grid[i][j] - grid[i][j - 1]) <= mid)
        ans += dfs(mid, i, j - 1, visited, grid, waypoints);

    if (i < m - 1 && visited[i + 1][j] == 0 && abs(grid[i][j] - grid[i + 1][j]) <= mid)
        ans += dfs(mid, i + 1, j, visited, grid, waypoints);

    if (j < n - 1 && visited[i][j + 1] == 0 && abs(grid[i][j] - grid[i][j + 1]) <= mid)
        ans += dfs(mid, i, j + 1, visited, grid, waypoints);
    
    if (waypoints[i][j] == 1) {
        ans++;
    }

    return ans;
}

bool check(int mid, vec<vec<int>>& grid, vec<vec<int>>& waypoints) {
    vec<vec<int>> visited (m, vec<int> (n, 0));

    int countHere = dfs(mid, 0, 0, visited, grid, waypoints);

    if (countHere < counter) {
        return false;
    }
    return true;
}

int main()
{
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> m >> n;
    vec<vec<int>> grid (m, vec<int> (n, 0));
    vec<vec<int>> waypoints (m, vec<int> (n, 0));
    for (auto& row : grid) {
        for (auto& c : row) {
            cin >> c;
        }
    }
    for (auto& row : waypoints) {
        for (auto& c : row) {
            cin >> c;
            if (c == 1) {
                counter++;
            }
        }
    }

    int l = 0, r = 1e9 + 67;
    int ans = r;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, grid, waypoints)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}