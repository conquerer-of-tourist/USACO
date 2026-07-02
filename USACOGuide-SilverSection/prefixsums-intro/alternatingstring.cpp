/*
    Contests: Codeforces Round 970 (Division 3)
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: July 2nd, 2026
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    //
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