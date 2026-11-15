/*

    P. 3 [SWS] [2026 First Contest, USACO Silver]

    Hengsheng Wang
    Novemeber 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<long long, long long>
#define ve vector

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> r (n - k + 1);
    for (auto& val : r) {
        char a; cin >> a;
        val = (a == '0') ? 0 : 1;
    }

    int minOne = 0, maxOne = 0;
    int initOneMin = 0;
    int initOneMax = 0;

    vector<int> diffs; // # of 1's versus # of 0's

    for (int i = 0; i < min(n - k + 1, k); i++) {
        int curr = i + k;

        int num0 = 1, num1 = 0;
        int lastVal = 1;
        while (curr < n) {
            int g = r[curr - i] ^ r[curr - i + 1] ^ lastVal;

            lastVal = g;

            if (g == 0) num0++;
            else num1++;
            curr += k;
        }
        if (num0 > num1) {
            minOne += num1;
            maxOne 
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}