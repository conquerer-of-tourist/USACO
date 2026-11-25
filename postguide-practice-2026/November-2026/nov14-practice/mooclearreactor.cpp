/*

    Hengsheng W.

    Mooclear Reactor (P. 2)
    2026 First Contest [Silver]
    Nov. 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ve vector
#define pi pair<long long, long long>

void solve()
{
    int n, m;
    cin >> n >> m;
    ve<int> l (n), r (n);
    for (auto& li : l) cin >> li;
    for (auto& ri : r) cin >> ri;

    ve<ve<pi>> adj (n);
    for (int i = 0; i < m; i++) {
        int x, y, val;
        cin >> x >> y >> val;

        x--; y--;

        adj[x].push_back({y, val});
        adj[y].push_back({x, val});
    }
    
    ve<ll> sign (n, 0), base (n, 0);
    // val = sign * x + base

    int ans = 0;
    bool possible = true;

    for (int s = 0; s < n; s++) {
        if (sign[s] != 0) continue;

        queue<int> q;
        ve<int> component;

        bool fixed = false;
        ll forceX = -1;

        sign[s] = 1;
        base[s] = 0;

        q.push(s);

        while (!q.empty() && possible) {
            int u = q.front();
            q.pop();

            component.push_back(u);

            for (auto [v, w] : adj[u]) {
                int newSign = 0 - sign[u];

                ll newBase = (ll) w - base[u];

                if (sign[v] == 0) {
                    sign[v] = newSign;
                    base[v] = newBase;

                    q.push(v);
                }
                else {
                    if (sign[v] == newSign &&
                        base[v] != newBase) {
                        possible = false;
                        break;
                    }
                    else {
                        ll coeff = sign[v] - newSign;
                        ll rhs = newBase - base[v];

                        if (coeff == 0 && rhs == 0) continue;
                        else if (coeff != 0) {
                            if (rhs % coeff != 0) possible = 0;
                            else {
                                ll X = rhs / coeff;
                                
                                if (fixed && forceX != X) possible = 0;
                                else { fixed = true; forceX = X; }
                            }
                        }
                    }
                }
            }
        }
        if (!possible) break;

        if (!fixed) {
            ve<pair<ll, ll>> events;
            for (auto& u : component) {
                if (sign[u] == 1) {
                    events.push_back({l[u] - base[u], 1});
                    events.push_back({r[u] - base[u] + 1, -1});
                }
                else {
                    events.push_back({base[u] - r[u], 1});
                    events.push_back({base[u] - l[u] + 1, -1});
                }
            }
            sort(events.begin(), events.end());
            int maximal = 0;
            int curr = 0;
            for (int i = 0; i < (int) events.size(); i++) {
                curr += events[i].second;
                maximal = max(curr, maximal);
            }
            ans += maximal;
        }
        else {
            for (int u : component) {
                ll val = sign[u] * forceX + base[u];
                if (l[u] <= val && val <= r[u]) {
                    ans ++;
                }
            }
        }
    }
    cout << (possible ? ans : -1) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}