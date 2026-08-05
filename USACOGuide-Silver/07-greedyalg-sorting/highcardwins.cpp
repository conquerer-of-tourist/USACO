/*

    August 4th Practice Session
    Hengsheng Wang
    USACO 2015 December Contest - P2. High Card Wins

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> all (2 * n, 0);
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
        all[val - 1] = 1;
    }
    sort(vals.begin(), vals.end());
    vector<int> ourVals;
    for (int i = 0; i < 2 * n; i++) {
        if (all[i] == 0) {
            ourVals.push_back(i + 1);
        }
    }
    int j = 0;
    sort(ourVals.begin(), ourVals.end());
    int counter = 0;
    for (int i = 0; i < n; i++) {
        int currOpponent = vals[i];
        while (j < n) {
            if (ourVals[j] < currOpponent) {
                j++;
            }
            else {
                j++;
                counter++;
                break;
            }
        }
        if (j == n) {
            break;
        }
    }
    cout << counter << '\n';
    return 0;
}