/*

    August 22, 2026
    Mootube - USACO 2018 January Contest (Silver)
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector
#define prii pair<int, int>
#define v1 first
#define v2 second

int n, q;

int dfs(ve<ve<prii>>& adj, ve<int>& visited, int curr, int require) {
    int ans = 1;
    for (auto& connect : adj[curr]) {
        if (connect.v2 >= require && visited[connect.v1] == 0) {
            visited[connect.v1] = 1;
            ans += dfs(adj, visited, connect.v1, require);
        }
    }
    return ans;
}

int main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> n >> q;
    ve<ve<prii>> adj (n);
    for (int i = 0; i < n - 1; i++) {
        int p, qq, r;
        cin >> p >> qq >> r;
        p--; qq--;
        adj[p].push_back({qq, r});
        adj[qq].push_back({p, r});
    }

    while (q--) {
        int ki, vi;
        cin >> ki >> vi;
        vi--;
        vector<int> visited (n, 0);
        visited[vi] = 1;
        int reached = dfs(adj, visited, vi, ki);
        cout << reached - 1 << '\n';
    }
    return 0;
}