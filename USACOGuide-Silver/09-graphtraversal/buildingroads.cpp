/*

    CSES Problemset - Building Roads
    August 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define v vector

v<int> beginnings;
v<int> visited;

void dfs(v<v<int>>& adj, int begin)
{
    visited[begin] = 1;
    for (auto& conn : adj[begin]) {
        if (visited[conn] == 0) {
            dfs(adj, conn);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    v<v<int>> adj (n);

    for (int i = 0; i < n; i++) {
        visited.push_back(0);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }
        dfs(adj, i);
        beginnings.push_back(i);
    }
    cout << beginnings.size() - 1<< '\n';
    for (int i = 0; i < (int) beginnings.size() - 1; i++) {
        cout << beginnings[i] + 1 << " " << beginnings[i + 1] + 1 << '\n';
    }
    return 0;
}