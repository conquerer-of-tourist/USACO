/*

    Codeforces Round 565 (Division 3)
    E. Cover it!

    Hengsheng W.
    August 17, 2026

*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& coloring, vector<vector<int>>& adj, int curr) {
    for (auto& connection: adj[curr]) {
        int currColor = coloring[curr];
        if (coloring[connection] == -1) {
            if (currColor == 0) {
                coloring[connection] = 1;
                dfs(coloring, adj, connection);
            }
            else {
                coloring[connection] = 0;
                dfs(coloring, adj, connection);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj (n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> coloring (n, -1);

    for (int i = 0; i < n; i++) {
        if (coloring[i] == -1) {
            coloring[i] = 0;
            dfs(coloring, adj, i);
        }
    }
    
    vector<int> v0, v1;
    int counter = 0;
    for (auto& val : coloring) {
        if (val == 0) v0.push_back(counter + 1);
        else v1.push_back(counter + 1);

        counter++;
    }
    if (v0.size() > v1.size()) {
        swap(v0, v1);
    }
    cout << v0.size() << '\n';
    for (auto& thingie : v0) {
        cout << thingie << ' ';
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}