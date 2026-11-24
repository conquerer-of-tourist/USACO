/* Nov. 23, 2026 | Hengsheng Wang | BC3 Week 9 Coach Prep */

#include <bits/stdc++.h>
using namespace std;

#define ve vector

ve<ve<int>> adj;
ve<int> visited;

int dfs(int c) {
    visited[c] = 1;

    int reached = 1;

    for (int nextCow = 0; nextCow < adj.size(); nextCow++) {
        if (!visited[nextCow] && adj[c][nextCow]) {
            visited[nextCow] = 1;

            reached += dfs(nextCow);
        }
    }

    return reached;
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;
    ve<int> x (n);
    ve<int> y (n);
    ve<int> p (n);

    for (int c = 0; c < n; c++) {
        cin >> x[c] >> y[c] >> p[c];
    }

    adj = ve<ve<int>> (n, ve<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d_sqrd = (x[i] - x[j]) * (x[i] - x[j]) +
                         (y[i] - y[j]) * (y[i] - y[j]);

            adj[i][j] = (d_sqrd <= p[i] * p[i]);
        }
    }

    int maxGroup = 1;
    for (int c = 0; c < n; c++) {
        visited.assign(n, 0);
        maxGroup = max(maxGroup, dfs(c));
    }
    cout << maxGroup << '\n';
}