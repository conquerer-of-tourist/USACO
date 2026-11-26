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

ll ceiling(ll a, ll b) {
    return (a / b) + ((a % b == 0) ? 0 : 1);
}

void solve(vector<ll>& a, ll& llerval)
{
    ll n = (ll) a.size();

    ll i, v, t;
    cin >> i >> v >> t;
    i--;

    llerval -= (n - 1);

    if (i == 0) {
        llerval /= (a[0] + 1);
        llerval *= (v + 1);
        llerval /= ceiling(a[1], a[0]);

        a[0] = v;
        llerval *= ceiling(a[1], a[0]);
    }
    else if (i < n - 1) {
        ll p0 = ceiling(a[i], a[i - 1]);
        ll p1 = ceiling(a[i + 1], a[i]);

        llerval /= (p0 * p1);

        a[i] = v;
        ll p2 = ceiling(a[i], a[i - 1]);
        ll p3 = ceiling(a[i + 1], a[i]);

        llerval *= (p2 * p3);
    }
    else {
        ll p0 = ceiling(a[i], a[i - 1]);
        llerval /= p0;
        a[i] = v;
        ll p2 = ceiling(a[i], a[i - 1]);
        llerval *= p2;
    }

    llerval += (n - 1);

    ll numRepeat = (t - llerval) / (llerval - (n - 1));
    ll numGet    = 0;

    if (t >= llerval) {
        numGet = 1 + numRepeat;
    }

    cout << numGet * a[n - 1] << '\n';
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a (n);
    for (auto& capacity : a) {
        cin >> capacity;
    }

    ll llerval = a[0] + 1;
    for (ll i = 1; i < n; i++) {
        llerval *= ceiling(a[i], a[i - 1]);
    }

    llerval += (n - 1);

    ll q;
    cin >> q;
    while (q--) {
        solve(a, llerval);
    }
}