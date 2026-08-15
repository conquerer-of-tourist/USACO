/*

    Information
    =======================
    Author: Hengsheng Wang
    Problem: USACO 2018 January Contest, Silver Problem 1. Lifeguards
    Date: July 6th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<ll, ll>
#define ll long long

int main()
{
    // freopen("lifeguards.in", "r", stdin);
    // freopen("lifeguards.out", "w", stdout);
    ll n;
    cin >> n;
    vector<vector<ll>> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1, i});
        events.push_back({b, -1, i});
    }

    sort(events.begin(), events.end());
    
    set<int> active;
    vector<int> aloneTimes (n, 0);
    int prevTime = events[0][0];
    int totalGood = 0;
    for (int i = 0; i < events.size(); i++) {
        int curLength = events[i][0] - prevTime;
        if (active.size() > 0) {
            totalGood += curLength;
        }
        if (active.size() == 1) {
            aloneTimes[*active.begin()] += curLength;
        }

        if (events[i][1] == -1) {
            active.erase(events[i][2]);
        }
        else if (events[i][1] == 1) {
            active.insert(events[i][2]);
        }
        prevTime = events[i][0];
    }
    int answer = 0;
    for (int i = 0; i < aloneTimes.size(); i++) {
        answer = max(answer, totalGood - aloneTimes[i]);
    }
    cout << answer << '\n';
}

/*

sort all events by time

active = empty set
totalCovered = 0
aloneTime[i] = 0 for every lifeguard

for each event position:
    length = currentTime - previousTime

    if active.size() > 0:
        totalCovered += length

    if active.size() == 1:
        let id = only active lifeguard
        aloneTime[id] += length

    process all events at currentTime

*/