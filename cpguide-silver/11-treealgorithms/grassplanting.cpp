/*

    Hengsheng Wang
    Grass Planting (USACO 2019 January Contest, Silver)

    August 23, 2026
    Practice Session on Trees

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int n;

int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    cin >> n;
    ve<ve<int>> adj (n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mini = 0;
    for (auto& val : adj) {
        mini = max(mini, (int) val.size() + 1);
    }
    cout << mini << '\n';
}