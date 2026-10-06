/*

    Bronze 2022 December Contest
    P1. Cow College

    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;

    vector<ll> cows (n);
    for (auto& cow : cows) {
        cin >> cow;
    }
    sort(cows.begin(), cows.end());

    ll ans = 0, ansTuition = INT_MAX;
    for (ll i = 0; i < n; i++) {
        if ((n - i) * cows[i] > ans) {
            ansTuition = cows[i];
        }
        else if ((n - i) * cows[i] == ans) {
            ansTuition = min(ansTuition, cows[i]);
        }
        ans = max(ans, (n - i) * cows[i]);
    }

    cout << ans << " " << ansTuition << '\n';
}