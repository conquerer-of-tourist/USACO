/*

    Information
    ======================
    Hengsheng Wang
    Milk Measurement
    USACO 2017 December Contest: Problem 2

    Sunday July 26, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct event {
    int d, ID, delta;
};

int main()
{
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

    sort(events.begin(), events.end());

    //
}