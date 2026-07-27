/*

    Information
    ====================
    Written by bpcf
    Saturday July 26, 2026
    C. An Impassioned Circulation of Affection (Codeforces Round 418, Division 2)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string k;
    cin >> k;
    
    vector<char> alphabet;
    vector<vector<int>> answers (26, vector<int> (n + 1, 0));

    for (char i = 'a'; i <= 'z'; i++) {
        vector<int> prefix (n + 1, 0);
        for (int j = 0; j < n; j++) {
            prefix[j + 1] = prefix[j] + ((k[j] == i) ? 1 : 0);
        }

        for (int a = 0; a < n; a++) {
            for (int b = a; b < n; b++) {
                int curLength = b - a + 1;
                int curGood = prefix[b + 1] - prefix[a];
                int added = curLength - curGood;

                answers[i - 'a'][added] = max(answers[i - 'a'][added], curLength);
            }
        }
    }

    for (int c = 0; c < 26; c++) {
        for (int m = 1; m <= n; m++) {
            answers[c][m] =
                max(answers[c][m], answers[c][m - 1]);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int m;
        char target;
        cin >> m >> target;

        cout << answers[target - 'a'][m] << '\n';
    }
}