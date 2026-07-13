/*

    Information
    =========================
    Hengsheng Wang
    July 7th, 2026
    CSES Problemset

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> vals (n);

    for (auto& val : vals) {
        cin >> val;
    }

    ll left = 0, right = 0;
    ll answer = 0;
    ll curSum = vals[0];
    while (left <= right && right < n) {
        if (curSum < x) {
            if (right + 1 >= n) {
                break;
            }
            else {
                curSum += vals[right + 1];
                right++;
            }
        }
        else if (curSum == x) {
            answer++;
            if (left < right) {
                curSum -= vals[left];
                left++;
            }
            else {
                if (right + 1 < n) {
                    curSum += (vals[right + 1] - vals[left]);
                    left++;
                    right++;
                }
                else {
                    break;
                }
            }
        }
        else {
            if (left < right) {
                curSum -= vals[left];
                left++;
            }
            else if (right + 1 < n) {
                right++;
                left = right;
                curSum = vals[right];
            }
            else {
                break;
            }
        }
    }
    cout << answer << '\n';
}