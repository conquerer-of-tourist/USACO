/*

    August 23, 2026
    Hengsheng Wang

    Milk Visits (USACO Silver 2019 December Contest)
    Optimized CC Solution

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int n, m;
string s;

void dfs(ve<ve<int>>& adj, ve<int>& colorings) {
    //
}

int main()
{
    // freopen("milkvisits.in", "r", stdin);
    // freopen("milkvisits.out", "w", stdout);
    cin >> n >> m >> s;

    ve<ve<int>> adj (n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ve<int> colorings (n, -1);
    int curLabel = 1;
    for (int i = 0; i < n; i++) {
        if (colorings[i] == -1) {
            
        }
    }
}