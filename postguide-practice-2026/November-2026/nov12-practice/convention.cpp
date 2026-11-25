/*

    November 12, 2026
    Problem 1. Convention

    2018 December - Silver Contest

*/

#include <bits/stdc++.h>
using namespace std;


int n, m, c;

bool check(int maxWait, vector<int>& arrivals) {
    int used = 1;
    int currBegin = arrivals[0];
    int currSize  = 1;
    for (int i = 1; i < n; i++) {
        if (currSize == c) {
            currSize = 1;
            currBegin = arrivals[i];
            used++;
            continue;
        }
        if (arrivals[i] - currBegin > maxWait) {
            used++;
            currSize = 1;
            currBegin = arrivals[i];
            continue;
        }
        currSize += 1;
    }
    return used <= m;
}

int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n >> m >> c;

    vector<int> arrivals (n);
    for (auto& a : arrivals) cin >> a;

    sort(arrivals.begin(), arrivals.end());

    int l = 0, r = 1e9;
    int answer = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (check(mid, arrivals)) {
            r = mid - 1;
            answer = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << answer << '\n';
}