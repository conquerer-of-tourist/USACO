/*

    2017 February Bronze
    P3. Why Did the Cow Cross the Road III

    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> cows (n);
    for (auto& cow : cows) {
        cin >> cow.first >> cow.second;
    }
    sort(cows.begin(), cows.end());

    int available = 0;
    for (int i = 0; i < n; i++) {
        if (available <= cows[i].first) {
            available = cows[i].first + cows[i].second;
        }
        else {
            available += cows[i].second;
        }
    }
    cout << available << '\n';
}