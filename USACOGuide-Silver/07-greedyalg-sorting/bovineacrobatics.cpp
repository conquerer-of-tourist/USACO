/*

    August 6th, 8th, 2026
    Bovine Acrobatics (USACO 2023 December Contest, Silver)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<ll, ll>> cows (n);
    for (auto& group : cows) {
        cin >> group.first >> group.second;
    }
    sort(cows.begin(), cows.end());

    ll towers = 0, available = 0, answer = 0;

    queue<pair<ll, ll>> q;
    for (auto& [w, count] : cows) {
        while (!q.empty() && q.front().first <= w - k) {
            available += q.front().second;
            q.pop();
        }

        ll extend = min(count, available);

        available -= extend;
        count -= extend;
        answer += extend;

        ll start = min(count, m - towers);
        towers += start;
        answer += start;

        q.push({w, extend + start});
    }
    cout << answer << '\n';
    return 0;
}