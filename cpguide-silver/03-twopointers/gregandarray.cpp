/*

    Information
    ====================================================
    DATE            July 4th, 5th, 2026
    AUTHOR          Hengsheng Wang
    CONTEST         Codeforces Round 179 (Division 1)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    vector<vector<ll>> operations (m, vector<ll>(3));
    for (ll i = 0; i < m; i++) {
        cin >> operations[i][0] >> operations[i][1]
            >> operations[i][2];
        operations[i][0]--;
        operations[i][1]--;
    }

    vector<ll> diffOperations (m + 1, 0);
    vector<ll> diff (n + 1, 0);
    for (ll i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        diffOperations[a]++;
        diffOperations[b + 1]--;
    }

    for (int i = 1; i < m; i++) {
        diffOperations[i] += diffOperations[i - 1];
    }

    for (int i = 0; i < m; i++) {
        ll diffThing = diffOperations[i] * operations[i][2];
        diff[operations[i][0]] += diffThing;
        diff[operations[i][1] + 1] -= diffThing;
    }

    for (ll i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }

    for (ll i = 0; i < n; i++) {
        vals[i] += diff[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cout << vals[i] << " ";
    }
    cout << vals[n - 1];
}