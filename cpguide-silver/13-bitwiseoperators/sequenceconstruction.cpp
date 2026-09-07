/*

    September 6th, 2026
    Sequence Construction - USACO Silver US Open 2025

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll m, k;
    cin >> m >> k;
    vector<ll> vals;
    ll totalSum = 0;
    for (int i = 0; i < 6; i++) {
        if ((k >> i) % 2 == 1) {
            ll curr = (1 << (i + 1)) - 1;
            totalSum += curr;
            vals.push_back(curr);
        }
    }
    if (totalSum > m || ((k - totalSum == 1) && k % 2 == 0)) {
        cout << -1 << '\n';
        return;
    }
    if ((k - totalSum) % 2 == 0) {
        vals.push_back((k - totalSum) / 2);
        vals.push_back((k - totalSum) / 2);
    }
    else if ((k - totalSum) % 2 == 1) {
        vals.erase(vals.begin());
        vals.push_back(2);
    }
    else {
        vals.push_back(1);
        vals.push_back(2);
        totalSum += 3;
        vals.push_back((k - totalSum) / 2);
        vals.push_back((k - totalSum) / 2);
    }

    cout << vals.size() << '\n';
    for (auto& val : vals) cout << val << " ";
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}