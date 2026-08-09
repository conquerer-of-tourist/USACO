/*

    August 8th, 2026
    Closest Cow Wins (USACO 2021 December)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pos first
#define taste second

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k, m, n;
    cin >> k >> m >> n;
    vector<pair<ll, ll>> grasses (k);
    for (auto& grass : grasses) {
        cin >> grass.pos >> grass.taste;
    }

    sort(grasses.begin(), grasses.end());

    vector<ll> nCows (m);
    for (auto& cow : nCows) {
        cin >> cow;
    }
    sort(nCows.begin(), nCows.end());

    vector<ll> gains;

    ll grassIndex = 0;
    ll lTotal = 0;

    while (grassIndex < k && grasses[grassIndex].pos < nCows[0]) {
        lTotal += grasses[grassIndex].taste;
        grassIndex++;
    }
    gains.push_back(lTotal);

    for (ll i = 0; i < m - 1; i++) {
        ll L = nCows[i];
        ll R = nCows[i + 1];

        ll start = grassIndex;
        ll curTotal = 0;

        while (grassIndex < k && grasses[grassIndex].pos < R) {
            curTotal += grasses[grassIndex].taste;
            grassIndex++;
        }

        ll intervalEnd = grassIndex;

        ll right = start;
        ll window = 0, best = 0;

        for (ll left = start; left < intervalEnd; left++) {
            while (right < intervalEnd && 
                   2 * (grasses[right].pos - grasses[left].pos) < R - L) {
                window += grasses[right].taste;
                right++;
            }

            best = max(best, window);
            window -= grasses[left].taste;
        }

        gains.push_back(best);
        gains.push_back(curTotal - best);
    }

    ll rTotal = 0;
    while (grassIndex < k) {
        rTotal += grasses[grassIndex].taste;
        grassIndex++;
    }

    gains.push_back(rTotal);

    ll answer = 0;
    sort(gains.rbegin(), gains.rend());
    for (int i = 0; i < min((ll) gains.size(), n); i++) {
        answer += gains[i];
    }

    cout << answer << '\n';
    return 0;
}