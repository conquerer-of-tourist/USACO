// Problem Name            -> Forest Queries
// Link                    -> https://cses.fi/problemset/submit/1652/
// Submit                  -> Hengsheng Wang
// Date                    -> June 26 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<int>> p (n + 1, vector<int> (n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char k;
            cin >> k;
            if (k == '*') {
                p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + 1;
            }
            else {
                p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            }
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << p[c][d] - p[a - 1][d] - p[c][b - 1] + p[a - 1][b - 1] << '\n';
    }
}