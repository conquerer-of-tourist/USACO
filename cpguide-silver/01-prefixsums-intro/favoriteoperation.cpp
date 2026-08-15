/*
    Contest: USACO Silver January 2025
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: July 3rd, 2026
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
        val = val % m;
    }
    int answer = INT_MAX;
    for (int i = 0; i < m; i++) {
        int curAns = 0;
        vector<int> secondV (n);
        for (int k = 0; k < n; k++) {
            secondV[k] = vals[k] + m - i;
            secondV[k] %= m;
            curAns += min(m - secondV[k], secondV[k]);
        }
        answer = min(answer, curAns);
    }
    cout << answer << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}