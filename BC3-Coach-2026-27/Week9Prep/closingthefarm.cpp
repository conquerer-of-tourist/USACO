/* Nov. 23, 2026 | Hengsheng Wang | BC3 Week 9 Coach Prep */

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int n, m;

ve<ve<int>> adj (3005);
ve<int> visited (3005);
ve<int> closed  (3005);

int farmsVisited = 0;

void dfs(int node) {
    if (visited[node] || closed[node]) {
        return;
    }

    farmsVisited++;
    visited[node] = 1;

    for (int nextNode : adj[node]) {
        if (visited[nextNode] == 0) {
            dfs(nextNode);
        }
    }
}

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ve<int> closingOrder (n);
    for (auto& closedFarm : closingOrder) {
        cin >> closedFarm;
    }

    dfs(1);

    if (farmsVisited == n) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

    for (int i = 0; i < n - 1; i++) {
        farmsVisited = 0;
        fill(visited.begin(), visited.end(), 0);

        dfs(closingOrder[n - 1]);

        if (farmsVisited == n - i - 1) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}