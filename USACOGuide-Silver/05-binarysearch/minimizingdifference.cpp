/*

    August 12, 2026
    hangboy
    Codeforces
    > Round 592 (Division 2)
    > E. Minimizing Difference

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, k;

bool check(vector<ll> arr, ll mid)
{
    // determien whether it workrs
}

int main()
{
    cin >> n >> k;
    vector<ll> arr (n);
    for (auto& a : arr) {
        cin >> a;
    }
    sort(arr.begin(), arr.end());

    ll l = 0, r = arr[n - 1] - arr[0];
    ll answer = r;
    
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(arr, mid)) {
            answer = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
}