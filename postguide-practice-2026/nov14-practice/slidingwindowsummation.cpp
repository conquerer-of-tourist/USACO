/*

    P. 3 [SWS] [2026 First Contest, USACO Silver]

    Hengsheng Wang
    November 14, 2026

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
    
    ve<int> r (n - k + 1);
    for (int i = 0; i < n - k + 1; i++) {
        char a;
        cin >> a;
        r[i] = a - '0';
    }

    ve<int> b (n, 0);

    for (int i = 0; i + k < n; i++) {
        b[i + k] = b[i] ^ r[i] ^ r[i + 1];
    }

    ve<int> chain0 (k, 0), chain1 (k, 0);
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            if (b[j] == 0) chain0[i]++;
            else           chain1[i]++;
        }
    }
    
    int par1min = 0;
    int par1max = 0;
    int min1 = 0;
    int max1 = 0;
    for (int i = 0; i < k; i++) {
        if (chain1[i] > chain0[i]) par1min++;
        if (chain0[i] > chain1[i]) par1max++;
        min1 += min(chain0[i], chain1[i]);
        max1 += max(chain0[i], chain1[i]);
    }

    int minChange = INT_MAX;
    for (int i = 0; i < k; i++) {
        minChange = min(minChange, abs(chain0[i] - chain1[i]));
    }

    if (par1min % 2 != r[0]) {
        min1 += minChange;
    }

    if (par1max % 2 != r[0]) {
        max1 -= minChange;
    }

    cout << min1 << ' ' << max1 << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}