/*

    USACO Guide Problemset | Codeforces | Problem B
    August 2nd, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> vals (n);
    for (auto & val : vals) {
        cin >> val;
    }
    sort(vals.begin(), vals.end());

    int total = 0;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (total + vals[i] <= x) {
            counter++;
            total += vals[i];
        }
        else {
            break;
        }
    }
    cout << counter << '\n';
}