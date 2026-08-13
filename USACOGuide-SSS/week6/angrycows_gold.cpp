/*

    Hengsheng Wang
    Problem 1 - Angry Cows (USACO 2016 January GOLD)
    August 10, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector

int n;

bool check(v<int>& targets, v<int>& lList, v<int>&rList, double mid) {
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        int distBetween = targets[i + 1] - targets[i];
        if (distBetween > 2 * mid) {
            return false;
        }
        int require1 = lList[i];
        int require2 = rList[i + 1];
        if (mid - 1 >= require1 && mid - 1 >= require2) {
            flag = true;
        }
    }
    return flag;
}

int main()
{
    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);
    cin >> n;
    vector<int> targets (n);
    for (auto& targ : targets) {
        cin >> targ;
    }

    sort(targets.begin(), targets.end());

    vector<int> lList (n), rList (n);

    lList.
    
    int j = 0;

    for (int i = 1; i < n; i++) {
        int c1 = max(lList[j + 1] + 1, targets[i] - targets[j + 1]);
        int c2 = max(lList[j] + 1, targets[i] - targets[j]);

        while (j < i - 1 && c1 <= c2) {
            j++;
            c1 = max(lList[j + 1] + 1, targets[i] - targets[j + 1]);
            c2 = max(lList[j] + 1, targets[i] - targets[j]);
        }
        lList[i] = c2;
    }

    j = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        int c1 = max(rList[j - 1] + 1, targets[j - 1] - targets[i]);
        int c2 = max(rList[j] + 1, targets[j] - targets[i]);
        while (j - 1 > i && c1 <= c2) {
            j--;
            c1 = max(rList[j - 1] + 1, targets[j - 1] - targets[i]);
            c2 = max(rList[j] + 1, targets[j] - targets[i]);
        }

        rList[i] = max(rList[j] + 1, targets[j] - targets[i]);
    }

    double l = 0, r = 1e9 + 7;
    double ans = r;

    while (l <= r) {
        double mid = l + (r - l) / 2;
        if (check(targets, lList, rList, mid)) {
            ans = mid;
            r = mid - 0.05;
        }
        else {
            l = mid + 0.05;
        }
    }
    cout << fixed << setprecision(1) << ans << '\n';
}