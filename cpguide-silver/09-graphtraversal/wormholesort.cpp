/*

    USACO 2020 January Contest - Silver
    August 17, 2026
    Problem 3. Wormhole Sort

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define p pair<ll, ll>
#define v1 first
#define v2 second

ll n, m;
vector<ll> cows;
vector<ll> component;
vector<vector<p>> adj;

void dfs(ll curr, ll label, ll mid) {
    component[curr] = label;
    for (auto& connect : adj[curr]) {
        if (connect.v2 >= mid && component[connect.v1] == -1) {
            dfs(connect.v1, label, mid);
        }
    }
}

bool check(ll mid) {
    fill(component.begin(), component.end(), -1);
    ll label = 1;
    for (ll i = 0; i < n; i++) {
        if (component[i] == -1) {
            dfs(i, label, mid);
            label++;
        }
    }

    for (ll i = 0; i < n; i++) {
        if (component[i] != component[cows[i]]) {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    cows.resize(n);
    component.resize(n);
    for (ll i = 0; i < n; i++) {
        component[i] = -1;
    }
    for (auto& c : cows) {
        cin >> c; c--;
    }
    bool flag = true;
    for (ll i = 0; i < n; i++) {
        if (cows[i] != i) {
            flag = false;
        }
    }
    if (flag) {
        cout << -1 << '\n';
        return 0;
    }
    adj.resize(n);
    for (ll i = 0; i < m; i++) {
        ll a, b, width;
        cin >> a >> b >> width;
        a--; b--;
        adj[a].push_back({b, width});
        adj[b].push_back({a, width});
    }
    ll l = 0, r = 1e13;
    ll answer = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            answer = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << answer << '\n';
    return 0;
}