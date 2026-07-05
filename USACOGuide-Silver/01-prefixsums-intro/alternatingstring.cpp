/*
    Contests: Codeforces Round 970 (Division 3)
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: July 2nd, 2026
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector

void solveEven(int n, string k)
{
    map<char, int> freqEven;
    map<char, int> freqOdd;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            freqEven[k[i]]++;
        }
        else {
            freqOdd[k[i]]++;
        }
    }
    int f1 = 0;
    int f2 = 0;
    for (auto& thing : freqEven) {
        f1 = max(f1, thing.second);
    }
    for (auto& thing : freqOdd) {
        f2 = max(f2, thing.second);
    }
    f1 = (n / 2) - f1;
    f2 = (n / 2) - f2;
    cout << f1 + f2 << '\n';
}

void solveOdd(int n, string k)
{
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    v<v<int>> prefEven (26, v<int> (n + 2, 0));
    v<v<int>> prefOdd  (26, v<int> (n + 2, 0));

    prefEven[k[0] - 'a'][1] = 1;
    prefOdd[k[1] - 'a'][2] = 1;

    for (int i = 1; i <= n; i++) {
        for (int a = 0; a < 26; a++) {
            prefEven[a][i] = prefEven[a][i - 1];
            prefOdd[a][i] = prefOdd[a][i - 1];
        }

        int curVal = k[i - 1] - 'a';

        if ((i - 1) % 2 == 0) {
            prefEven[curVal][i]++;
        }
        else {
            prefOdd[curVal][i]++;
        }
    }

    int answer = INT_MAX;
    for (int i = 0; i < n; i++) {
        int f1 = 0;
        int f2 = 0;
        for (int ch = 0; ch < 26; ch++) {
            f1 = max(f1, prefOdd[ch][i] + prefEven[ch][n] - prefEven[ch][i + 1]);
            f2 = max(f2, prefEven[ch][i] + prefOdd[ch][n] - prefOdd[ch][i + 1]);
        }
        int changed = (n - 1) - f1 - f2;
        answer = min(answer, changed);
    }

    cout << answer + 1 << '\n';
}

void solve()
{
    int n;
    cin >> n;
    string k;
    cin >> k;
    
    if (n % 2 == 0) {
        solveEven(n, k);
    }
    else {
        solveOdd(n, k);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

// /*
//     Contests: Codeforces Round 970 (Division 3)
//     Author: Hengsheng Wang
//     User: conquerer-of-tourist
//     Date: July 2nd, 2026
// */


// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define v vector

// void solveEven(int n, string k)
// {
//     map<char, int> freqEven;
//     map<char, int> freqOdd;
//     for (int i = 0; i < n; i++) {
//         if (i % 2 == 0) {
//             freqEven[k[i]]++;
//         }
//         else {
//             freqOdd[k[i]]++;
//         }
//     }
//     int f1 = 0;
//     int f2 = 0;
//     for (auto& thing : freqEven) {
//         f1 = max(f1, thing.second);
//     }
//     for (auto& thing : freqOdd) {
//         f2 = max(f2, thing.second);
//     }
//     f1 = (n / 2) - f1;
//     f2 = (n / 2) - f2;
//     cout << f1 + f2 << '\n';
// }

// void solveOdd(int n, string k)
// {
//     v<v<int>> leftEven  (26, v<int> (n + 1, 0));
//     v<v<int>> leftOdd   (26, v<int> (n + 1, 0));
//     v<v<int>> rightEven (26, v<int> (n + 1, 0));
//     v<v<int>> rightOdd  (26, v<int> (n + 1, 0));

//     for (int i = 1; i <= n; i++) {
//         char curr = k[i - 1];
//         int currInt = curr - 'a';
//         if (i % 2 == 0) {
//             leftEven[currInt][i] = leftEven[currInt][i - 2] + 1;
//             leftEven[currInt][i + 1] = leftEven[currInt][i];
//         }
//         else {
//             leftOdd[currInt][i] = leftOdd[currInt][i - 2] + 1;
//             leftOdd[currInt][i + 1] = leftOdd[currInt][i];
//         }
//     }

//     for (int i = n; i >= 1; i--) {
//         char curr = k[i - 1];
//         int currInt = curr - 'a';
//         if (i % 2 == 0) {
//             rightEven[currInt][i] = rightEven[currInt][i + 2] + 1;
//             rightEven[currInt][i - 1] = rightEven[currInt][i];
//         }
//         else {
//             rightOdd[currInt][i] = rightOdd[currInt][i + 2] + 1;
//             rightOdd[currInt][i - 1] = rightOdd[currInt][i];
//         }
//     }

//     int answer = INT_MAX - 3;
//     for (int i = 0; i < n; i++) {
//         int f1 = 0;
//         int f2 = 0;
//         for (int ch = 0; ch < 26; ch++) {
//             f1 = max(f1, leftOdd[ch][i] + rightEven[ch][i + 1]);
//             f2 = max(f2, leftEven[ch][i] + rightOdd[ch][i + 1]);
//         }
//         int changed = (n - 1) - f1 - f2;
//         answer = min(answer, changed);
//     }
//     cout << answer + 1 << '\n';
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     string k;
//     cin >> k;
    
//     if (n % 2 == 0) {
//         solveEven(n, k);
//     }
//     else {
//         solveOdd(n, k);
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
// }