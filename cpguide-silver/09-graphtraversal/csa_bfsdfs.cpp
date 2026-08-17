/*

    August 17, 2026
    Hengsheng W.
    CSAcademy - BFS DFS

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> bList (n), dList (n);
    for (auto& b : bList) {
        cin >> b; b--;
    }
    for (auto& d : dList) {
        cin >> d; d--;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if (bList[1] != dList[1]) {
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        edges.push_back({dList[i - 1], dList[i]});
    }

    for (int i = 2; i < n; i++) {
        edges.push_back({0, bList[i]});
    }
    
    cout << edges.size() << '\n';
    for (auto& edge : edges) {
        cout << edge.first + 1 << " " << edge.second + 1 << '\n';
    }
}