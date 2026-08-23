/*

    It turns out, I actually did this problem
    more than a year ago! Let's do it again

    Hengsheng Wang
    August 22, 2026
    CSES Problemset - Subordinates

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

void dfs(int curr, ve<ve<int>>& adj, ve<int>& subordinates) {
    if (adj[curr].size() == 0) {
        subordinates[curr] = 0;
    }
    for (auto& thingie : adj[curr]) {
        dfs(thingie, adj, subordinates);
        subordinates[curr] += subordinates[thingie] + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    ve<ve<int>> adj (n);
    ve<int> subordinates (n, 0);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
    }
    dfs(0, adj, subordinates);
    for (auto& val : subordinates) {
        cout << val << ' ';
    }
    return 0;
}