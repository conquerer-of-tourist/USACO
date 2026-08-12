/*

    August 12, 2026 - Warmups Sessions
    hangboy
    Codeforces - E. Mahmoud and Ehab + Function

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m, q;

int main()
{
    cin >> n >> m >> q;
    vector<ll> a (n), b (m);
    for (auto& val : a) {
        cin >> val;
    }
    for (auto& val : b) {
        cin >> val;
    }
    ll totalA = 0;
    for (ll i = 0; i < n; i++) {
        if (i % 2 == 0) {
            totalA += a[i];
        }
        else {
            totalA -= a[i];
        }
    }
    vector<ll> bVals;
    ll curB = 0;
    for (ll i = 0; i < n; i++) {
        if (i % 2 == 0) {
            curB += b[i];
        }
        else {
            curB -= b[i];
        }
    }
    bVals.push_back(curB);
    for (ll i = 0; i < m - n; i++) {
        curB = -1 * curB + b[i];
        if (n % 2 == 1) {
            curB += b[n + i];
        }
        else {
            curB -= b[n + i];
        }
        bVals.push_back(curB);
    }
    sort(bVals.begin(), bVals.end());

    auto it = lower_bound(bVals.begin(), bVals.end(), totalA);

    ll ans = LLONG_MAX;

    if (it != bVals.end()) {
        ans = min(ans, abs(totalA - *it));
    }
    if (it != bVals.begin()) {
        it--;
        ans = min(ans, abs(totalA - *it));
    }
    
    cout << ans << '\n';

    for (ll i = 0; i < q; i++) {
        ll l, r, x;
        cin >> l >> r >> x;
        if ((r - l + 1) % 2 == 0) {
            totalA = totalA;
        }
        else if (l % 2 == 1) {
            totalA += x;
        }
        else {
            totalA -= x;
        }
        it = lower_bound(bVals.begin(), bVals.end(), totalA);

        ans = LLONG_MAX;

        if (it != bVals.end()) {
            ans = min(ans, abs(totalA - *it));
        }
        if (it != bVals.begin()) {
            it--;
            ans = min(ans, abs(totalA - *it));
        }
        cout << ans << '\n';
    }
    return 0;
}