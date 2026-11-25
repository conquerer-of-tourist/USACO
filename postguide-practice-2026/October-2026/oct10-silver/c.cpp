/*

    USACO Silver - Convention
    P1 2018 December

    Hengsheng Wang
    October 10, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

bool check(ve<int>& arrivals, int mid, int m, int c) {
    int curr = 0;
    int used = 0;
    for (int i = 0; i < arrivals.size(); i++) {
        if (i == curr) used++;
        int sizee = i - curr + 1;
        if (i < arrivals.size() - 1 && arrivals[i + 1] - arrivals[curr] > mid) {
            curr = i + 1;
            continue;
        }
        if (sizee == c) {
            curr = i + 1;
            continue;
        }
    }
    return (used <= m);
}

int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    ve<int> arrivals (n);
    for (auto& a : arrivals) cin >> a;

    sort(arrivals.begin(), arrivals.end());

    int l = 0, r = (arrivals[n - 1] - arrivals[0]);
    int answer = INT_MAX;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(arrivals, mid, m, c)) {
            answer = min(answer, mid);
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
}