/*

    USACO 2016 December Contest (Gold) Problem 1 - Moocast
    Hengsheng Wang
    August 17, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<ll, ll>
#define f1 first
#define f2 second
#define ll long long

ll n;

void dfs(vector<ll>& visited, vector<p>& cows, ll start, ll mid) {
    for (ll i = 0; i < n; i++) {
        if (i != start && visited[i] == 0) {
            ll dist = (cows[start].f1 - cows[i].f1) * (cows[start].f1 - cows[i].f1) +
                       (cows[start].f2 - cows[i].f2) * (cows[start].f2 - cows[i].f2);
            if (dist <= mid) {
                visited[i] = 1;
                dfs(visited, cows, i, mid);
            }
        }
    }
}

bool check(vector<p>& cows, ll mid) {
    vector<ll> visited (n, 0);
    visited[0] = 1;
    dfs(visited, cows, 0, mid);
    ll counter = 0;
    for (auto& vis : visited) {
        if (vis == 1) {
            counter++;
        }
    }
    return (counter == n);
}

int main()
{
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    vector<p> cows (n);
    for (auto& cow : cows) {
        cin >> cow.f1 >> cow.f2;
    }
    ll l = 0, r = 1e15;
    ll answer = r;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(cows, mid)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}