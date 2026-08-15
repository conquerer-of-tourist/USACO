/*
    Contest: Codeforces Round 870 (Division 2)
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: July 2nd, 2026
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    // b1 + b2 + b3 - (r - l)
    // (b1 + l) + b2 + (b3 - r)
    // this means that we have two prefixes
    
    vector<int> pre1 (n + 1);
    // here, pre1[i] = maximal (bi + i) for all [0 to i]

    pre1[0] = 0;
    for (int i = 0; i < n; i++) {
        pre1[i + 1] = vals[i] + (i + 1);
    }

    // these values will also use one-indexed values
    for (int i = 1; i <= n; i++) {
        pre1[i] = max(pre1[i], pre1[i - 1]);
    }

    vector<int> pre2 (n + 1);
    // we take pre2 to be maximal value of bi - i
    // suffix maximum? is what it is called?

    for (int i = n; i >= 1; i--) {
        pre2[i] = vals[i - 1] - (i);
    }

    for (int i = n - 1; i >= 1; i--) {
        pre2[i] = max(pre2[i], pre2[i + 1]);
    }

    int answer = INT_MIN + 5;
    for (int i = 1; i <= n - 2; i++) {
        int curVal = pre1[i] + vals[i] + pre2[i + 2];
        answer = max(answer, curVal);
    }
    cout << answer << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}