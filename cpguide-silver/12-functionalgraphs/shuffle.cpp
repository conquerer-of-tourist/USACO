/*

    The Bovine Shuffle
    2017 December Silver

    Problem 3
    September 26th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& v : vals) {
        cin >> v;
        v--;
    }
    vector<int> indegrees (n, 0);
    for (int i = 0; i < n; i++) {
        indegrees[vals[i]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) q.push(i);
    }
    int answer = n;
    while (!q.empty()) {
        int v = vals[q.front()];
        answer--;
        
        indegrees[v]--;
        q.pop();
        
        if (indegrees[v] == 0) {
            q.push(v);
        }
    }
    cout << answer << '\n';
}