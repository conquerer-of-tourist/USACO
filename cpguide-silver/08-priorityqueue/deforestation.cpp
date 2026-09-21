/*

    2024 - Deforestation [December, Silver]
    Sunday, September 20, 2026
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> trees (n);
    for (auto& t : trees) {
        cin >> t;
    }
    sort(trees.begin(), trees.end());

    priority_queue<pair<int, int>> values;

    //
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}