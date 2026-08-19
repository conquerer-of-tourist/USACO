/*

    August 18, 2026
    E. Round Dance - Codeforces Round 874 (Division 3)

*/

#include <bits/stdc++.h>
using namespace std;

void dfs(bool& isPath, int curr, vector<set<int>>& adj, vector<int>& visited) {
    visited[curr] = 1;
    if (adj[curr].size() == 1) {
        isPath = true;
    }

    for (auto& connect : adj[curr]) {
        if (visited[connect] == 0) {
            dfs(isPath, connect, adj, visited);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<set<int>> adj (n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        adj[i].insert(a);
        adj[a].insert(i);
    }

    vector<int> visited (n);

    int components = 0;
    int lines = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            bool isPath = false;
            dfs(isPath, i, adj, visited);
            components++;
            lines += (isPath) ? 1 : 0;
        }
    }
    int minVal;
    if (lines >= 1) {
        minVal = (components - lines) + 1;
    }
    else {
        minVal = components;
    }
    int maxVal = components;
    cout << minVal << " " << maxVal << '\n';
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}