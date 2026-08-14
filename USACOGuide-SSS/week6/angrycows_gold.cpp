/*

    August 13, 2026
    Angry Cows - USACO Gold (2016 January)
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> list, rist;

bool check(vector<int>& vals, double mid)
{
    //
}

int main()
{
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    sort(vals.begin(), vals.end());

    // compute l[i] and r[i] here

    double l = 0, r = 1e9;
    double answer = r;

    while (l <= r) {
        double mid = l + (r - l) / 2;
        if (check(vals, mid)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << fixed << setprecision(1) << answer << '\n';
    return 0;
}