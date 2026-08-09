/*

    Social Distancing (Silver)
    August 9th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;

ll maximum = 1e18;

bool check(vector<pair<ll, ll>>& positions, ll dist)
{
    int counter = 1;
    ll lastCow = positions[0].first;
    ll blockIndex = 0;
    
    for (int i = 1; i < n; i++) {
        int nextCow = lastCow + dist;
    }
}

int main()
{
    // freopen("socdist.in", "r", stdin);
    // freopen("socdist.out", "w", stdout);

    cin >> n >> m;
    vector<pair<ll, ll>> positions (m);
    for (auto& grass : positions) {
        cin >> grass.first >> grass.second;
    }
    sort(positions.begin(), positions.end());

    ll l = 0, r = 0;
    ll ans = maximum;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(positions, mid)) {
            ans = min(mid, ans);
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    cout << ans << '\n';
    return 0;
}