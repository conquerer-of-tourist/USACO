/*

    CSES Problemset - Tree Diameter
    August 23, 2026
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int main()
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
    cout << deepestDepth2 << '\n';
    return 0;
}