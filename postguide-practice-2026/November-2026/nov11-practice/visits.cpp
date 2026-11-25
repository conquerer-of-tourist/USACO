/*

    Visits
    USACO 2022 U.S. Open - Silver
    Problem 1

    November 11, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pii pair<long long, long long>
#define ve  vector

int main()
{
    ll n, answer = 0;
    cin >> n;

    ve<ll> visit;
    ve<ll> moo;
    for (int i = 0; i < n; i++) {
        int a, v;
        cin >> a >> v;
        
        visit.push_back(a - 1);
        moo.push_back(v);

        answer += v;
    }

    ve<ll> visited (n, 0);
    ve<ll> positions (n);

    for (ll i = 0; i < n; i++) {
        if (visited[i] != 0) {
            continue;
        }

        ve<ll> path;
        ll curr = i;

        while (visited[curr] == 0) {
            visited[curr] = 1;
            positions[curr] = path.size();
            path.push_back(curr);

            curr = visit[curr];
        }

        if (visited[curr] == 1) {
            ll cycleMin = LLONG_MAX;

            for (int j = positions[curr]; j < path.size(); j++) {
                cycleMin = min(cycleMin, moo[path[j]]);
            }
            answer -= cycleMin;
        }

        for (ll node : path) {
            visited[node] = 2;
        }
    }
    cout << answer << '\n';
}