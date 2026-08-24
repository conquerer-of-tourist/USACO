/*

    CSES Problemset - Tree Distances
    August 23, 2026
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int n;

void dfs(ve<ve<int>>& adj, ve<int>& visited, int curr, int depth,
        map<int, int>& depths) {
    for (auto& conne : adj[curr]) {
        if (!visited[conne]) {
            visited[conne] = 1;
            depths[conne] = depth + 1;
            dfs(adj, visited, conne, depth + 1, depths);
        }
    }
}

void dfs2(ve<ve<int>>& adj, ve<int>& visited, 
         int curr, int depth, ve<int>& depths) {
    for (auto& conn : adj[curr]) {
        if (!visited[conn]) {
            visited[conn] = 1;
            depths[conn] = depth + 1;
            dfs2(adj, visited, conn, depth + 1, depths);
        }
    }
}

int main()
{
    cin >> n;
    ve<ve<int>> adj (n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<int, int> depths;
    for (int i = 0; i < n; i++) {
        depths[i] = 0;
    }
    ve<int> visited (n, 0);
    visited[0] = 1;
    for (auto& conn : adj[0]) {
        dfs(adj, visited, conn, 0, depths);
    }
    auto it = depths.end();
    int k1 = (*it).first; it--;
    int k2 = (*it).first;

    ve<int> from1 (n, 0); dfs2(adj, visited, k1, 0, from1);
    ve<int> from2 (n, 0); dfs2(adj, visited, k2, 0, from2);

    for (int i = 0; i < n; i++) {
        cout << max(from1[i], from2[i]) << " ";
    }
}