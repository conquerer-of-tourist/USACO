/*

    Information
    ==================
    bpcf
    July 15th and 16th, 2026
    Codeforces Round 698 (Division 2)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void solve()
{
    ll n;
    cin >> n;
    vector<ll> dList (2 * n);
    for (auto& di : dList) {
        cin >> di;
    }
    

    sort(dList.rbegin(), dList.rend());

    vector<ll> importantD (n);
    for (ll i = 0; i < 2 * n; i += 2) {
        if (dList[i] != dList[i + 1]) {
            cout << "NO" << '\n';
            return;
        }
        if (i < 2 * n - 2) {
            if (dList[i + 1] == dList[i + 2]) {
                cout << "NO" << '\n';
                return;
            }
        }
        importantD[i / 2] = dList[i];
    }

    ll totalSoFar = 0;
    for (ll i = 0; i < n; i++) {
        ll curr = importantD[i] - 2 * totalSoFar;

        if (curr <= 0) {
            cout << "NO" << '\n';
            return;
        }

        ll currDiv = (n - i) * 2;
        if (curr % currDiv != 0) {
            cout << "NO" << '\n';
            return;
        }
        ll currVal = curr / currDiv;

        totalSoFar += currVal;
    }

    cout << "YES" << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}