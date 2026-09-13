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
    // freopen("helpcross.in", "r", stdin);
    // freopen("helpcross.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    priority_queue<int, vector<int>, greater<int>> chickens;
    for (int i = 0; i < c; i++) {
        int a;
        cin >> a;
        chickens.push(a);
    }
    vector<pair<int, int>> vals (n);
    for (auto& v : vals) {
        cin >> v.first >> v.second;
    }
    int answer = 0;
    sort(vals.begin(), vals.end(), [](const pii& a, const pii& b){
        if (a.first == b.first) {
            return b.second < a.second;
        }
        return a.first < b.first;
    });
    for (int i = 0; i < n; i++) {
        int curr = chickens.top();
        if (curr >= vals[i].first && curr <= vals[i].second) {
            chickens.pop();
            answer++;
        }
        else if (curr < vals[i].first) {
            chickens.pop();
        }
    }
    cout << answer << '\n';
}