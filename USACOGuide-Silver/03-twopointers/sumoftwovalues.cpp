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
    
    map<ll, vector<ll>> vals;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        vals[a].push_back(i + 1);
    }
    for (auto& val : vals) {
        ll k = x - val.first;
        auto it = vals.find(k);

        if (it == vals.end()) {
            continue;
        }

        if (k == val.first && val.second.size() >= 2) {
            cout << val.second[0] << " " << val.second[1] << '\n';
            return 0;
        }
        else if (k != val.first) {
            cout << val.second[0] << " " << it->second[0] << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
