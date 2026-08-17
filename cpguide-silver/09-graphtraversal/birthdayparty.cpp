/*

    Open Kattis - Birthday Party
    Hengsheng Wang
    August 16, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int dfs(int start, vector<set<int>>& adj, vector<int>& visited, 
    int banStart, int banEnd) {
    
    int ans = 1;
    for (auto& connection : adj[start]) {
        if (visited[connection] == 0 && 
            (!(start == banStart && connection == banEnd) &&
             !(start == banEnd   && connection == banStart))) {
            visited[connection] = 1;
            ans += dfs(connection, adj, visited, banStart, banEnd);
        }
    }
    return ans;
}

void solve(int p, int c)
{
    vector<set<int>> adj (p);
    for (int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int isYes = false;
    int counter = 0;
    for (auto& person : adj) {
        for (auto& connect : person) {
            vector<int> visited (p, 0);
            visited[0] = 1;
            int visitedNum = dfs(0, adj, visited, counter, connect);
            if (visitedNum < p) {
                isYes = true;
                break;
            }
        }
        counter++;
    }
    if (!isYes) {
        cout << "No" << '\n';
    }
    else {
        cout << "Yes" << '\n';
    }
}

int main()
{
    while (true) {
        int p, c;
        cin >> p >> c;
        if (p == 0 && c == 0) {
            break;
        }
        else {
            solve(p, c);
        }
    }
}