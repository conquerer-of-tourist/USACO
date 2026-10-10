/*

    USACO Silver - Switching on the Lights
    P2 2015 December

    Hengsheng Wang
    October 10, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int main()
{
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    ve<ve<int>> visited (n + 2, ve<int> (n + 2, 0));
    ve<ve<int>> grid (n + 2, ve<int> (n + 2, 0));

    map<int, ve<int>> adj;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[103 * a + b].push_back(103 * c + d);
    }

    queue<int> q;
    q.push(103 * 1 + 1);
    grid[1][1] = 1;

    while (!q.empty()) {
        int curA = q.front() / 103;
        int curB = q.front() % 103;

        q.pop();

        if (curA == 0 || curB == 0 || 
            curA == n || curB == n || 
            visited[curA][curB] == 1 || 
            grid[curA][curB] == 0) continue;

        visited[curA][curB] = 1;
        for (auto& square : adj[curA * 103 + curB]) {
            grid[square / 103][square % 103] = 1;
            //
        }

        q.push((curA - 1) * 103 + curB);
        q.push((curA + 1) * 103 + curB);
        q.push((curA) * 103 + curB - 1);
        q.push((curA) * 103 + curB + 1);
    }

    int answer = 0;

    for (auto& aa : grid) {
        for (auto& bb : aa) {
            answer += bb;
        }
    }
    cout << answer << '\n';
}