/*

    August 20, 2026
    Map of Sweden - Kattis IO
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int swedenComponent = -1;

void dfs(   vector<vector<int>>& grid,
            vector<vector<int>>& visited, 
            map<int, int>& components, int i, int j) {
    //
}

int main()
{
    int r, c, u;
    cin >> r >> c >> u;
    vector<vector<int>> grid (r, vector<int> (c, 0));
    vector<vector<int>> visited (r, vector<int> (c, 0));
    map<int, int> components;
    for (auto& row : grid) {
        for (auto& cell : grid) {
            char a;
            cin >> a;
            if (a == '.') a = 0;
            if (a == '#') a = 1;
            if (a == 'S') a = 2;
        }
    }
    int curLabel = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j] == 0) {
                visited[i][j] = 1;
                components[i] = 0;
                dfs(grid, visited, components);
            }
        }
    }
}

/*

    Current Thoughts:
        * For each new value, first check all four surroundings
        * If not connected to anything; turn it into a new component
        * If currently connected to the first component; we're automatically increasing by 1
        * Keep a map or something that tracks:
        *       {key: component, value: area}
        * And this way, whenever we connect to the first component; remove this from map

*/