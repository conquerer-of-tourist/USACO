/*

    Permutator (H)
    Teamscode Summer 2023

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;

    vector<ll> a (n), b (n);
    for (auto& A : a) cin >> A;
    for (auto& B : b) cin >> B;

    vector<ll> f(n);

    for (ll i = 0; i < n; i++) {
        f[i] = a[i] * (i + 1) * (n - i);
    }

    sort(f.begin(), f.end());
    sort(b.rbegin(), b.rend());

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += f[i] * b[i];
    }

    cout << ans << '\n';
}