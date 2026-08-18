/*

    August 18, 2026
    USACO 2023 February Silver - Moo Route II
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

struct flight {
    int target, time1, time2;
};

vector<vector<flight>> flights;
vector<int> layovers;

int main()
{
    int n, m;
    cin >> n >> m;
    flights.resize(n);
    layovers.resize(n);
    for (int i = 0; i < m; i++) {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        a1--;
        a3--;
        flight curr;
        curr.time1 = a2;
        curr.time2 = a4;
        curr.target = a3;
        flights[a1].push_back(curr);
    }

    for (auto& layover: layovers) {
        cin >> layover;
    }
    layovers[0] = 0;

    for (int i = 0; i < n; i++) {
        sort(flights[i].begin(), flights[i].end(), [](const flight& a, const flight& b) {
                 return a.time1 > b.time1;
        });
    }

    vector<int> best(n, 1e9 + 7);
    best[0] = 0;

    vector<int> ptr(n, 0);
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        int needTime = best[curr] + layovers[curr];

        while (ptr[curr] < flights[curr].size() &&
               flights[curr][ptr[curr]].time1 >= needTime) {
            flight f = flights[curr][ptr[curr]];
            ptr[curr]++;

            if (f.time2 < best[f.target]) {
                best[f.target] = f.time2;
                q.push(f.target);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (best[i] == 1e9 + 7) {
            cout << -1 << '\n';
        }
        else {
            cout << best[i] << '\n';
        }
    }

    return 0;
}