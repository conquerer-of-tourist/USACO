#/*

    Information
    =================
    Author: Hengsheng Wang
    Problem Info: Educational Codeforces Round 46
    Date: July 13th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<ll, ll>
#define ll long long

const ll MOD = (ll) 1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> events;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b + 1, -1});
    }
    map<ll, ll> freq;
    sort(events.begin(), events.end());
    ll curr = 1;
    for (ll i = 1; i <= n; i++) {
        freq[i] = 0;
    }
    for (ll i = 1; i < events.size(); i++) {
        freq[curr] += events[i].first - events[i - 1].first;
        curr += events[i].second;
    }
    vector<pair<ll, ll>> answers;
    for (auto& thing : freq) {
        answers.push_back({thing.first, thing.second});
    }
    sort(answers.begin(), answers.end());
    for (auto& thing : answers) {
        if (thing.first != 0) {
            cout << thing.second << " ";
        }
    }
}