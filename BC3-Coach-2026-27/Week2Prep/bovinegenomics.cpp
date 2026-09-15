/*

    Bovine Genomics (Bronze 2017)
    September 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> spotted (n, vector<int> (m, 0));
    vector<vector<int>> normal (n, vector<int> (m, 0));

    for (auto& cow : spotted) {
        for (auto& base : cow) {
            cin >> base;
        }
    }
    for (auto& cow : normal) {
        for (auto& base : cow) {
            cin >> base;
        }
    }
    int answer = 0;
    for (int i = 0; i < m; i++) {
        set<int> sV, nV;
        for (int j = 0; j < n; j++) {
            sV.insert(spotted[j][i]);
        }
        for (int j = 0; j < n; j++) {
            nV.insert(normal[j][i]);
        }
        bool flag = true;
        for (auto& val : sV) {
            if (nV.find(val) != nV.end()) {
                flag = false;
            }
        }
        if (flag) {
            answer++;
        }
    }
    cout << answer << '\n';
}