/*

    August 23, 2026
    Hengsheng W.

    USACO 2020 December Contest - Problem 1. Cowntagion (Silver)

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector
#define ll long long

ll n;

ll dfs(ve<ve<ll>>& adj, ve<ll>& visited, ll curr) {
    ll minDays = 0, minCows = 1;
    while (minCows < adj[curr].size() + ((curr == 0) ? 1 : 0)) {
        minDays++;
        minCows *= 2;
    }
    ll ans = minDays;
    for (auto& conn : adj[curr]) {
        if (!visited[conn]) {
            visited[conn] = 1;
            ans += dfs(adj, visited, conn) + 1;
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    ve<ve<ll>> adj (n);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ve<ll> visited (n, 0);
    visited[0] = 1;
    ll total = dfs(adj, visited, 0);
    cout << total << '\n';
}