/*
    
    =========
    August 8 2026
    C. Yet Another Tournament (Educational Codeforces #141)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a (n);
    for (auto& aa : a) {
        cin >> aa;
    }
    auto og = a;
    sort(a.begin(), a.end());

    vector<ll> prefix (n + 1, 0);
    ll maximal = 0;
    for (ll i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
        if (prefix[i] <= m) {
            maximal = i;
        }
    }

    if (maximal == 0) {
        cout << n + 1 << '\n';
    }
    else if (maximal == n) {
        cout << 1 << '\n';
    }
    else {
        if (prefix[maximal - 1] + og[maximal] <= m) {
            cout << n - maximal << '\n';
        }
        else {
            cout << n - maximal + 1 << '\n';
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}