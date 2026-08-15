/*

    CSES Problemset - Stick Lengths
    July 31, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<ll> nums;
    for (ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    ll chosen = n / 2;
    ll counter = 0;
    for (ll i = 0; i < n; i++) {
        counter += abs(nums[i] - nums[chosen]);
    }
    if (n % 2 == 0) {
        chosen--;
        ll counter2 = 0;
        for (ll i = 0; i < n; i++) {
            counter2 += abs(nums[i] - nums[chosen]);
        }
        counter = min(counter, counter2);
    }
    cout << counter << '\n';
}