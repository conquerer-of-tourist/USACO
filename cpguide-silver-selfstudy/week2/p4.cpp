/*

    Information
    =============================
    Author: Hengsheng Wang
    Problem: USACO 2019 January Contest, Silver 3) Mountain View
    Date: July 6th and 7th, 2026

*/
#include <bits/stdc++.h>
using namespace std;

#define p pair<ll, ll>
#define ll long long

int main()
{
    // freopen("mountains.in", "r", stdin);
    // freopen("mountains.out", "w", stdout);
    ll n;
    cin >> n;

    vector<p> endpoints (n);
    for (auto& endpoint : endpoints) {
        ll a, b;
        cin >> a >> b;

        ll left = a - b, right = a + b;
        endpoint = {left, right};
    }

    sort(endpoints.begin(), endpoints.end(), [](p a, p b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    ll maxRight = -100, visible = 0;
    for (int i = 0; i < n; i++) {
        ll curRight = endpoints[i].second;
        if (curRight > maxRight) {
            visible++;
            maxRight = curRight;
        }
    }

    cout << visible << '\n';
}