/*

    August 27, 2026
    XOR Sigma Problem (ABC 365)
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<ll> vals (n);
    ll total = 0;
    for (auto& val : vals) {
        cin >> val; total += val;
    }

    ll ans = -1 * total;

    vector<ll> prefXOR (n + 1, 0);
    for (ll i = 0; i < n; i++) {
        prefXOR[i + 1] = prefXOR[i] ^ vals[i];
    }

    for (ll b = 0; b < 29; b++) {
        ll cnt0 = 0, cnt1 = 0;
        for (auto& pre : prefXOR) {
            if (pre & (1 << b)) cnt1++;
            else cnt0++;
        }
        ans += cnt0 * cnt1 * (1 << b);
    }
    cout << ans << '\n';
}