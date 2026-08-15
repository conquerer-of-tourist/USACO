/*

    Codeforces (C. Maximum Median) Round 577
    hangboy
    Practice Session - August 12, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, k;

bool check(vector<ll>& vals, ll mid)
{
    ll totalChange = 0;
    for (ll i = (n - 1) / 2; i < n; i++) {
        totalChange += max(0LL, mid - vals[i]);
        if (totalChange > k) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> k;
    vector<ll> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    sort(vals.begin(), vals.end());
    ll l = 0, r = 1e17;
    ll answer = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(vals, mid)) {
            answer = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << answer << '\n';
    return 0;
}