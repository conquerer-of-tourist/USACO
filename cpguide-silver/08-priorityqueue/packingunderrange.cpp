/*

    ABC - Packing Under Range Regulations
    Hengsheng W.
    September 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

void solve() 
{
    int n;
    cin >> n;
    vector<pii> vals (n);
    for (auto& v : vals) {
        cin >> v.first >> v.second;
    }
    sort(vals.begin(), vals.end());

    priority_queue<int, vector<int>, greater<int>> q;
    int x = 0, curr = 0;
    while (curr < n || !q.empty()) {
        if (q.empty()) {
            x = vals[curr].first;
        }
        while (curr < n && vals[curr].first <= x) {
            q.push(vals[curr].second);
            curr++;
        }
        if (q.top() < x) {
            cout << "NO \n";
            return;
        }
        q.pop();
        x++;
    }
    cout << "YES \n";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}