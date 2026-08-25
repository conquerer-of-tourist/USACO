/*

    August 24, 2026
    Tree Distances II (CSES Problemset)

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector
#define ll long long

ll dfs(ll& totalDist, ve<ve<ll>>& adj, ve<ll>& visited, 
        ve<ll>& subtrees, ll curr, ll depth) {
    ll ans = 0;
    ll counter = 0;
    for (auto& connect : adj[curr]) {
        if (!visited[connect]) {
            counter++;
            visited[connect] = 1;
            subtrees[connect] = dfs(totalDist, adj, visited, subtrees, connect, depth + 1);
            ans += 1 + subtrees[connect];
        }
    }
    totalDist += depth;
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    ve<ve<ll>> adj (n);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll totalDist = 0;
    ve<ll> visited (n, 0);
    ve<ll> subtrees (n, 0);
    visited[0] = 1;
    dfs(totalDist, adj, visited, subtrees, 0, 0);

    ve<ll> distances (n, 0);
    stack<pair<ll, ll>> calls;
    calls.push({0, totalDist});
    distances[0] = totalDist;

    fill(visited.begin(), visited.end(), 0);
    visited[0] = 1;

    while (!calls.empty()) {
        ll curr = calls.top().first;
        ll lastDist = calls.top().second;
        calls.pop();

        for (auto& connect : adj[curr]) {
            if (!visited[connect]) {
                visited[connect] = 1;
                distances[connect] = lastDist - 2 * (subtrees[connect] + 1) + n;
                calls.push({connect, distances[connect]});
            }
        }
    }
    for (auto& dist : distances) {
        cout << dist << " ";
    }
}