/*

    August 6, 2026
    Rest Stops | USACO Silver 2018 February

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    ll l, n, vF, vB;
    cin >> l >> n >> vF >> vB;
    vector<pair<ll, ll>> stops (n);
    for (auto& stop : stops) {
        cin >> stop.first >> stop.second;
    }

    vector<pair<ll, ll>> POIs;
    ll curBest = 0;
    for (ll i = n - 1; i >= 0; i--) {
        ll curLoc = stops[i].first;
        ll curGood = stops[i].second;

        if (curGood > curBest) {
            POIs.push_back({curLoc, curGood});
            curBest = curGood;
        }
    }

    sort(POIs.begin(), POIs.end());

    ll answer = 0;
    ll bessieLoc = 0;
    for (ll i = 0; i < POIs.size(); i++) {
        ll curLoc = POIs[i].first;
        ll curGood = POIs[i].second;
        ll deltaLoc = curLoc - bessieLoc;
        ll timeRest = deltaLoc * (vF - vB);
        answer += timeRest * curGood;

        bessieLoc = curLoc;
    }

    cout << answer << '\n';
    return 0;
}