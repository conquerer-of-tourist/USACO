/*

    Information
    ==================================
    CSES - Array Division
    Hengsheng Wang
    Binary Search Topics - August 10, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, k;

bool check(vector<ll>& arr, ll maxSum)
{
    ll subUsed = 0;
    ll curInd = 0;
    while (subUsed < k) {
        subUsed++;

        ll curSum = 0;
        ll nextInd = curInd;
        while (nextInd < n && curSum + arr[nextInd] <= maxSum) {
            curSum += arr[nextInd];
            nextInd++;
        }
        curInd = nextInd;
    }
    if (curInd < n) {
        return false;
    }
    return true;
}

int main()
{
    cin >> n >> k;
    vector<ll> arr (n);

    ll total = 0;
    for (auto& a : arr) {
        cin >> a;
        total += a;
    }

    ll l = 1, r = total;
    ll answer = total;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(arr, mid)) {
            r = mid - 1;
            answer = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << answer << '\n';
    return 0;

}