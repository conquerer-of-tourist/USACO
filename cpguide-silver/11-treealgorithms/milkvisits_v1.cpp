/*

    August 23, 2026
    Hengsheng Wang

    Milk Visits (USACO Silver 2019 December Contest)

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int n, m;
string s;

bool dfs(ve<ve<int>>& adj, ve<int>& visi, int curr, int end, char require, bool found) {
    if (curr == end) {
        return found;
    }
    for (auto& val : adj[curr]) {
        if (visi[val] == 0) {
            visi[val] = 1;
            bool worksHere = false;
            if (found == true) {
                worksHere = dfs(adj, visi, val, end, require, true);
            }
            else {
                worksHere = dfs(adj, visi, val, end, require, s[val] == require);
            }
            if (worksHere) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> m >> s;

    ve<ve<int>> adj (n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> answers;
    while (m--) {
        int a, b; char c;
        cin >> a >> b >> c;
        a--; b--;
        
        vector<int> visi (n, 0);
        visi[a] = 1;
        bool works = dfs(adj, visi, a, b, c, (s[a] == c));
        if (works) answers.push_back(1);
        else       answers.push_back(0);
    }
    for (auto& ans : answers) cout << ans;
}