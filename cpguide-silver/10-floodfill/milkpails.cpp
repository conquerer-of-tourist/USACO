/*

    Hengsheng Wang
    August 22, 2026

    USACO 2016 February Contest, Silver
    Problem 3. Milk Pails

*/

#include <bits/stdc++.h>
using namespace std;

int x, y, k, m;

int dfs(int a, int b, int moves, vector<vector<int>>& fastest) {
    int closest = INT_MAX;
    closest = min(closest, abs(m - a - b));
    
    if (moves == k) {
        return closest;
    }

    if (fastest[a][b] <= moves) {
        return closest;
    }

    fastest[a][b] = moves;

    closest = min(closest, dfs(0, b, moves + 1, fastest));
    closest = min(closest, dfs(a, 0, moves + 1, fastest));
    closest = min(closest, dfs(x, b, moves + 1, fastest));
    closest = min(closest, dfs(a, y, moves + 1, fastest));

    if (a + b > x) {
        closest = min(closest, dfs(x, a + b - x, moves + 1, fastest));
    }
    else {
        closest = min(closest, dfs(a + b, 0, moves + 1, fastest));
    }
    if (a + b > y) {
        closest = min(closest, dfs(a + b - y, y, moves + 1, fastest));
    }
    else {
        closest = min(closest, dfs(0, a + b, moves + 1, fastest));
    }
    return closest;
}

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> x >> y >> k >> m;

    vector<vector<int>> fastest (x + 1, vector<int> (y + 1, INT_MAX));

    int closest = dfs(0, 0, 0, fastest);
    cout << closest << '\n'; 
}