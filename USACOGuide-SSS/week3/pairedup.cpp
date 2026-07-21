/*

    Information
    ===================
    Person:  Hengsheng Wang
    Problem: USACO Silver 2017 U.S. Open (Problem 1)
    Date: July 18th, 2026 (start)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    ll n;
    cin >> n;

    vector<pair<ll, ll>> vals (n);

    for (auto& val : vals) {
        cin >> val.first >> val.second;
    }

    sort(vals.begin(), vals.end(), [](const auto& a,
                                      const auto& b) {
        return a.second < b.second;
    });

    ll mllime = 0;
    ll l = 0;
    ll r = n - 1;

    while (true) {
        if (l > r) {
            break;
        }
        if (l == r) {
            mllime = max(mllime, 2 * vals[l].second);
            break;
        }
        else {
            ll k1 = vals[l].first;
            ll k2 = vals[r].first;
            if (k1 == k2) {
                mllime = max(mllime, vals[l].second + 
                                       vals[r].second);
                l++;
                r--;
            }
            else if (k1 > k2) {
                mllime = max(mllime, vals[l].second + vals[r].second);
                vals[l].first -= vals[r].first;
                r--;
            }
            else {
                mllime = max(mllime, vals[l].second + vals[r].second);
                vals[r].first -= vals[l].first;
                l++;
            }
        }
    }
    cout << mllime << '\n';
    return 0;
}