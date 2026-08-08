/*
    
    =========
    August 8 2026
    C. Yet Another Tournament (Educational Codeforces #141)

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a (n);
    for (auto& aa : a) {
        cin >> aa;
    }
    sort(a.begin(), a.end());

    vector<int> prefix (n + 1, 0);
    int maximal = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
        if (prefix[i] <= m) {
            maximal = i;
        }
    }

    if (maximal == 0) {
        cout << n + 1 << '\n';
    }
    else if (maximal == n) {
        cout << 1 << '\n';
    }
    else {
        //
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}