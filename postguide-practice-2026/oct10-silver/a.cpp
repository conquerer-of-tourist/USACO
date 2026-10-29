/*

    USACO Silver - Hoof, Paper, Scissors
    P2 2017 January

    Hengsheng Wang
    October 10, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> vals (n);
    for (int i = 0; i < n; i++) {
        char k;
        cin >> k;
        if (k == 'H') vals[i] = 0;
        if (k == 'P') vals[i] = 1;
        if (k == 'S') vals[i] = 2;
    }

    vector<vector<int>> prefix (3, vector<int> (n + 1, 0));
    vector<vector<int>> suffix (3, vector<int> (n + 1, 0));

    for (int i = 0; i < n; i++) {
        prefix[0][i + 1] = prefix[0][i];
        prefix[1][i + 1] = prefix[1][i];
        prefix[2][i + 1] = prefix[2][i];

        prefix[vals[i]][i + 1]++;
    }

    suffix[vals[n - 1]][n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix[0][i] = suffix[0][i + 1];
        suffix[1][i] = suffix[1][i + 1];
        suffix[2][i] = suffix[2][i + 1];

        suffix[vals[i]][i] += 1;
    }

    int answer = 1;
    for (int i = 0; i < n - 1; i++) {
        answer = max(answer, max({prefix[0][i + 1], prefix[1][i + 1], prefix[2][i + 1]})                
                           + max({suffix[0][i + 1], suffix[1][i + 1], suffix[2][i + 1]}));
    }
    cout << answer << '\n';
}