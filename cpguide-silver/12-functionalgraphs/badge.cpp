/*

    August 26, 2026
    Codeforces Round 503 (Division 2) - B. Badge
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(vector<int>& visited, int curr, vector<int>& succ) {
    if (visited[curr] == 2) {
        return;
    }
    int next1 = succ[curr];
    visited[next1]++;
    dfs(visited, next1, succ);    
}

int main()
{
    cin >> n;
    vector<int> successors (n);
    for (auto& successor : successors) {
        int a; cin >> a;
        successor = a - 1;
    }
    for (int i = 0; i < n; i++) {
        vector<int> visited (n, 0);
        visited[i] = 1;
        dfs(visited, i, successors);
        for (int j = 0; j < n; j++) {
            if (visited[j] == 2) {
                cout << j + 1 << " ";
                break;
            }
        }
    }
    return 0;
}