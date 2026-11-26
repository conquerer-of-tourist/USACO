/*

    November 25, 2026 | Hengsheng Wang
    ====================================
    > USACO 2026 Third Contest
    > Problem 2 - Milk Buckets

*/

// Can the 2026-2027 Schedule just come out already?

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll>& a, ll& llerval)
{
    ll n = (ll) a.size();

    ll i, v, t;
    cin >> i >> v >> t;
    i--;

    if (i == 0) {
        llerval /= a[0];
        llerval *= v;

        a[0] = v;
    }
    else if (i < n - 1) {
        ll p0 = a[i] / a[i - 1] + ((a[i] % a[i - 1]) == 0) ? 0 : 1;
        ll p1 = a[i + 1] / a[i] + ((a[i + 1] % a[i] == 0)) ? 0 : 1;

        llerval /= (p0 * p1);

        a[i] = v;

        ll p2 = a[i] / a[i - 1] + ((a[i] % a[i - 1]) == 0) ? 0 : 1;
        ll p3 = a[i + 1] / a[i] + ((a[i + 1] % a[i]) == 0) ? 0 : 1;

        llerval *= (p2 * p3);
    }
    else {
        ll p0 = a[i] / a[i - 1] + ((a[i] % a[i - 1]) == 0) ? 0 : 1;
        llerval /= p0;
        a[i] = v;
        ll p2 = a[i] / a[i - 1] + ((a[i] % a[i - 1]) == 0) ? 0 : 1;
        llerval *= p2;
    }

    ll numRepeat = (t - llerval) / (llerval - (a[1] / a[0] + (a[1] % a[0] == 0) ? 0 : 1));
    cout << (max((ll) 0, 1 + max((ll) 0, numRepeat))) * a[n - 1] << '\n';
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a (n);
    for (auto& capacity : a) {
        cin >> capacity;
    }

    ll llerval = a[0];
    for (ll i = 1; i < n; i++) {
        ll k = a[i] / a[i - 1];
        if ((a[i] % a[i - 1]) != 0) {
            k++;
        }
        llerval *= k;
    }

    llerval += (n);

    ll q;
    cin >> q;
    while (q--) {
        solve(a, llerval);
    }
}