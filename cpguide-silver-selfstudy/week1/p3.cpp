// Problem Name            -> Maximum Subarray Sum
// Link                    -> https://cses.fi/problemset/task/1643/
// Submit                  -> Hengsheng Wang
// Date                    -> June 26 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<ll> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    ll answer = vals[0];
    ll current = vals[0];
    for (ll i = 1; i < n; i++) {
        current = max(vals[i], current + vals[i]);
        answer = max(answer, current);
    }
    cout << answer << '\n';
}