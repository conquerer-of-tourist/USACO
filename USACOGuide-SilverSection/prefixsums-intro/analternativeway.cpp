/*
    Contests: Codeforces Round 1107 (Division 3)
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: July 1st, 2026
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a (n);
    vector<ll> b (n);

    for (auto& val : a) {
        cin >> val;
    }
    for (auto& val : b) {
        cin >> val;
    }

    vector<ll> pre1 (n);
    vector<ll> pre2 (n);
    pre1[0] = a[0];
    pre2[0] = b[0];
    for (ll i = 1; i < n; i++) {
        pre1[i] = pre1[i - 1] + a[i];
        pre2[i] = pre2[i - 1] + b[i];
    }

    for (ll i = 0; i < n; i++) {
        if (pre1[i] > pre2[i]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}