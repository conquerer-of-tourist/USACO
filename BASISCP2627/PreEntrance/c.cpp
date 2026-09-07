// Speeeeding Ticket

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> limits (100, 0);
    int beginLen = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = beginLen; j < beginLen + a; j++) {
            limits[j] = b;
        }
        beginLen += a;
    }
    beginLen = 0;
    vector<int> speeds (100, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = beginLen; j < beginLen + a; j++) {
            speeds[j] = b;
        }
        beginLen += a;
    }
    int maximal = 0;
    for (int i = 0; i < 100; i++) {
        maximal = max(maximal, speeds[i] - limits[i]);
    }
    cout << maximal << '\n';
}