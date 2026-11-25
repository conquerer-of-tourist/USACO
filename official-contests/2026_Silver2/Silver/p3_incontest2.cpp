/*
    Hengsheng Wang
    USACO Silver
    February 1st, 2026
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) cin >> val;
    vector<int> doubleVals (2 * n);
    for (int i = 0; i < 2 * n; i++) {
        doubleVals[i] = vals[i % n];
    }
    set<int> uniques;
    for (auto& val : vals) uniques.insert(val);
    int diffs = uniques.size();

    vector<int> best (n, n - 1);
    for (int i = 0; i < n; i++) {
        if (diffs == n) {
            continue;
        }
        int curIndex;
        if (i >= n / 2) {
            curIndex = i;
        }
        else {
            curIndex = n + i;
        }
        set<int> k;
        for (int r = curIndex; r < min(2 * n, curIndex + n); r++) {
            k.insert(doubleVals[r]);
            for (int l = curIndex; l >= max(0, curIndex - n); l--) {
                k.insert(doubleVals[l]);
                if (k.size() == diffs) {
                    best[i] = min(best[i], 2 * (curIndex - l) + (r - curIndex));
                    best[i] = min(best[i], 2 * (r - curIndex) + (curIndex - l));
                    break;
                }
            }
            k.clear();
            for (int ins = curIndex; ins <= r; ins++) {
                k.insert(doubleVals[ins]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << best[i] << ((i == n - 1) ? "" : " ");
    }
}