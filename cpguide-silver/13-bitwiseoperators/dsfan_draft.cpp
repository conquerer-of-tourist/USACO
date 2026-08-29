/*

    E. Data Structures Fan
    Codeforces Round 985 (Division 3)

    Hengsheng W.
    August 28, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    ll str;
    cin >> str;
    string strver = to_string(str);

    ll total0 = 0;
    ll total1 = 0;

    for (int i = 0; i < n; i++) {
        if (str & (1 << i)) {
            total1 = total1 ^ vals[i];
        }
        else {
            total0 = total0 ^ vals[i];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int version;
        cin >> version;
        if (version == 2) {
            int g;
            cin >> g;
            if (g == 1) cout << total1 << '\n';
            else        cout << total0 << '\n';
        }
        else {
            int l, r;
            cin >> l >> r;
            int replacement = 0;

        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) solve();
}