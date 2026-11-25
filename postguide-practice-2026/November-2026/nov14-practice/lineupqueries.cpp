/*

    Hengsheng W.

    Lineup Queries (P. 1)
    2026 First Contest [Silver]
    Nov. 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll g;
        cin >> g;
        if (g == 1) {
            ll cow, t;
            cin >> cow >> t;

            ll curTime = 2 * cow - 1;

            if (t <= curTime) {
                cout << cow << '\n';
                continue;
            }

            curTime = (cow == 0) ? 0 : (3 * cow - 1);

            while (curTime < t) {
                ll tNext = curTime + 1 + ((curTime + 1) / 2);
                curTime = tNext;
            }

            cout << curTime - t << '\n';
        }
        else {
            ll pos, t;
            cin >> pos >> t;

            while (t > 0) {
                ll mid = t / 2;
                if (pos > mid) {
                    break;
                }
                else if (pos == mid) {
                    pos = 0;
                    t--;
                }
                else {
                    ll k = max((ll) 1, (t - 2 * pos) / 3);
                    pos = pos + k;
                    t = t - k;
                }
            }
            cout << pos << '\n';
        }
    }
}