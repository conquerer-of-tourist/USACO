/*

    Magic Ship (Codeforces Round 60)
    hangboy
    August 11, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll x_1, y_1, x_2, y_2, n;
string s;

bool check(ll mid)
{
    ll fullRotations = mid / n;
    ll netX = 0;
    ll netY = 0;
    for (ll i = 0; i < n; i++) {
        char curr = s[i];
        if (curr == 'U') {
            netY++;
        }
        else if (curr == 'D') {
            netY--;
        }
        else if (curr == 'L') {
            netX--;
        }
        else {
            netX++;
        }
    }
    netX *= fullRotations;
    netY *= fullRotations;
    for (ll i = 0; i < mid % n; i++) {
        char curr = s[i];
        if (curr == 'U') {
            netY++;
        }
        else if (curr == 'D') {
            netY--;
        }
        else if (curr == 'L') {
            netX--;
        }
        else {
            netX++;
        }
    }
    ll needX = (x_2 - x_1) - netX;
    ll needY = (y_2 - y_1) - netY;
    if (abs(needX) + abs(needY) <= mid) {
        return true;
    }
    return false;
}

int main()
{
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    cin >> n;
    cin >> s;

    ll l = 0, r = 1e17;
    ll answer = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
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