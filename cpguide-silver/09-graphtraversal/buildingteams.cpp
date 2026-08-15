/*

    CSES Problemset - Building Teams
    August 14, 2026
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> people;
vector<vector<int>> adjacency;

bool dfs(int ind)
{
    for (auto& fr : adjacency[ind]) {
        if (people[fr] == 0) {
            people[fr] = 3 - people[ind];
            if (!dfs(fr)) {
                return false;
            }
        }
        else if (people[fr] == people[ind]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    people.resize(n);
    for (auto& person : people) {
        person = 0;
    }

    adjacency.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (people[i] == 0) {
            people[i] = 1;
            bool worked = dfs(i);
            if (!worked) {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
        }
    }
    for (auto& person : people) {
        if (person == 0) {
            cout << "1 ";
        }
        else {
            cout << person << " ";
        }
    }
    return 0;
}