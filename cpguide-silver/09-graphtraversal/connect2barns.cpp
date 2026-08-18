/*

    August 18, 2026
    Hengsheng Wang
    USACO 2021 December Silver - Problem 2. Connecting Two Barns

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(ll curr, ll label, vector<vector<ll>>& adj, vector<ll>& components) {
    components[curr] = label;

    for (ll nxt : adj[curr]) {
        if (components[nxt] == -1) {
            dfs(nxt, label, adj, components);
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj (n);
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> components (n, -1);
    ll curLabel = 0;
    for (ll i = 0; i < n; i++) {
        if (components[i] == -1) {
            dfs(i, curLabel, adj, components);
            curLabel++;
        }
    }
    vector<vector<ll>> sections (curLabel);
    for (ll i = 0; i < n; i++) {
        sections[components[i]].push_back(i);
    }

    if (components[n - 1] == 0) {
        cout << 0 << '\n';
        return;
    }

    ll comp1 = 0;
    ll comp2 = components[n - 1];

    ll bestAns = LLONG_MAX;
    for (ll i = 0; i < curLabel; i++) {
        ll closestTo1 = LLONG_MAX;
        ll closestTo2 = LLONG_MAX;
        for (auto& val : sections[i]) {
            auto close1 = lower_bound(sections[comp1].begin(), sections[comp1].end(), val);
            auto close2 = lower_bound(sections[comp2].begin(), sections[comp2].end(), val);
            
            if (close1 != sections[comp1].end()) closestTo1 = min(closestTo1, (ll) abs(*close1 - val));
            if (close2 != sections[comp2].end()) closestTo2 = min(closestTo2, (ll) abs(*close2 - val));
            if (close1 != sections[comp1].begin()) close1--;
            if (close2 != sections[comp2].begin()) close2--;
            closestTo1 = min(closestTo1, (ll) abs(*close1 - val));
            closestTo2 = min(closestTo2, (ll) abs(*close2 - val));
        }
        bestAns = min(bestAns, closestTo1 * closestTo1 + closestTo2 * closestTo2);
    }
    
    cout << bestAns << '\n';
    return;
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}