// Codeforces A. Elections

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> vals = {a, b, c};
    sort(vals.begin(), vals.end());
    
    int maximal = vals[2];

    if (vals[1] < vals[2]) {
        if (maximal == a) {
            cout << "0 ";
        } else {
            cout << maximal - a + 1 << " ";
        }
        if (maximal == b) {
            cout << "0 ";
        } else {
            cout << maximal - b + 1 << " ";
        }
        if (maximal == c) {
            cout << "0 ";
        } else {
            cout << maximal - c + 1 << " ";
        }
    }
    else if (vals[0] == vals[2]) {
        cout << "1 1 1";
    }
    else {
        if (a != maximal) {
            cout << maximal - a + 1 << " ";
        }
        else {
            cout << "1 ";
        }
        if (b != maximal) {
            cout << maximal - b + 1 << " ";
        }
        else {
            cout << "1 ";
        }
        if (c != maximal) {
            cout << maximal - c + 1 << " ";
        }
        else {
            cout << "1 ";
        }
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}