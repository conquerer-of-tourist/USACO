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

vector<vector<int>> visitedFlights;
vector<vector<flight>> flights;
vector<int> layovers;
vector<int> visited;

void dfs(int curr, int startTime, bool isFirst) {
    for (auto& adjFlight : flights[curr]) {
        int targ = adjFlight.target;
        int t1 = adjFlight.time1;
        int t2 = adjFlight.time2;
        int neededTime = startTime + layovers[curr];
        if (neededTime > t1 && isFirst == false) {
            continue;
        }
        if (visited[targ] <= t2) {
            continue;
        }
        visited[targ] = t2;
        dfs(targ, t2, false);
    }
}

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

    for (int i = 0; i < n; i++) {
        visited.push_back(1e9 + 7);
    }

    visited[0] = 0;
    dfs(0, 0, true);
    for (auto& val : visited) {
        if (val == 1e9 + 7) {
            cout << -1 << '\n';
        }
        else {
            cout << val << '\n';
        }
    }
    return 0;
}