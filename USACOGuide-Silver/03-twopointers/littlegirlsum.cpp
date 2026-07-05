/*

    Information
    ====================================================
    DATE            July 5th, 2026
    AUTHOR          Hengsheng Wang
    CONTEST         Codeforces Round 169 (Division 2)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, q;
    cin >> n >> q;
    
    vector<ll> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    vector<ll> diffs (n + 1, 0);
    for (ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        diffs[a]++;
        diffs[b + 1]--;
    }

    for (ll i = 1; i < n; i++) {
        diffs[i] += diffs[i - 1];
    }

    sort(diffs.begin(), diffs.end());
    sort(vals.begin(), vals.end());
    ll answer = 0;
    for (ll i = 0; i < n; i++) {
        answer += diffs[i + 1] * vals[i];
    }
    cout << answer << '\n';
}