/*
    Sliding Window Summation (USACO 2026 Contest 1, Silver)
    Hengsheng Wang
    November 19, 2026
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> r (n, 0);
    for (int i = 0; i < n - k + 1; i++) {
        char a;
        cin >> a;
        r[i] = ((a == '0') ? 0 : 1);
    }

    int minParity = 0;
    int maxParity = 0;

    int minVal = 0;
    int maxVal = 0;

    int minDiff = INT_MAX;

    for (int i = 0; i < k; i++) {
        int count0 = 1;
        int count1 = 0;
        int lastVal = 0;
        for (int j = i + k; j < n; j += k) {
            int curr = r[j - k] ^ r[j - k + 1] ^ lastVal;
            lastVal = curr;

            if (curr == 0) {
                count0++;
            }
            else {
                count1++;
            }
        }
        if (count0 > count1) {
            if (i < k) {
                maxParity++;
                maxParity %= 2;
            }
            minVal += count1;
            maxVal += count0;
        }
        else if (count0 < count1) {
            if (i < k) {
                minParity++;
                minParity %= 2;
            }
            minVal += count0;
            maxVal += count1;
        }
        else {
            minVal += count0;
            maxVal += count1;
        }

        if (i < k) {
            minDiff = min(minDiff, abs(count1 - count0));
        }
    }

    if ((minParity % 2) != r[0]) {
        minVal += minDiff;
    }
    if ((maxParity % 2) != r[0]) {
        maxVal -= minDiff;
    }

    cout << minVal << " " << maxVal << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}