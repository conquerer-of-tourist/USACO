/*

    Information
    ====================
    Hengsheng Wang
    July 23rd, 2026
    2016 USACO US Open Contest: Silver P2: Diamond Collectors

    *I finished this code for the USACO Guide 2-Pointer Module

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    sort(vals.begin(), vals.end());

    vector<int> prefixMax (n + 1, 0);

    int l = 0;

    for (int r = 0; r < n; r++) {
        while (vals[r] - vals[l] > k) {
            l++;
        }
        prefixMax[r + 1] = max(prefixMax[r] , r - l + 1);
    }

    vector<int> suffixMax (n + 1, 0);

    int r = n - 1;

    for (l = n - 1; l >= 0; l--) {
        while (vals[r] - vals[l] > k) {
            r--;
        }
        suffixMax[l] = max(suffixMax[l + 1], r - l + 1);
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(answer, prefixMax[i] + suffixMax[i]);
    }
    cout << answer << '\n';
}