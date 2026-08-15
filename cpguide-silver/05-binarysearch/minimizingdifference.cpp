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

bool check(vector<ll>& arr, ll mid)
{
    map<ll, ll> occur;
    for (auto& val : arr) {
        occur[val]++;
    }

    ll used = 0;
    while (true) {
        ll leftBound = (*occur.begin()).first;
        ll leftCount = (*occur.begin()).second;

        ll rightBound = (*occur.rbegin()).first;
        ll rightCount = (*occur.rbegin()).second;

        if (rightBound - leftBound <= mid) {
            return true;
        }

        if (leftCount < rightCount) {
            auto secondOne = occur.begin(); secondOne++;
            ll nextVal = (*secondOne).first;
            ll needHere = (nextVal - leftBound) * leftCount;

            if (used + needHere <= k) {
                occur[nextVal] += leftCount;
                used += needHere;
                occur.erase(occur.begin());
            }
            else {
                ll required = rightBound - mid;
                if (required >= nextVal) {
                    return false;
                }
                else {
                    needHere = (required - leftBound) * leftCount;
                    if (used + needHere > k) {
                        return false;
                    }
                    occur.erase(occur.begin());
                    occur[required] = leftCount;
                    used += needHere;
                }
            }
        }
        else {
            auto adjacentOne = occur.rbegin(); adjacentOne++;

            ll nextVal = (*adjacentOne).first;
            ll needHere = (rightBound - nextVal) * rightCount;

            if (used + needHere <= k) {
                occur[nextVal] += rightCount;
                used += needHere;
                auto removeOne = occur.end(); removeOne--;
                occur.erase(removeOne);
            }
            else {
                ll required = leftBound + mid;
                if (required <= nextVal) {
                    return false;
                }
                else {
                    needHere = (rightBound - required) * rightCount;
                    if (used + needHere > k) {
                        return false;
                    }
                    auto removeOne = occur.end(); removeOne--;
                    occur.erase(removeOne);
                    occur[required] = rightCount;
                    used += needHere;
                }
            }
        }
    }
    return true;
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
    cout << answer << '\n';
    return 0;
}