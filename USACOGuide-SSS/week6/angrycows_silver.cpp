/*

    Hengsheng Wang
    Problem 1 - Angry Cows (USACO 2016 January Silver)
    August 10, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int n, k;

bool check(vector<int>& targets, int r)
{
    int used = 0;
    int curIndex = 0;
    while (used < k) {
        used++;
        if (curIndex >= n) {
            break;
        }
        int firstHit = targets[curIndex];
        int nextIndex = curIndex + 1;
        while (nextIndex < n && targets[nextIndex] - firstHit <= 2 * r) {
            nextIndex++;
        }
        curIndex = nextIndex;
    }
    if (curIndex >= n) {
        return true;
    }
    return false;
}

int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n >> k;
    vector<int> targets (n);
    for (auto& targ : targets) {
        cin >> targ;
    }

    sort(targets.begin(), targets.end());

    int l = 0, r = 1e9;
    int answer = r;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(targets, mid)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
}