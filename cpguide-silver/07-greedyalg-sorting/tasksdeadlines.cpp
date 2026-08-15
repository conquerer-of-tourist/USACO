/*

    CSES - Tasks and Deadlines
    Hengsheng Wang
    August 3rd, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> tasks (n);
    for (auto& task : tasks) {
        cin >> task.first >> task.second;
    }

    sort(tasks.begin(), tasks.end());

    ll counter = 0;
    ll total = 0;
    for (auto& task : tasks) {
        counter += task.first;
        ll reward = task.second - counter;
        total += reward;
    }
    cout << total << '\n';
}