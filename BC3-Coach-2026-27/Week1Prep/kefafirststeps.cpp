// Kefa First Steps - Sep 8, 2026

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }
    int longest = 1;
    int currInd = 0;
    while (true) {
        int currLen = 0;
        int currVal = INT_MIN;
        while (currInd + 1 < n) {
            if (vals[currInd + 1] >= currVal) {
                currLen++;
                currVal = vals[currInd];
                currInd++;
            }
            else {
                break;
            }
        }
        longest = max(longest, currLen);
        if (currInd == n - 2) {
            break;
        }
    }
    cout << longest << '\n';
}