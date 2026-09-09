/*

    Counting Haybales - Silver 2016 December
    Tuesday, September 8, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    sort(vals.begin(), vals.end());
    while (q--) {
        int a, b;
        cin >> a >> b;
        auto i1 = lower_bound(vals.begin(), vals.end(), a);
        auto i2 = upper_bound(vals.begin(), vals.end(), b);
        i2--;
        int diff = (i2 - vals.begin()) - (i1 - vals.begin()) + 1;
        cout << diff << '\n';
    }
}