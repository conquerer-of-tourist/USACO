/*

    Contest:
        - USACO 2019 February
        - Silver Problem 3: The Great Revegetation
    August 17, 2026
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<int, int>

vector<vector<p>> adj;
vector<int> coloring;

bool dfs(int i) {
    for (auto& conn : adj[i]) {
        if (coloring[conn.first] != -1) {
            if (coloring[i] == coloring[conn.first] && conn.second == 1) {
                return false;
            }
            if (coloring[i] != coloring[conn.first] && conn.second == 0) {
                return false;
            }
        }
        if (coloring[conn.first] == -1) {
            if (conn.second == 1) {
                coloring[conn.first] = 3 - coloring[i];
            }
            else {
                coloring[conn.first] = coloring[i];
            }
            bool thingie = dfs(conn.first);
            if (!thingie) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    coloring.resize(n);

    for (int i = 0; i < n; i++) {
        coloring[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 'S') {
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        }
        else {
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 1});
        }
    }
    int ansPower = 0;
    for (int i = 0; i < n; i++) {
        if (coloring[i] == -1) {
            coloring[i] = 1;
            bool worked = dfs(i);
            if (!worked) {
                cout << 0 << '\n';
                return 0;
            }
            ansPower += 1;
        }
    }
    cout << "1";
    for (int i = 0; i < ansPower; i++) {
        cout << "0";
    }
}