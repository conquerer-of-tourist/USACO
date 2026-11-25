/*

    November 5th, 2026
    2026 AMC 10A

    USACO 2023 February Contest - Silver
    Problem 2. Cow-Libi

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll g, n;
    cin >> g >> n;

    vector<ll> times (g);
    vector<vector<ll>> grazings (g, vector<ll> (3));
    for (ll i = 0; i < g; i++) {
        cin >> grazings[i][1] >> grazings[i][2] >> grazings[i][0];
    }

    sort(grazings.begin(), grazings.end(), [](
        const vector<ll>& a, vector<ll>&b ){
        return a[0] < b[0];
    });

    for (ll i = 0; i < g; i++) {
        times[i] = grazings[i][0];
    }

    ll answer = 0;
    for (ll i = 0; i < n; i++) {
        ll x, y, t;
        cin >> x >> y >> t;

        ll ind = upper_bound(times.begin(), times.end(), t) - times.begin();

        bool isGood = 0;
        for (ll j : {ind - 1, ind}) {
            if (j < 0 || j >= g) continue;
            ll dx = grazings[j][1] - x;
            ll dy = grazings[j][2] - y;
            ll dt = grazings[j][0] - t;

            if (dx * dx + dy * dy > dt * dt) {
                isGood = true;
            }
        }

        answer += isGood;
    }
    cout << answer << '\n';
}