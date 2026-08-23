/*

    August 22, 2026
    Hengsheng W.

    Codeforces Round 428 (Division 2)
    Problem C. Journey

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

double dfs(ve<ve<int>>& adj, ve<int>& visited, int curr) {
    double ans = 0;
    int cnt = 0;
    for (auto& connect : adj[curr]) {
        if (visited[connect] == 0) {
            cnt++;
            visited[connect] = 1;
            ans += (double) dfs(adj, visited, connect);
        }
    }
    if (cnt == 0) {
        return 1;
    }
    return 1 + ans / (double) cnt;
}

int main()
{
    int n;
    cin >> n;
    ve<ve<int>> adj (n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ve<int> visited (n, 0);
    visited[0] = 1;
    double ans = dfs(adj, visited, 0);
    cout << fixed << setprecision(7) << ans - 1.0 << '\n';
}