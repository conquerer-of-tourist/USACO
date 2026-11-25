/*
    Hengsheng Wang
    USACO Silver
    February 1st, 2026
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long k = 1;
    for (int i = 0; i < n; i++) {
        k *= 2;
    }
    for (int i = 0; i < k; i++) {
        string curr = (bitset<12>(i)).to_string();
        // curr = curr.substr()
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