/*

    August 31, 2026
    1. Searching for Soulmates (USACO 2022 January Silver)
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll p, q;
    cin >> p >> q;

    vector<ll> fromP, fromQ;
    fromP.push_back(p);

    while (fromP.back() > 1) {
        ll curr = fromP.back();

        if (fromP.back() % 2 == 1) curr++;
        else curr /= 2;

        fromP.push_back(curr);
    }

    fromQ.push_back(q);
    while (fromQ.back() > 1) {
        ll curr = fromQ.back();

        if (curr % 2 == 1) curr--;
        else curr /= 2;

        fromQ.push_back(curr);
    }

    ll answer = 1e17;

    for (ll i = 0; i < fromP.size(); i++) {
        for (ll j = 0; j < fromQ.size(); j++) {
            ll val = fromP[i];
            ll val2 = fromQ[j];

            if (val <= val2) {
                ll curr = i + (val2 - val) + j;
                answer = min(curr, answer);
            }
        }
    }
    cout << answer << '\n';
}

int main()
{
    ll n;
    cin >> n;
    while (n--) {
        solve();
    }
}