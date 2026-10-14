/*

    October 12, 2026
    Hengsheng Wang
    Sliding Window Summation
    (P3. 2026 Silver First Contest)

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

void solve()
{
    int n, k;
    cin >> n >> k;
    ve<int> r (n - k + 1);
    for (auto& R : r) {
        char c; cin >> c; R = (c == '0') ? 0 : 1;
    }
    //
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}