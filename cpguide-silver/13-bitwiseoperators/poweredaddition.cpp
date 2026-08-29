/*

    Codeforces Round 633 (Division 1)
    A. Powered Addition
    hangboy
    August 28, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) cin >> val;

    int increment = 0;
    int lastOne = vals[0];

    for (int i = 1; i < n; i++) {
        if (lastOne > vals[i])  increment = max(increment, lastOne - vals[i]);
        else                    lastOne = vals[i];
    }

    cout << max(0, (int) log2(increment) + 1) << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) solve();
}