/*

    U.S. Open Contest - 2023 Silver
    Problem 2. Field Day

    September 7, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c, n;
    cin >> c >> n;
    vector<int> vals (n, 0);
    vector<int> minChange (1 << c, INT_MAX);
    for (auto& val : vals) {
        for (int i = 0; i < c; i++) {
            char ch; cin >> ch;
            val += ((ch == 'G') ? (1 << i) : 0);
        }
        minChange[val] = 0;
    }
    for (int e = 0; e < c; e++) {
        for (int curr = 0; curr < (1 << c); curr++) {
            if (minChange[curr] != INT_MAX) {
                minChange[curr ^ (1 << e)] = min(minChange[curr ^ (1 << e)], 
                                                 minChange[curr] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << c - minChange[vals[i] ^ ((1 << c) - 1)] << '\n';
    }
}