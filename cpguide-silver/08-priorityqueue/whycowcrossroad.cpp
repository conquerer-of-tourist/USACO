/*

    September 13, 2026
    1. Why Did the Cow Cross the Road? (2017 February, Silver)
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main()
{
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    vector<int> chickens (c);
    vector<pii> vals (n);
    for (auto& chicken : chickens) cin >> chicken;
    for (auto& v : vals) cin >> v.first >> v.second;

    sort(chickens.begin(), chickens.end());
    sort(vals.begin(), vals.end());

    int answer = 0, curr = 0;
    priority_queue<int> available;
    for (auto& ch : chickens) {
        while (curr < vals.size() && vals[curr].first <= ch) {
            available.push(-1 * vals[curr].second);
            curr++;
        }
        while (!available.empty() && (-1 * available.top()) < ch) {
            available.pop();
        }
        if (!available.empty()) {
            answer++;
            available.pop();
        }
    }
    cout << answer << '\n';
}