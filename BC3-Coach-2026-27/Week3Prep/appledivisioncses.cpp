/*

    September 16, 2026
    Apple Divisions (CSES Problemset)
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
vector<ll> apples;

ll recurse(ll pile1, ll pile2, ll curr) {
    if (curr == n) {
        return abs(pile1 - pile2);
    }
    ll a1 = recurse(pile1 + apples[curr], pile2, curr + 1);
    ll a2 = recurse(pile1, pile2 + apples[curr], curr + 1);
    return min(a1, a2);
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        apples.push_back(a);
    }

    ll ans = recurse(0, 0, 0);
    cout << ans << '\n';
}