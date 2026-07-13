/*

    Information
    =====================
    Hengsheng Wang
    July 9th, 13th, 2026
    CSES Problemset: Sum of Three Values

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
    ll n, x;
    cin >> n >> x;
    
    vector<ll> vals (n);

    for (auto& val : vals) {
        cin >> val;
    }

    // sort(vals.begin(), vals.end());

    if (n <= 2) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    for (int i = 0; i < n - 2; i++) {
        int needed = x - vals[i];
        for (int j = 1; j < n - 1; j++) {
            ll k = needed - vals[j].first;
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
    }
}