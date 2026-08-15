/*

    August 15, 2026
    Hengsheng
    Flight Route Check (CSES Problemset)

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adj2;

void dfs(vector<int>& visited, int i)
{
    for (auto& connection: adj[i]) {
        if (visited[connection] == 1) {
            continue;
        }
        visited[connection] = 1;
        dfs(visited, connection);
    }
}

void dfs2(vector<int>& visited, int i)
{
    for (auto& connection: adj2[i]) {
        if (visited[connection] == 1) {
            continue;
        }
        visited[connection] = 1;
        dfs2(visited, connection);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    adj2.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj2[b - 1].push_back(a - 1);
    }

    vector<int> visited (n, 0);
    visited[0] = 1;
    dfs(visited, 0);

    vector<int> visited2 (n, 0);
    visited2[0] = 1;
    dfs2(visited2, 0);

    int ind0v1 = -1;
    int ind0v2 = -1;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            ind0v1 = i;
        }
    }
    if (ind0v1 != -1) {
        cout << "NO" << '\n';
        cout << 1 << " " << ind0v1 + 1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (visited2[i] == 0) {
            ind0v2 = i;
        }
    }
    if (ind0v2 != -1) {
        cout << "NO" << '\n';
        cout << ind0v2 + 1 << " " << 1 << '\n';
        return 0;
    }
    cout << "YES" << '\n';
}