/*

    Information
    ====================================================
    DATE            July 5th, 2026
    AUTHOR          Hengsheng Wang
    CONTEST         Codeforces Round 419 (Division 2)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, k, q;
    cin >> n >> k >> q;
    
    vector<int> diff (200003, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        diff[a]++;
        diff[b + 1]--;
    }

    for (int i = 1; i < 200001; i++) { 
        diff[i] += diff[i - 1];
    }
    
    vector<int> prefix (200003, 0);
    prefix[0] = (diff[0] >= k) ? 1 : 0;
    for (int i = 1; i < 200001; i++) {
        prefix[i] = prefix[i - 1] + ((diff[i] >= k) ? 1 : 0);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }
}