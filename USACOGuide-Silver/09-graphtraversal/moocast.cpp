/*

    USACO 2016 December Contest, Silver | Problem 3. Moocast
    August 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define v vector
#define ll long long

struct cow {
    ll x, y, range;
};

ll dfs(v<v<ll>>& adj, v<ll>& visited, ll i)
{
    ll returnVal = 1;
    visited[i] = 1;
    for (auto& adjVal : adj[i]) {
        if (visited[adjVal] == 0) {
            returnVal += dfs(adj, visited, adjVal);
        }
    }
    return returnVal;
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ll n;
    cin >> n;
    v<v<ll>> adj (n);
    v<cow> cows (n);
    //
    for (auto& c : cows) {
        cin >> c.x >> c.y >> c.range;
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (i != j) {
                ll xloc1 = cows[i].x;
                ll xloc2 = cows[j].x;
                ll yloc1 = cows[i].y;
                ll yloc2 = cows[j].y;
                ll distSQ = (xloc1 - xloc2) * (xloc1 - xloc2) + 
                             (yloc1 - yloc2) * (yloc1 - yloc2);
                ll rangeSQ = cows[i].range * cows[i].range;

                if (rangeSQ >= distSQ) {
                    adj[i].push_back(j);
                }
            }
        }
    }

    ll bestAns = 1;
    for (ll i = 0; i < n; i++) {
        vector<ll> visited (n, 0);
        ll ansHere = dfs(adj, visited, i);
        bestAns = max(bestAns, ansHere);
    }
    cout << bestAns << '\n';
}