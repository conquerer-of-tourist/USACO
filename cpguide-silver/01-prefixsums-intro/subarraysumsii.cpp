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
    ll n, x;
    cin >> n >> x;

    vector<ll> nums (n);
    for (auto& num : nums) {
        cin >> num;
    }

    vector<ll> prefix (n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    map<ll, ll> freq;
    freq[0] = 1;

    ll answer = 0;
    for (ll i = 1; i <= n; i++) {
        answer += freq[prefix[i] - x];

        freq[prefix[i]]++;
    }
    cout << answer << '\n';
}