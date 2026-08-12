/*

    August 11, 2026
    hangboy
    B. Preparing for Merge Sort (Codeforces ACM-ICPC)

*/

#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    vector<vector<int>> arrays;
    set<int> active;
    map<int, int> activeMap;
    arrays.push_back({vals[0]});
    active.insert(vals[0]);
    activeMap[vals[0]] = 0;
    for (int i = 1; i < n; i++) {
        auto it = active.lower_bound(vals[i]);
        if (it == active.begin()) {
            active.insert(vals[i]);
            arrays.push_back({vals[i]});
            activeMap[vals[i]] = arrays.size() - 1;
        }
        else {
            it--;
            int minVal = *it;
            int corrIndex = activeMap[minVal];
            arrays[corrIndex].push_back(vals[i]);
            activeMap.erase(*it);
            active.erase(*it);
            active.insert(vals[i]);
            activeMap[vals[i]] = corrIndex;
        }
    }
    for (auto& t : arrays) {
        for (auto& k : t) {
            cout << k << ' ';
        }
        cout << '\n';
    }
    return 0;
}