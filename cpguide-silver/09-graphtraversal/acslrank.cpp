/*

    August 16, 2026
    Hengsheng Wang
    ACSL 2009 Practices - Problem 4) Rank

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool dfs(int curr, int startWith, vector<int>& visited) {
    for (auto& connect : adj[curr]) {
        if (connect == startWith) {
            return true;
        }
        if (visited[connect] == 0) {
            visited[connect] = 1;
            bool doesWork = dfs(connect, startWith, visited);
            if (doesWork) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    adj.resize(n);
    for (int i = 0; i < k; i++) {
        int a, b, s1, s2;
        cin >> a >> b >> s1 >> s2;
        a--; b--;
        if (s1 > s2) {
            adj[a].push_back(b);
        }
        else {
            adj[b].push_back(a);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> visited (n, 0);
        visited[i] = 1;
        bool weGet = dfs(i, i, visited);
        if (weGet) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}