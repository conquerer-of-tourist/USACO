/*

    August 22, 2026
    Codeforces Venture Cup 2017 - C. Poland Ball and Forest

    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

void dfs(int i, ve<int>& visited, ve<ve<int>>& adj) {
    for (auto& val : adj[i]) {
        if (!visited[val]) {
            visited[val] = 1;
            dfs(val, visited, adj);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    ve<ve<int>> adj (n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        adj[i].push_back(a - 1);
        adj[a - 1].push_back(i);
    }
    ve<int> visited (n, 0);

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj);
            counter++;
        }
    }
    cout << counter << '\n';
    return 0;
}