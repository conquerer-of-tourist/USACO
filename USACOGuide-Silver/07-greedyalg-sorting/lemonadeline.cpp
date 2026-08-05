/*

    Information
    =================
    August 3rd, 2026
    USACO 2018 US Open Contest / Silver / P2 / Lemonade line

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n;
    cin >> n;
    vector<ll> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    sort(vals.rbegin(), vals.rend());
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (counter > vals[i]) {
            break;
        }
        else {
            counter++;
        }
    }
    cout << counter << '\n';
    return 0;
}