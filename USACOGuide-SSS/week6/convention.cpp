/*

    Hengsheng Wang
    August 10th, 2026
    USACO 2018 December - Convention (P1)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, c;
vector<int> arrivals;

bool check(int midTime)
{
    int cowNum = 0;
    for (int i = 0; i < m; i++) {
        if (cowNum >= n) {
            return true;
        }
        int curFirst = arrivals[cowNum];
        int curCows = 1;
        cowNum++;
        while (cowNum < n && arrivals[cowNum] - curFirst <= midTime) {
            if (curCows == c) {
                break;
            }
            cowNum++;
            curCows++;
        }
    }
    if (cowNum < n) {
        return false;
    }
    return true;
}

int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arrivals.push_back(a);
    }
    sort(arrivals.begin(), arrivals.end());
    ll l = 0, r = arrivals[n - 1];
    int answer = r;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
            answer = min(answer, mid);
        }
        else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}