/*

    Hengsheng W.

    Cow-Libi 2
    2026 Second Contest, Silver

    Nov. 15, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int t, c;

void solve()
{
    int n;
    cin >> n;
    int cN1 = 0;
    int cN2 = 0;
    vector<int> lSide (n), rSide (n);
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (a == 'N') cN1++;

        if (a == 'N') lSide[i] = 0;
        else          lSide[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (a == 'N') cN2++;

        if (a == 'N') rSide[i] = 0;
        else          rSide[i] = 1;
    }
    int v01 = 0, v10 = 0;
    int v00 = 0, v11 = 0;
    for (int i = 0; i < n; i++) {
        if (lSide[i] == 0 && rSide[i] == 1) {
            v01++;
        }
        else if (lSide[i] == 1 && rSide[i] == 0) {
            v10++;
        }
        else if (lSide[i] == 0 && rSide[i] == 0) {
            v00++;
        }
        else {
            v11++;
        }
    }

    if (cN1 % 2 != 0 || cN2 % 2 != 0 || cN1 != cN2) {
        cout << "NO" << '\n';
        return;
    }
    if (v01 != v10 ||
        (v00 > 0 && v11 > 0 && !(v10 > 0 && v01 > 0))) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';

    if (c == 1) {
        vector<int> s00, s11, s01, s10;

        for (int i = 0; i < n; i++) {
            if (!lSide[i] && !rSide[i]) s00.push_back(i + 1);
            else if (!lSide[i] && rSide[i]) s01.push_back(i + 1);
            else if (lSide[i] && !rSide[i]) s10.push_back(i + 1);
            else s11.push_back(i + 1);
        }
        
        vector<int> p;

        for (auto h : s11) {
            p.push_back(h);
        }

        if (!s10.empty()) {
            p.push_back(s10.back());
            s10.pop_back();
        }

        for (auto h : s00) {
            p.push_back(h);
        }

        while (!s10.empty()) {
            p.push_back(s01.back());
            p.push_back(s10.back());
            s01.pop_back();
            s10.pop_back();
        }

        if (!s01.empty()) {
            p.push_back(s01.back());
            s01.pop_back();
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << (i + 1 == n ? '\n' : ' ');
        }

        string owners (n, 'J');

        for (int i = 1; i < n; i++) {
            int prev = p[i - 1] - 1;
            if (rSide[prev] == 1) {
                owners[i] = owners[i - 1];
            }
            else {
                owners[i] = (owners[i - 1] == 'J' ? 'N' : 'J');
            }
        }

        cout << owners << '\n';
    }
}

int main()
{
    cin >> t >> c;
    while (t--) {
        solve();
    }
}