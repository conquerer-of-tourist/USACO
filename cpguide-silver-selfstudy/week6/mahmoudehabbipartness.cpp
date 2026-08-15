/*

    Another problem I did a year ago
    B. Mahmoud and Ehab and the Biparteness (Codeforces)
    I still think I remember doing this one a year ago in 2025

    Today: August 15, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> adj;

bool dfs(vector<ll>& colors, ll ind) {
    for (auto& connection: adj[ind]) {
        if (colors[connection] == 0) {
            colors[connection] = 3 - colors[ind];
            bool worksHere = dfs(colors, connection);

            if (worksHere == false) {
                return false;
            }
        }
        if (colors[connection] == colors[ind]) {
            return false;
        }
    }
    return true;
}

int main()
{
    ll n;
    cin >> n;
    adj.resize(n);
    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    vector<ll> colors (n, 0);
    colors[0] = 1;
    bool result = dfs(colors, 0);

    ll count1 = 0;
    ll count2 = 0;
    for (auto& c : colors) {
        if (c == 1) {
            count1++;
        }
        else {
            count2++;
        }
    }
    cout << count1 * count2 - (n - 1) << '\n';
    return 0;
}