/*

    B. The Meeting Place Cannot Be Changed
     > Codeforces Round 403 (Division 2)
     > hangboy
     > August 11, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int n;

bool check(vector<pair<int, int>>& vals, double mid) {
    vector<double> minLefts;
    vector<double> maxRights;
    for (auto& val : vals) {
        double maxRight = val.first + val.second * mid;
        double minLeft = val.first - val.second * mid;

        minLefts.push_back(minLeft);
        maxRights.push_back(maxRight);
    }

    sort(minLefts.begin(), minLefts.end());
    sort(maxRights.begin(), maxRights.end());

    if (minLefts[n - 1] > maxRights[0]) {
        return false;
    }
    return true;
}

int main()
{
    cin >> n;
    vector<pair<int, int>> vals (n);
    for (auto& val : vals) {
        cin >> val.first;
    }
    for (auto& val : vals) {
        cin >> val.second;
    }
    double l = 0.000000001, r = 1e9;
    double answer = r;
    while (l <= r) {
        double mid = l + (r - l) / 2;
        if (check(vals, mid)) {
            answer = mid;
            r = mid - 0.0000001;
        }
        else {
            l = mid + 0.0000001;
        }
    }
    cout << fixed << setprecision(7) << answer << '\n';
    return 0;
}