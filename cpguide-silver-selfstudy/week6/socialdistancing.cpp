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
    
    for (int i = 0; i < m; i++) {
        if (counter >= n) {
            return true;
        }
        ll nextCow = lastCow + dist;
        if (nextCow < positions[i].first) {
            lastCow = positions[i].first;
            counter++;
            nextCow = lastCow + dist;
            while (nextCow <= positions[i].second) {
                lastCow = nextCow;
                nextCow = lastCow + dist;
                counter++;
            }
        }
        else if (nextCow <= positions[i].second) {
            while (nextCow <= positions[i].second) {
                lastCow = nextCow;
                nextCow = lastCow + dist;
                counter++;
            }
        }
        else {
            continue;
        }
    }
    if (counter >= n) {
        return true;
    }
    return false;
}

int main()
{
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    cin >> n >> m;
    vector<pair<ll, ll>> positions (m);
    for (auto& grass : positions) {
        cin >> grass.first >> grass.second;
    }
    sort(positions.begin(), positions.end());

    ll l = 1, r = maximum;
    ll ans = 0;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(positions, mid)) {
            ans = max(mid, ans);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}