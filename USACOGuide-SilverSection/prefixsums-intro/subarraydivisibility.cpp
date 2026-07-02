/*
    Contests: CSES Problemset
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: June 30, 2026
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;

    map<ll, ll> freq;
    freq[0] = 1;

    ll answer = 0;
    ll currSum = 0;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        currSum += a;

        currSum %= n;
        if (currSum < 0) {
            currSum += n;
        }
        answer += freq[currSum];
        freq[currSum] += 1;
    }
    cout << answer << '\n';
}