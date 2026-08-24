/*

    bpcf
    August 23, 2026
    F. Minimize the Diameter (Sasha T9 Contest #1)

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int solve()
{
    int n;
    cin >> n;
    ve<ve<int>> adj (n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ve<int> visited (n, 0);
    stack<pair<int, int>> vals;
    int deepestNode = 0, deepestDepth = 0;
    vals.push({0, 0});
    while (!vals.empty()) {
        int node = vals.top().first;
        int depth = vals.top().second;
        vals.pop();

        visited[node] = 1;
        for (auto& neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                if (deepestDepth < depth + 1) {
                    deepestNode = neighbor;
                    deepestDepth = depth + 1;
                }
                vals.push({neighbor, depth + 1});
            }
        }
    }
    fill(visited.begin(), visited.end(), 0);
    int deepestNode2 = 0, deepestDepth2 = 0;
    vals.push({deepestNode, 0});
    while (!vals.empty()) {
        int node = vals.top().first;
        int depth = vals.top().second;
        vals.pop();

        visited[node] = 1;
        for (auto& neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                if (deepestDepth2 < depth + 1) {
                    deepestNode2 = neighbor;
                    deepestDepth2 = depth + 1;
                }
                vals.push({neighbor, depth + 1});
            }
        }
    }
    return deepestDepth2;
}

int main()
{
    int a1 = solve();
    int a2 = solve();
    cout << max({a1, a2, (a1 + 1) / 2 + (a2 + 1) / 2 + 1}) << '\n';
}