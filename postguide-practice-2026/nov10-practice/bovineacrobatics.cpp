/*

    Novemeber 10th, 2026

    Bovine Acrobatics
    (USACO 2023 December Silver Problem 1)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ve vector
#define pii pair<int, int>

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> cows;
    for (int i = 0; i < n; i++) {
        int w, a;
        cin >> w >> a;
        cows.push_back(make_pair(w, a));
    }

    sort(cows.rbegin(), cows.rend());

    queue<pii> towers;

    ll ans = 0;

    towers.push({INT_MAX, m});
    for (int i = 0; i < n; i++) {
        int rem = cows[i].second;
        int currCow = cows[i].first;

        while (rem > 0 && !towers.empty() &&
                (ll) currCow + k <= towers.front().first) {
            int base = towers.front().first;
            int num = towers.front().second;

            if (currCow - k > base) {
                continue;
            }
            if (rem > num) {
                rem -= num;
                towers.pop();
            }
            else {
                towers.front().second -= rem;
                rem = 0;
            }
        }

        int place = cows[i].second - rem;
        if (place > 0) {
            towers.push({currCow, place});
            ans += place;
        }
    }
    cout << ans << '\n';
}
