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

int main()
{
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    int n;
    vector<int> usb;
    vector<int> ps2;
    for (int i = 0; i < n; i++) {
        int a; string k;
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

    int totalSum = 0;
    int totalCount = 0;

    int curr = 0;
    while (t1 > 0 && curr < usb.size()) {
        totalSum += usb[curr];
        curr++;
        totalCount++;
    }

    int curr2 = 0;
    while (t2 > 0 && curr2 < ps2.size()) {
        totalSum += ps2[curr2];
        curr2++;
        totalCount++;
    }

    vector<int> remaining;
    //
}