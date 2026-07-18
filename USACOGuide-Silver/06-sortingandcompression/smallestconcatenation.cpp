/*

    Information
    ======================
    bpcf
    July 15th, 2026
    Educational Codeforces Round 9: Problem C

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    sort(vals.begin(), vals.end(), [](const string& a, const string& b) {
        return a + b < b + a;
    });
    for (auto& val : vals) {
        cout << val;
    }
    return 0;
}