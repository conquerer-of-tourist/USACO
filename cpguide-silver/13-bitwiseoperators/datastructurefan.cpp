/*

    E. Data Structures Fan
    Codeforces Round 985 (Division 3)

    Hengsheng W.
    August 28, 30, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    string s;
    cin >> s;

    ll total0 = 0;
    ll total1 = 0;

    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            total0 = total0 ^ vals[i];
        }
        else {
            total1 = total1 ^ vals[i];
        }
    }

    vector<ll> pref (n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ vals[i - 1];
    }
    
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll version;
        cin >> version;
        if (version == 1) {
            ll l, r;
            cin >> l >> r;
            ll currRange = pref[r] ^ pref[l - 1];
            total0 ^= currRange;
            total1 ^= currRange;
        }
        else if (version == 2) {
            ll k;
            cin >> k;
            if (k == 0) cout << total0 << " ";
            if (k == 1) cout << total1 << " ";
        }
    }
    cout << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while (t--) solve();
}