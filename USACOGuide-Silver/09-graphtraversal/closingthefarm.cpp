/*

    USACO 2016 US Open Contest - P3. Closing the Farm (Silver)
    August 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int adj[3000][3000];
set<int> active;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for (int i = 0; i < n; i++) {
        active.insert(i);
    }
    //
    for (int i = 0; i < n; i++) {
        //
    }
}