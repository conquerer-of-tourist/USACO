/*
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: June 29, 2026
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    vector<char> vals (n);
    vector<int> appearH (n + 1, 0), appearP (n + 1, 0), appearS (n + 1, 0);
    for (auto& val : vals) {
        cin >> val;
    }
    for (int i = 1; i <= n; i++) {
        char curr = vals[i - 1];
        appearH[i] = appearH[i - 1] + ((curr == 'H') ? 1 : 0);
        appearP[i] = appearP[i - 1] + ((curr == 'P') ? 1 : 0);
        appearS[i] = appearS[i - 1] + ((curr == 'S') ? 1 : 0);
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        int a1 = appearH[i], a2 = appearP[i], a3 = appearS[i];
        int b1 = appearH[n] - appearH[i];
        int b2 = appearP[n] - appearP[i];
        int b3 = appearS[n] - appearS[i];
        int k1 = max(a1, max(a2, a3));
        int k2 = max(b1, max(b2, b3));
        answer = max(answer, k1 + k2);
    }
    cout << answer << '\n';
}