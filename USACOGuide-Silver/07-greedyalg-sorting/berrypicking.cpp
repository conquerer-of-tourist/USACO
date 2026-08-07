/*

    August 6th, 2026
    Berry Picking (2020 USACO January - Silver)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    
    int maximal = 0;
    vector<int> originalBerries (n);
    for (auto& tree : originalBerries) {
        cin >> tree;
        maximal = max(maximal, tree);
    }

    int answer = 0;

    for (int i = 1; i <= maximal; i++) {
        int full = 0;
        for (auto& tree : originalBerries) {
            full += tree / i;
        }

        if (full < k / 2) {
            continue;
        }

        if (full >= k) {
            answer = max(answer, (k / 2) * i);
            continue;
        }

        vector<int> remainders;

        for (auto& tree : originalBerries) {
            remainders.push_back(tree % i);
        }
        sort(remainders.rbegin(), remainders.rend());

        int current = (full - k / 2) * i;
        for (int j = 0; j < min(k - full, n); j++) {
            current += remainders[j];
        }
        answer = max(answer, current);
    }

    cout << answer << '\n';
    return 0;
}