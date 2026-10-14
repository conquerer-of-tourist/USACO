/*

    October 12, 2026
    Hengsheng Wang
    Sliding Window Summation
    (P3. 2026 Silver First Contest)

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

void solve()
{
    int n, k;
    cin >> n >> k;
    ve<int> r (n - k + 1);
    for (auto& R : r) {
        char c;
        cin >> c; 
        R = (c == '0') ? 0 : 1;
    }
    int minPar = 0, maxPar = 0;

    int minAnswer = 0;
    int maxAnswer = 0;
    int minDiff = INT_MAX;
    for (int i = 0; i < k; i++) {
        int counter = 1;
        int start1 = 1;
        int curr = 1;
        for (int ind = i + k; ind < n; ind += k) {
            curr = curr ^ r[ind - k] ^ r[ind - k + 1];
            if (curr == 1) start1++;

            counter++;
        }
        int otherOption = counter - start1;
        minDiff = min(minDiff, abs(start1 - otherOption));
        minAnswer += min(otherOption, start1);
        maxAnswer += max(otherOption, start1);

        if (start1 < otherOption) minPar ^= 1;
        else maxPar ^= 1;
    }
    if (minPar != r[0]) minAnswer += minDiff;
    if (maxPar != r[0]) maxAnswer -= minDiff;

    cout << minAnswer << " " << maxAnswer << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}