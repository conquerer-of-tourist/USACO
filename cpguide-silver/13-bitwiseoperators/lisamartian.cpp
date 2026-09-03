/*

    September 2nd, 2026
    F. Lisa and the Martians (Codeforces Round 888 Division 3)
    hangboy

*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<ll, ll>
#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pii> vals (n);
    for (ll i = 0; i < n; i++) {
        cin >> vals[i].first;
        vals[i].second = i + 1;
    }
    sort(vals.begin(), vals.end());

    ll bestCurr = LLONG_MAX;
    ll bestI = 0, bestJ = 0, bestX = 0;
    for (ll i = 0; i < n - 1; i++) {
        ll a1 = vals[i].first;
        ll a2 = vals[i + 1].first;

        ll curr = a1 ^ a2;
        if (curr < bestCurr) {
            bestCurr = curr;
            bestI = vals[i].second;
            bestJ = vals[i + 1].second;
            bestX = (((ll) 1 << k) - 1) ^ (a1);
        }
    }
    cout << bestI << " " << bestJ << " " << bestX << '\n';
    return;
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}