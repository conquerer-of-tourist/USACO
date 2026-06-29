// Problem Name            -> Haybales
// Link                    -> https://www.spoj.com/problems/HAYBALE/
// Submit                  -> Hengsheng Wang
// Date                    -> June 26 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v (n + 1, 0);
    while (k--) {
        int a, b; 
        cin >> a >> b;
        v[a - 1] += 1;
        v[b] -= 1;
    }
    vector<int> vals (n, 0);
    int curr = 0;
    vals[0] = v[0];
    for (int i = 1; i < n; i++) {
        vals[i] = vals[i - 1] + v[i - 1];
    }
    sort(vals.begin(), vals.end());
    cout << vals[vals.size() / 2];
}