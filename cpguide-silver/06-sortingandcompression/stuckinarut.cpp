/*

    Information
    ---------------------------
    Hengsheng Wang
    USACO 2020 December Contest: Silver
    July 14th, 2026 and July 15th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9 + 1;

struct cowInfo {
    char dir;
    int x;
    int y;
};

struct event {
    int time;
    int blockerTime;
    int blocker;
    int blocked;
};

vector<int> overallBlame (100000, -1);

int dfs (int& cow, vector<vector<int>>& affected) {
    if (overallBlame[cow] != -1) {
        return overallBlame[cow];
    }

    int total = 0;
    for (auto& directly : affected[cow]) {
        total += 1 + dfs(directly, affected);
    }

    overallBlame[cow] = total;
    return total;
}


int main()
{
    int n;
    cin >> n;
    vector<cowInfo> cows (n);
    for (auto& cow : cows) {
        cin >> cow.dir >> cow.x >> cow.y;
    }
    vector<event> events;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            char c1Dir = cows[i].dir;
            char c2Dir = cows[j].dir;

            if (c1Dir == c2Dir) {
                continue;
            }

            if (c1Dir == 'E') {
                // Cow 1 goes (a + k, b)
                // Cow 2 goes (a, b + k)

                int meetX = cows[j].x;
                int meetY = cows[i].y;

                int c1X = cows[i].x;
                int c2Y = cows[j].y;

                if (c1X > meetX || c2Y > meetY) {
                    continue;
                }

                event curEvent;
                curEvent.time = max(meetX - c1X, meetY - c2Y);
                curEvent.blockerTime = min(meetX - c1X, meetY - c2Y);

                if (meetX - c1X > meetY - c2Y) {
                    curEvent.blocked = i;
                    curEvent.blocker = j;
                }
                else if (meetX - c1X == meetY - c2Y) {
                    continue;
                }
                else {
                    curEvent.blocked = j;
                    curEvent.blocker = i;
                }

                events.push_back(curEvent);
            }

            else {

                int meetX = cows[i].x;
                int meetY = cows[j].y;

                int c1X = cows[j].x;
                int c2Y = cows[i].y;

                if (c1X > meetX || c2Y > meetY) {
                    continue;
                }

                event curEvent;
                curEvent.time = max(meetX - c1X, meetY - c2Y);
                curEvent.blockerTime = min(meetX - c1X, meetY - c2Y);

                if (meetX - c1X > meetY - c2Y) {
                    curEvent.blocked = j;
                    curEvent.blocker = i;
                }
                else if (meetX - c1X == meetY - c2Y) {
                    continue;
                }
                else {
                    curEvent.blocked = i;
                    curEvent.blocker = j;
                }

                events.push_back(curEvent);
            }
        }
    }
    
    sort(events.begin(), events.end(), [](const event& a, const event& b) {
        return a.time < b.time;
    });

    vector<int> stoppedTime (n, INF);
    vector<vector<int>> affected (n);

    for (auto& curEvent : events) {
        int blocker = curEvent.blocker;
        int blocked = curEvent.blocked;

        if (stoppedTime[blocked] == INF && stoppedTime[blocker] > curEvent.blockerTime) {
            stoppedTime[blocked] = curEvent.time;
            affected[blocker].push_back(blocked);
        }
    }

    for (int i = 0; i < n; i++) {
        dfs(i, affected);
    }

    for (int i = 0; i < n; i++) {
        cout << overallBlame[i] << '\n';
    }
    return 0;
}