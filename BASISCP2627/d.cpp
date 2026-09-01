// Diamond Collector

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
    int answer = 1;
    int l = 0, r = 0;
    while (l < n) {
        while (r < n - 1 && vals[r + 1] - vals[l] <= k) {
            r++;
            answer = max(answer, r - l + 1);
        }
        l++;
    }
    cout << answer << '\n';
}