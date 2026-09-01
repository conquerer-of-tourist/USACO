// Maximum Distance (USACO Guide)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll main()
{
    ll n;
    vector<pair<ll, ll>> vals (n);
    for (auto& val : vals) {
        cin >> val.first;
    }
    for (auto& val : vals) {
        cin >> val.second;
    }
    long long maxVal = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            maxVal = max(maxVal, (vals[i].first - vals[j].first) * (vals[i].first - vals[j].first) +
                                 (vals[i].second - vals[j].second) * (vals[i].second - vals[j].second));
        }
    }
    cout << maxVal << '\n';
}