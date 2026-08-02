/*

    Information
    ======================
    bpcf
    July 31, 2026
    Problem B. USB vs. PS/2
    Educational Codeforces Round 17

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    ll n;
    cin >> n;
    vector<ll> usb;
    vector<ll> ps2;
    for (ll i = 0; i < n; i++) {
        ll a; string k;
        cin >> a >> k;
        if (k == "USB") {
            usb.push_back(a);
        }
        else {
            ps2.push_back(a);
        }
    }
    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());

    ll totalSum = 0;
    ll totalCount = 0;

    ll curr = 0;
    while (t1 > 0 && curr < usb.size()) {
        totalSum += usb[curr];
        curr++;
        totalCount++;
        t1--;
    }

    ll curr2 = 0;
    while (t2 > 0 && curr2 < ps2.size()) {
        totalSum += ps2[curr2];
        curr2++;
        totalCount++;
        t2--;
    }

    vector<ll> remaining;
    for (ll i = curr; i < usb.size(); i++) {
        remaining.push_back(usb[i]);
    }
    for (ll i = curr2; i < ps2.size(); i++) {
        remaining.push_back(ps2[i]);
    }
    sort(remaining.begin(), remaining.end());
    ll curr3 = 0;

    while (t3 > 0 && curr3 < remaining.size()) {
        totalSum += remaining[curr3];
        curr3++;
        totalCount++;
        t3--;
    }
    cout << totalCount << " " << totalSum << '\n';
}