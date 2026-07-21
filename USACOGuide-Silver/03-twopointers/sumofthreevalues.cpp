/*

    Information
    =====================
    Hengsheng Wang
    July 9th, 13th, 20th 2026
    CSES Problemset: Sum of Three Values

*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
    ll n, x;
    cin >> n >> x;
    
    vector<pair<ll, ll>> vals (n);

    for (int i = 0; i < n; i++) {
        cin >> vals[i].first;
        vals[i].second = i + 1;
    }

    sort(vals.begin(), vals.end());

    for (int i = 0; i < n - 2; i++) {
        int curNeed = x - vals[i].first;

        int l = i + 1;
        int r = n - 1;
        int curSum = vals[l].first + vals[r].first;
        while (true) {
            if (l >= r) {
                break;
            }
            if (curSum == curNeed) {
                cout << vals[i].second << " " 
                     << vals[l].second << " " 
                     << vals[r].second << '\n';
                return 0;
            }
            else if (curSum < curNeed) {
                l++;
                curSum += (vals[l].first - vals[l - 1].first);
            }
            else {
                r--;
                curSum += (vals[r].first - vals[r + 1].first);
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}