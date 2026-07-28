/*

    Information
    =====================
    Hengsheng Wang
    Practice Session July 27, 2026
    CSES Problem Set – Room Allocation

*/

#include <bits/stdc++.h>
using namespace std;

struct event {
    int id;
    int time;
    int type;
};

int main()
{
    int n;
    cin >> n;

    vector<event> events;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        event startOne;
        event endOne;
        startOne.id = i;
        startOne.type = 0;
        startOne.time = a;
        endOne.id = i;
        endOne.type = 1;
        endOne.time = b;
        events.push_back(startOne);
        events.push_back(endOne);
    }

    sort(events.begin(), events.end(), [](const auto& a, const auto& b){
        if (a.time == b.time) {
            return a.type < b.type;
        }
        return a.time < b.time;
    });

    vector<int> rooms;
    vector<int> answers (n);
    int counter = 0;

    for (auto& e : events) {
        if (e.type == 0) {
            if (rooms.empty()) {
                counter++;
                rooms.push_back(counter);
            }
            answers[e.id] = *(rooms.rbegin());
            rooms.pop_back();
        }
        else {
            rooms.push_back(answers[e.id]);
        }
    }
    cout << counter << '\n';
    for (auto& ans : answers) {
        cout << ans << ' ';
    }
}