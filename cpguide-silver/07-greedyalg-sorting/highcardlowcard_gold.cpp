/*

    August 4th Practice Session
    Hengsheng Wang
    USACO 2015 December Contest - P2. High Card Wins

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> vals (2 * n, 0);
    vector<int> v1 (n);
    vector<int> v2;
    for (auto& v : v1) {
        cin >> v;

        vals[v - 1] = 1;
    }
    vector<int> v1_1;
    vector<int> v1_2;
    for (int i = 0; i < n / 2; i++) {
        v1_1.push_back(v1[i]);
    }
    for (int i = n / 2; i < n; i++) {
        v1_2.push_back(v1[i]);
    }
    for (int i = 0; i < 2 * n; i++) {
        if (vals[i] == 0) {
            v2.push_back(i + 1);
        }
    }
    sort(v1_1.begin(), v1_1.end());
    sort(v1_2.rbegin(), v1_2.rend());
    sort(v2.begin(), v2.end());
    vector<int> v2_2;
    vector<int> v2_1;
    for (int i = 0; i < n / 2; i++) {
        v2_1.push_back(v2[i]);
    }
    for (int i = n / 2; i < n; i++) {
        v2_2.push_back(v2[i]);
    }

    int j = 0;
    int counter = 0;
    for (int i = 0; i < n / 2; i++) {
        int currOpponent = v1_1[i];
        while (j < n / 2) {
            if (v2_2[j] < currOpponent) {
                j++;
            }
            else {
                j++;
                counter++;
                break;
            }
        }
        if (j == n / 2) {
            break;
        }
    }
    j = 0;
    sort(v2_1.rbegin(), v2_1.rend());
    for (int i = 0; i < n / 2; i++) {
        int currOpponent = v1_2[i];
        while (j < n / 2) {
            if (v2_1[j] > currOpponent) {
                j++;
            }
            else {
                j++;
                counter++;
                break;
            }
        }
        if (j == n / 2) {
            break;
        }
    }
    cout << counter << '\n';
}