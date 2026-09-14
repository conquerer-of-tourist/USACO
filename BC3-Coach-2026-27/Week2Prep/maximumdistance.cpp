/*

    Maximum Distance (A)
    Codeforces - USACO Guide Submissions
    September 13, 2026
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> x (n), y (n);
    for (auto& X : x) cin >> X;
    for (auto& Y : y) cin >> Y;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll dist = (x[i] - x[j]) * (x[i] - x[j]) +
                      (y[i] - y[j]) * (y[i] - y[j]);
            
            ans = max(ans, dist);
        }
    }
    cout << ans << '\n';
}