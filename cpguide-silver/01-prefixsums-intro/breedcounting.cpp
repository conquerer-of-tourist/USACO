/*
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: June 29, 2026
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> nums (n);
    for (auto& num : nums) {
        cin >> num;
    }
    vector<int> h (n + 1, 0);
    vector<int> g (n + 1, 0);
    vector<int> j (n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = h[i] + ((nums[i] == 1) ? 1 : 0);
        g[i + 1] = g[i] + ((nums[i] == 2) ? 1 : 0);
        j[i + 1] = j[i] + ((nums[i] == 3) ? 1 : 0);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << h[b] - h[a - 1] << " " << g[b] - g[a - 1] << " " <<
                j[b] - j[a - 1] << '\n';
    }
    return 0;
}