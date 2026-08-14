/*

    August 13, 2026 - Practice

    Hengsheng Wang
    USACO 2023 February Silver - Bakery

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct cow {
    ll ai, bi, ci;
};

bool check(vector<cow>& cows, ll w, ll timeX, ll timeY)
{
    ll totalChange = timeX + timeY - w;
    ll finalXL = 1;
    ll finalXR = timeX;

    ll finalYL = 1;
    ll finalYR = timeY;

    for (auto& c : cows) {
        if (c.ai == c.bi) {
            ll RHS = c.ci / c.bi;
            if (totalChange > RHS) {
                return false;
            }
        }
        else if (c.ai > c.bi) {
            ll newRightBound = (c.ci - c.bi * totalChange) / (c.ai - c.bi);
            if (newRightBound < finalXL) {
                return false;
            }
            ll newLeftBoundY = totalChange - newRightBound;
            if (newLeftBoundY > finalYR) {
                return false;
            }
            finalYL = max(finalYL, newLeftBoundY);
            finalXR = min(finalXR, newRightBound);
        }
        else {
            ll newLeftBound = (c.bi * totalChange - c.ci) / (c.bi - c.ai);
            ll modRHS = (c.bi * totalChange - c.ci) % (c.bi - c.ai);
            if (modRHS != 0) {
                newLeftBound++;
            }
            if (newLeftBound > finalXR) {
                return false;
            }
            ll newRightBoundY = totalChange - newLeftBound;
            if (newRightBoundY < finalYL) {
                return false;
            }
            finalYR = min(finalYR, newRightBoundY);
            finalXL = max(finalXL, newLeftBound);
        }
    }
    return true;
}

void solve()
{
    ll n, timeX, timeY;
    cin >> n >> timeX >> timeY;
    vector<cow> cows (n);
    for (auto& thing : cows) {
        cin >> thing.ai >> thing.bi >> thing.ci;
    }
    ll l = 0, r = timeX + timeY - 2;
    ll answer = r;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(cows, mid, timeX, timeY)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}