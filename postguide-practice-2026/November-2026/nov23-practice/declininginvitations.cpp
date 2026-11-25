/*

    Declining Invitations
    =============================
    Problem Redo
    Hengsheng Wang
    Monday, Nov. 23, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ve vector
#define maxHp priority_queue<ll>

void propogate (

    ve<ll>& full,
    ve<ll>& p,
    ve<ve<ll>>& satisfied,
    ve<maxHp>& criterion,
    ll& sumOfRanks,
    ll& personID,
    ll curr

) {
    if ((ll) criterion[curr].size() < (ll) full[curr]) {
        criterion[curr].push(personID);
        sumOfRanks += personID + 1;
        return;
    }

    ll displaced = 0;
    if (criterion[curr].top() > personID) {
        displaced = criterion[curr].top();
        sumOfRanks += personID + 1;
        criterion[curr].pop();
        criterion[curr].push(personID);

        sumOfRanks -= (displaced + 1);
    }
    else {
        displaced = personID;
    }

    auto possibleNxt = lower_bound(satisfied[displaced].begin(),
                                    satisfied[displaced].end(),
                                    curr + 1);

    if (possibleNxt == satisfied[displaced].end()) {
        return;
    }

    ll movedReq = satisfied[displaced][(possibleNxt - 
                  satisfied[displaced].begin())];
    propogate(full, p, satisfied, criterion, sumOfRanks, displaced, movedReq);
    return;
}

int main()
{
    ll n, c;
    cin >> n >> c;

    ve<ll> full (c);
    for (auto& fullVal : full) {
        cin >> fullVal;
    }

    ve<ll> p (n);
    for (auto& contestant : p) {
        cin >> contestant;
        contestant--;
    }

    ve<ve<ll>> satisfied (n);
    for (ll i = 0; i < n; i++) {
        ll numSat;
        cin >> numSat;
        for (ll j = 0; j < numSat; j++) {
            ll req;
            cin >> req;
            req--;
            satisfied[i].push_back(req);
        }
        sort(satisfied[i].begin(), satisfied[i].end());
    }
    
    ve<maxHp> criterion (c);

    vector<ll> answers (n);
    ll sumOfRanks = 0;
    for (ll i = n - 1; i >= 0; i--) {
        propogate(full, p, satisfied, criterion, sumOfRanks, p[i], satisfied[p[i]][0]);
        
        answers[i] = sumOfRanks;
    }
    for (auto& ans : answers) {
        cout << ans << '\n';
    }
}