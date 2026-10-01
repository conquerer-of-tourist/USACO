/*

    2022 U.S. Open - Silver
    Problem 1. Visits
    September 30, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, answer = 0;
    cin >> n;

    vector<ll> a, v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x - 1);

        answer += y;
        v.push_back(y);
    }
    vector<ll> visited (n, 0);
    vector<ll> positions (n);

    for (ll i = 0; i < n; i++) {
        if (visited[i] != 0) continue;

        vector<ll> path;
        ll curr = i;

        while (visited[curr] == 0) {
            visited[curr] = 1;
            positions[curr] = path.size();
            path.push_back(curr);

            curr = a[curr];
        }

        if (visited[curr] == 1) {
            ll cycleMin = LLONG_MAX;

            for (int j = positions[curr]; j < path.size(); j++) {
                cycleMin = min(cycleMin, v[path[j]]);
            }

            answer -= cycleMin;
        }

        for (ll node : path) {
            visited[node] = 2;
        }
    }
    cout << answer << '\n';
}