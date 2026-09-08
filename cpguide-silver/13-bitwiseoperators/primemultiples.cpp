/*

    Prime Multiples - CSES Problemset
    Hengsheng W.
    Monday September 7, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> vals (k);
    for (auto& val : vals) {
        cin >> val;
    }

    ll answer = 0;
    for (ll i = 1; i < (1 << k); i++) {
        ll primePD = 1;
        for (ll j = 0; j < k; j++) {
            if (i & (1 << j)) {
                if (primePD > n / vals[j]) {
                    primePD = n + 1;
                    break;
                }
                primePD *= vals[j];
            }
        }
        if (__builtin_popcountll(i) % 2 == 1)  answer += n / primePD;
        else                                   answer -= n / primePD;
    }
    cout << answer << '\n';
}