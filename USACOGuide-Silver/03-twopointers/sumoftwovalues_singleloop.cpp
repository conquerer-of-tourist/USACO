/*

    Information
    =====================
    Hengsheng Wang
    July 9th, 2026
    CSES Problemset: Sum of Two Values

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
    ll n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    map<ll, ll> vals;
    for (int i = 0; i <= n; i++) {
        ll a; cin >> a;
        if (vals.find(x - a) != vals.end()) {
            cout << vals[x - a] << " " << i + 1 << '\n';
            return 0;
        }
        vals[a] = i + 1;
    }
    cout << "IMPOSSIBLE";
}