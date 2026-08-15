/*

    USACO 2016 US Open Contest - P3. Closing the Farm (Silver)
    August 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> active;

int dfs(vector<int>& visited, int k) {
    int answer = 1;
    for (int connection : adj[k]) {
        if (!visited[connection] && 
            active[connection]) {
            visited[connection] = 1;
            answer += dfs(visited, connection);
        }
    }
    return answer;
}

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    active.resize(n);
    for (int i = 0; i < n; i++) {
        active[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        int startWith = 0;
        while (!active[startWith]) {
            startWith++;
        }

        vector<int> visited (n, 0);

        visited[startWith] = 1;
        int result = dfs(visited, startWith);

        if (result == n - i) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }

        int a;
        cin >> a; a--;
        active[a] = 0;
    }
}