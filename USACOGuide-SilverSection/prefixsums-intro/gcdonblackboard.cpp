/*
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: June 29-30, 2026
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    vector<int> prefixGCD (n + 1, 1);
    prefixGCD[0] = vals[0];
    vector<int> suffixGCD (n + 1, 1);
    suffixGCD[n] = vals[n - 1];
    for (int i = 0; i < n - 1; i++) {
        prefixGCD[i + 1] = gcd(prefixGCD[i], vals[i + 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suffixGCD[i] = gcd(suffixGCD[i + 1], vals[i]);
    }
    int maximal = 1;
    maximal = max(maximal, prefixGCD[n - 2]);
    maximal = max(maximal, suffixGCD[1]);
    for (int i = 0; i < n - 2; i++) {
        maximal = max(maximal, gcd(prefixGCD[i], suffixGCD[i + 2]));
    }
    cout << maximal << '\n';
}