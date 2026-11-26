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

const ll LIM = (ll) 1e18 + (ll) 1;

ll multiply(ll x, ll y) {
    return (x > (LIM / y) ? (LIM) : (x * y));
}

ll ceiling(ll a, ll b) {
    return (a / b) + ((a % b == 0) ? 0 : 1);
}

void update (vector<ll>& tree, ll i, ll v) {
    ll n = tree.size() / 2;

    int ind = i + n;
    tree[ind] = v;

    while (ind > 1) {
        ind = ind / 2;
        tree[ind] = multiply(tree[ind * 2], tree[ind * 2 + 1]);
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a (n);
    for (auto& capacity : a) {
        cin >> capacity;
    }

    vector<ll> f (n);
    vector<ll> tree (2 * n, 1);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            f[0] = a[0] + 1;
        }
        else {
            f[i] = ceiling(a[i], a[i - 1]);
        }
    }

    for (int i = n; i < 2 * n; i++) {
        tree[i] = f[i - n];
    }

    for (int i = n - 1; i > 0; i--) {
        tree[i] = multiply(tree[i * 2 + 1], tree[i * 2]);
    }

    ll q;
    cin >> q;
    while (q--) {
        ll i, v, t;
        cin >> i >> v >> t;
        i--;

        a[i] = v;

        if (i == 0) update(tree, i, v + 1);
        else        update(tree, i, ceiling(a[i], a[i - 1]));

        if (i + 1 < n) {
            update(tree, i + 1, ceiling(a[i + 1], a[i]));
        }

        ll p = tree[1];
        ll first = p + n - 1;

        if (t < first) {
            cout << 0 << '\n';
        }
        else {
            ll numFlips = 1 + (t - first) / p;

            cout << numFlips * a[n - 1] << '\n';
        }
    }
}