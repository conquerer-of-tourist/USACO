/*

    Hengsheng Wang

    Problem 2. Declining Invitations
    USACO 2026 Second Contest - Silver

    November 16, 17, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void insert(int cow, int startCrit, 
            vector<priority_queue<int>>& criterions,
            vector<vector<int>>& cows,
            vector<int>& full, ll& total) {
    
    auto it = upper_bound(cows[cow].begin(), cows[cow].end(), startCrit);

    if (it == cows[cow].end()) {
        return;
    }

    int nextCrit = *it;

    if (criterions[nextCrit].size() < full[nextCrit]) {
        criterions[nextCrit].push(cow);

        total += cow + 1;
        return;
    }
    if (cow < criterions[nextCrit].top()) {
        int displaced = criterions[nextCrit].top();
        criterions[nextCrit].pop();
        criterions[nextCrit].push(cow);

        insert(displaced, nextCrit, criterions, cows, full, total);

        total += cow - displaced;
    }
    else {
        insert(cow, nextCrit, criterions, cows, full, total);
    }
}

int main()
{
    int n, c;
    cin >> n >> c;

    vector<int> full (c);
    for (auto& F : full) cin >> F;

    vector<int> p (n);
    for (auto& P : p) {
        cin >> P;
        P--;
    }

    vector<vector<int>> cows (n);
    for (int i = 0; i < n; i++){
        int n_i;
        cin >> n_i;
        for (int j = 0; j < n_i; j++) {
            int ci;
            cin >> ci;
            ci--;
            cows[i].push_back(ci);
        }
        sort(cows[i].begin(), cows[i].end());
    }

    vector<priority_queue<int>> criterions (c);

    vector<ll> ans (n);
    ll total = 0;

    for (int i = n - 1; i >= 0; i--) {
        int cow = p[i];
        insert(cow, -1, criterions, cows, full, total);
        ans[i] = total;
    }

    for (ll x : ans) {
        cout << x << '\n';
    }
}