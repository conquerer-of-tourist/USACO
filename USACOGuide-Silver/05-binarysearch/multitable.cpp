/*

    August 11, 2026
    Hengsheng Wang
    CSES Problemset - Multiplication Table

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

bool check(ll mid) {
    ll totalCount = 0;
    for (ll i = 1; i <= n; i++) {
        ll currCount = min(n, mid / i);
        totalCount += currCount;
    }
    if (totalCount >= (n * n + 1) / 2) {
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    ll l = 1, r = n * n;
    ll answer = r;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            answer = min(answer, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}