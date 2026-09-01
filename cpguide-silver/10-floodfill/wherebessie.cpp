/*

    August 30, 2026
    3. Where's Bessie? (USACO 2017 U.S. Open Silver)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid (n, vector<char> (n));
    for (auto & r : grid) {
        for (auto& c : r) {
            cin >> c;
        }
    }
}