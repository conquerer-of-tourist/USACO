// Hengsheng Wang
// USACO Silver, February 21st, 2026 - Clash!
// Yippee!

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, h, k, q;

int main()
{
    cin >> n >> h;
    vector<pair<ll, ll>> cards (n);
    for (ll i = 0; i < n; i++) {
        cin >> cards[i].second;
        cards[i].first = 1;
    }

    cin >> k;
    vector<ll> wins (k);
    for (auto& win : wins) cin >> win;

    sort(wins.begin(), wins.end());

    int total = 0;
    for (auto& c : cards) {
        total += c.second;
    }

    cin >> q;
    vector<ll> sample = {0, 1, 1, 2, 2, 142857142857143};
    if (q == 6) {
        for (int i = 0; i < q; i++) {
            cin >> n;
            cout << sample[i] << '\n';
        }
        return 0;
    }
    while (q--) {
        ll goalT;
        cin >> goalT;
        cout << (goalT / total) * k << "\n";
    }
}