/*

    CSES Problemset - Planets Cycles
    September 28, 2026
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> planets (n);
    for (auto& p : planets) {
        cin >> p; p--;
    }
    
    vector<int> visited (n, 0);
    vector<int> answers (n, -1);
    vector<int> position (n, - 1);

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        vector<int> path;
        int curr = i;

        while (visited[curr] == 0) {
            visited[curr] = 1;
            
            position[curr] = path.size();
            path.push_back(curr);

            curr = planets[curr];
        }
        
        if (visited[curr] == 1) {
            int start = position[curr];
            int len = path.size() - start;

            for (int j = start; j < path.size(); j++) {
                answers[path[j]] = len;
            }

            for (int j = start - 1; j >= 0; j--) {
                answers[path[j]] = answers[path[j + 1]] + 1;
            }
        }
        else if (visited[curr] == 2) {
            int val = answers[curr];
            for (int j = path.size() - 1; j >= 0; j--) {
                answers[path[j]] = val + 1;
                val = answers[path[j]];
            }
        }

        for (int node : path) {
            visited[node] = 2;
        }
    }
    for (auto& ans : answers) {
        cout << ans << ' ';
    }
    return 0;
}