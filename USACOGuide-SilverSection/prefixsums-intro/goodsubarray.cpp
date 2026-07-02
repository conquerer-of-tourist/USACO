/*
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: June 30, 2026
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> occurences;

    occurences[0] = 1;

    int pref = 0;
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        pref += c - '0';
        int value = pref - i;

        ans += occurences[value];
        occurences[value]++;
    }
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}