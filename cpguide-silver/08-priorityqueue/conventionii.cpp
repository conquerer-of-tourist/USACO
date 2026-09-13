/*

    Convention II USACO 2018 December Silver
    Problem 2
    September 12, 2026 - Hengsheng

*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    cin >> n;

    using cow = array<int, 3>;
    vector<cow> vals (n);
    for (int i = 0; i < n; i++) {
        cin >> vals[i][1] >> vals[i][2];
        vals[i][0] = i;
    }
    sort(vals.begin(), vals.end(), [](const cow& a, const cow& b) {
        return a[1] < b[1];
    });
    int t = 0, curr = 0, answer = 0;
    
    priority_queue<cow, vector<cow>, greater<cow>> waiting;
    while (curr < n || !waiting.empty()) {
        if (curr < n && vals[curr][1] <= t) {
            waiting.push(vals[curr]);
            curr++;
        }
        else if (waiting.empty()) {
            t = vals[curr][1] + vals[curr][2];
            curr++;
        }
        else {
            cow nxt = waiting.top();
            answer = max(answer, t - nxt[1]);

            t += nxt[2];
            waiting.pop();
        }
    }
    cout << answer << '\n';
}