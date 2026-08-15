/*

    Information
    ======================
    Hengsheng Wang
    Milk Measurement
    USACO 2017 December Contest: Problem 2

    Sunday July 26, 2026
    Monday July 27, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct event {
    int d, ID, delta;
};

int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n, g;
    cin >> n >> g;

    vector<event> events;
    
    for (int i = 0; i < n; i++) {
        int day, cowID, change;
        cin >> day >> cowID >> change;

        event curEvent;
        curEvent.d = day;
        curEvent.ID = cowID;
        curEvent.delta = change;

        events.push_back(curEvent);
    }

    sort(events.begin(), events.end(), [](const auto& a, const auto& b){
        return a.d < b.d;
    });

    map<int, int> produce;

    for (const auto& e : events) {
        produce[e.ID] = g;
    }
    
    map<int, int> frequency;
    frequency[g] = produce.size() + 1;

    int answer = 0;
    for (const auto& e : events) {
        int oldMax = (*frequency.rbegin()).first;
        int oldCnt = (*frequency.rbegin()).second;

        bool wasTop = (produce[e.ID] == oldMax);

        int oldProduce = produce[e.ID];

        frequency[oldProduce]--;

        if (frequency[oldProduce] == 0) {
            frequency.erase(oldProduce);
        }

        produce[e.ID] += e.delta;

        frequency[produce[e.ID]]++;

        int newMax = (*frequency.rbegin()).first;
        int newCnt = (*frequency.rbegin()).second;

        bool isTop = (produce[e.ID] == newMax);
        if (wasTop != isTop || wasTop && isTop && oldCnt != newCnt) {
            answer++;
        }
    }
    cout << answer << '\n';
}