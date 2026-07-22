/*

    General Information
    ================================
    Hengsheng Wang
    July 22, 2026

    USACO 2019 February Contest, Silver
    Problem 1. Sleepy Cow Herding

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> cows (n);
    for (auto& cow : cows) {
        cin >> cow;
    }

    sort(cows.begin(), cows.end());

    int maximum = max(cows[n - 2] - cows[0] - (n - 2), 
                      cows[n - 1] - cows[1] - (n - 2));

    int minMoves = INT_MAX;
    int r = 0;

    for (int l = 0; l < n; l++) {
        if (r < l) {
            r = l;
        }
        while (r < n && cows[r] - cows[l] <= n - 1) {
            r++;
        }

        int curHave = r - l;

        if (curHave == n - 1 && cows[r - 1] - cows[l] == n - 2) {
            minMoves = min(minMoves, 2);
        }
        else {
            minMoves = min(minMoves, n - curHave);
        }
    }
    cout << minMoves << '\n' << maximum;
    return 0;
}