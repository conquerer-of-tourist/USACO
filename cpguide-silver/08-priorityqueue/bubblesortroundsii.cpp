/*

    Saturday, September 19, 2026
    CSES Problemset - Bubble Sort Rounds II

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> values (n);
    for (auto& kf : values) cin >> kf;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 0; i <= min(n - 1, k); i++) {
        pq.push(values[i]);
    }
    vector<ll> answers;
    for (ll i = 0; i < n; i++) {
        answers.push_back(pq.top());
        pq.pop();
        if (i < n - 1 - k) {
            pq.push(values[i + 1 + k]);
        }
    }
    for (auto& val : answers) {
        cout << val << " ";
    }
    return 0;
}