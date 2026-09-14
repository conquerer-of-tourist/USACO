/*

    Diamond Collector (P1) - 2016 U.S. Open Bronze
    Hengsheng Wang
    Sunday, September 13, 2026

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
    for (auto& v : vals) cin >> v;

    sort(vals.begin(), vals.end());

    int answer = 1;
    for (int start = 0; start < n; start++) {
        int minVal = vals[start];
        int curr = start;
        while (curr < n && vals[curr] - minVal <= k) {
            curr++;
        }
        answer = max(answer, curr - start);
    }
    cout << answer << '\n';
}