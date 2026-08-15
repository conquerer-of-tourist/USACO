// Problem Name            -> Static Range Sum, Yosupo Judge
// Link                    -> https://judge.yosupo.jp/problem/static_range_sum
// Submit                  -> Hengsheng Wang
// Date                    -> June 26 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
vector<ll> prefix;

void solve() {
    ll a, b;
    cin >> a >> b;
    cout << prefix[b] - prefix[a] << '\n';
}

int main()
{
    ll n, q;
    cin >> n >> q;
    prefix.push_back(0);
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
        prefix.push_back(a + prefix[i]);
    }
    while (q--) {
        solve();
    }
}