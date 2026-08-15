/*

    CSES Problemset: Factory Machines
    August 10, 2026
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll m, p;

bool check(vector<ll>& machines, ll maxTime)
{
    ll products = 0;
    for (auto& machine : machines) {
        ll k = maxTime / machine;
        products += k;
        if (products >= p) {
            return true;
        }
    }
    if (products >= p) {
        return true;
    }
    return false;
}

int main()
{
    cin >> m >> p;
    vector<ll> machines (m);
    for (auto& machine : machines) {
        cin >> machine;
    }

    ll l = 1, r = 1e18;
    ll answer = 1e18;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(machines, mid)) {
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