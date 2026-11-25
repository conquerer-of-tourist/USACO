/*

    October 28, 2026
    Potion Farming

    Hengsheng Wang
    2024 January Silver Problem 2

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector
#define pii pair<int, int>

int n;

pii dfs(int curr, int par,  ve<int>& potions, 
                            ve<int>& count, 
                            ve<ve<int>>& tree) {
    if (curr != 0 && tree[curr].size() == 1) {
        return {1, min(1, count[curr])};
    }

    int ans1 = 0;
    int ans2 = count[curr];

    for (int child : tree[curr]) {
        if (child == par) continue;

        pii result = dfs(child, curr, potions, count, tree);
        ans1 += result.first;
        ans2 += result.second;
    }
    return {ans1, min(ans1, ans2)};
}

int main()
{
    cin >> n;

    ve<int> potions (n);
    ve<int> count   (n);
    for (auto& potion : potions) {
        cin >> potion;
        potion--;
    }

    ve<ve<int>> tree (n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[b].push_back(a);
        tree[a].push_back(b);
    }
    
    int travs = 0;
    for (int i = 1; i < n; i++){
         if (tree[i].size() == 1) travs++;
    }

    for (int i = 0; i < travs; i++) {
        count[potions[i]]++;
    }

    pii ans = dfs(0, -1, potions, count, tree);
    cout << ans.second << '\n';
}