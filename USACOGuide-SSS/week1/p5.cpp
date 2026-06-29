// Problem Name            -> Rectangular Pasture
// Link                    -> hhttps://usaco.org/index.php?page=viewproblem2&cpid=1063
// Submit                  -> Hengsheng Wang
// Date                    -> June 26 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define p pair<int, int>
#define s1 first
#define s2 second

int main()
{
    int n;
    cin >> n;
    vector<p> cows (n);
    for (auto& cow : cows) {
        cin >> cow.s1 >> cow.s2;
    }
    sort(cows.begin(), cows.end());
    for (int i = 0; i < n; i++) {
        cows[i].s1 = i;
    }
    sort(cows.begin(), cows.end(), [](const auto& a, const auto& b) {
        return a.s2 < b.s2;
    });
    for (int i = 0; i < n; i++) {
        cows[i].s2 = i;
    }
    int cowLocations[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cowLocations[i][j] = 0;
        }
    }
    for (auto& cow : cows) {
        cowLocations[cow.s1][cow.s2] = 1;
    }
    int prefix[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            prefix[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            if (cowLocations[i - 1][j - 1] == 1) {
                prefix[i][j]++;
            }
        }
    }
    sort(cows.begin(), cows.end());
    ll answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = min(cows[i].s2, cows[j].s2);
            int x2 = max(cows[i].s2, cows[j].s2);
            int n1 = prefix[j + 1][x1 + 1] - prefix[j + 1][0] - prefix[i][x1 + 1] + prefix[i][0];
            int n2 = prefix[j + 1][n] - prefix[j + 1][x2] - prefix[i][n] + prefix[i][x2];
            answer += n1 * n2;
        }
    }
    cout << answer + 1 + n << '\n';
}