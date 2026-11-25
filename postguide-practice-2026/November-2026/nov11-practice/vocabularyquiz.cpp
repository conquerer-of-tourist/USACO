/*

    Visits
    USACO 2022 U.S. Open - Silver
    Problem 1

    November 11, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pii pair<long long, long long>
#define ve  vector

int main()
{
    int n;
    cin >> n;

    ve<ll> parent (n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
    }

    ve<ll> depth (n + 1, 0), children (n + 1, 0);

    for (int i = 1; i <= n; i++) {
        depth[i] = depth[parent[i]] + 1;
        children[parent[i]]++;
    }

    int m = 0;
    for (int i = 1; i <= n; i++) {
        m += (children[i] == 0) ? 1 : 0;
    }

    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;
        int x = w;

        while (x != 0 && children[parent[x]] == 1) {
            x = parent[x];
            children[x] = 0;
        }

        cout << depth[x] << '\n';
        if (x != 0) children[parent[x]]--;
    }
}