#/*

    Information
    =================
    Author: Hengsheng Wang
    Problem Info: CSES Problemset: Restaurant Customers
    Date: July 13th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<ll, ll>
#define ll long long

const ll MOD = (ll) 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }
    sort(events.begin(), events.end());
    int curr = 0;
    int maximum = 0;
    for (auto& event : events) {
        curr += event.second;
        maximum = max(maximum, curr);
    }
    cout << maximum << '\n';
}