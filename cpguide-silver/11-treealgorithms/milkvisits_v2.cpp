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

void dfs(ve<ve<int>>& adj, ve<int>& colorings, int curLabel, int i, char type) {
    for (auto& conn : adj[i]) {
        if (colorings[conn] == -1 && s[conn] == type) {
            colorings[conn] = curLabel;
            dfs(adj, colorings, curLabel, conn, type);
        }
    }
}

int main()
{
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
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
            colorings[i] = curLabel;
            dfs(adj, colorings, curLabel, i, s[i]);
            curLabel++;
        }
    }
    vector<int> answers;
    while (m--) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        if (colorings[a] == colorings[b]) answers.push_back(s[a] == c);
        else answers.push_back(1);
    }
    for (auto& ans : answers) cout << ans;
}