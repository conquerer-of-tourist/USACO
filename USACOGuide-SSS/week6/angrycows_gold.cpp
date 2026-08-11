/*

    Hengsheng Wang
    Problem 1 - Angry Cows (USACO 2016 January GOLD)
    August 10, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);
    cin >> n >> k;
    vector<int> targets (n);
    for (auto& targ : targets) {
        cin >> targ;
    }

    sort(targets.begin(), targets.end());

    //
}