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

//

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
        //
    }
}