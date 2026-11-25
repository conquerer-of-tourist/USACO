/*
    F. John Loves Rotations
    USACO 2026 Second Contest, Silver -Problem 3

    Hengsheng W.
    November 15, 2026
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a (n);
    for (auto& A : a) cin >> A;

    for (int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }

    vector<int> total (n + 1, 0);
    int need = 0;

    for (int i = 0; i < n; i++) {
        if (total[a[i]] == 0) need++;

        total[a[i]]++;
    }

    vector<int> freq (n + 1, 0);
    vector<int> rEnd (n);

    int r = 0;
    int distinct = 0;

    for (int l = 0; l < n; l++) {
        while (distinct < need) {
            freq[a[r]]++;
            if (freq[a[r]] == 1) {
                distinct++;
            }

            r++;
        }

        rEnd[l] = r - 1;

        freq[a[l]]--;
        if (freq[a[l]] == 0) distinct--;
    }

    vector<int> ans (n, n);

    for (int i = 0; i < n; i++) {
        int len = rEnd[i] - i;

        ans[i] = min(ans[i], len);

        ans[rEnd[i] % n] = min(ans[rEnd[i] % n], len);
    }
    
    for (int k = 0; k < 2 * n; k++) {
        int i = k % n;
        ans[(i + 1) % n] = min(ans[(i + 1) % n], ans[i] + 1);
    }

    for (int k = 2 * n - 1; k >= 0; k--) {
        int i = k % n;
        ans[(i - 1 + n) % n] = min(ans[(i - 1 + n) % n], ans[i] + 1);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ((i != n - 1) ? ' ' : '\n');
    }
}