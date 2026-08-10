/*

    Cow Dance Show (USACO 2017 January)
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

int n, tmax;

bool check(vector<int>& cows, int t) {
    priority_queue<int, vector<int>, greater<int>> stage;
    for (int i = 0; i < t; i++) {
        stage.push(cows[i]);
    }
    int maxTime = 0;
    for (int i = n - 1; i >= t; i--) {
        int curr = stage.top();
        stage.pop();
        stage.push(cows[i] + curr);
    }
    while (!stage.empty()) {
        maxTime = max(maxTime, stage.top());
        stage.pop();
    }
    return (maxTime <= tmax);
}

int main()
{
    cin >> n >> tmax;
    vector<int> cows (n);
    for (auto& cow : cows) {
        cin >> cow;
    }
    sort(cows.begin(), cows.end());

    int l = 1, r = n;
    int answer = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(cows, mid)) {
            answer = min(answer, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}

/*

for example, if we have 4, 4, 6, 6:


[4, 6] [4, 6] satisfies 10
but 
[4, 4] [6, 6] only satisfies 12

so if we wanted it to satisfy 10...

*/