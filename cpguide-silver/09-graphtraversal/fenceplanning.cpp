/*

    August 15, 2026
    Problem 3. Fence Planning (2019 US Open, Silver)

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<int, int>
#define x first
#define y second

vector<int> visited;
vector<p> cows;
vector<vector<int>> adj;

void dfs(int& minX, int& minY, int& maxX, int& maxY, int ind)
{
    for (auto& connection: adj[ind]) {
        if (visited[connection] == 0) {
            visited[connection] = 1;

            minX = min(cows[connection].x, minX);
            maxX = max(cows[connection].x, maxX);
            minY = min(cows[connection].y, minY);
            maxY = max(cows[connection].y, maxY);
            dfs(minX, minY, maxX, maxY, connection);
        }
    }
}

int main()
{
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    visited.resize(n);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cows.resize(n);
    for (auto& cow : cows) {
        cin >> cow.x >> cow.y;
    }

    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int answer = INT_MAX;
    for (int i = 0; i < n; i++) {
        int minX = cows[i].x, maxX = cows[i].x;
        int minY = cows[i].y, maxY = cows[i].y;

        if (visited[i] == 0) {
            visited[i] = 1;

            dfs(minX, minY, maxX, maxY, i);
            int perim = 2 * (maxX + maxY - minX - minY);
            answer = min(answer, perim);
        }
    }
    cout << answer << '\n';
}