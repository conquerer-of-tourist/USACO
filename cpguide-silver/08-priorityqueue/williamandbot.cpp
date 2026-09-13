/*

    E. William and Root (UTPC Contest October '22)
    hangboy
    September 13, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& a : vals) {
        cin >> a;
    }

    priority_queue<int, vector<int>, greater<int>> taken;
    for (int i = 0; i < n; i++) {
        taken.push(vals[i]);
        if (i & 1) taken.pop();
    }

    ll a = 0;
    while (!taken.empty()) {
        a += taken.top(); taken.pop();
    }
    cout << a << '\n';
}