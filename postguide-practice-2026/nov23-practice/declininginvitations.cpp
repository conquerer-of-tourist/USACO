/*

    Declining Invitations
    =============================
    Problem Redo
    Hengsheng Wang
    Monday, Nov. 23, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector
#define minHp priority_queue<int, vector<int>, greater<int>>
#define maxHp priority_queue<int>

void propogate (

    ve<int>& full,
    ve<int>& p,
    ve<ve<int>>& satisfied,
    ve<maxHp> criterion,
    int& sumOfRanks,
    int& personID,
    int reqID

) {
    int curr = satisfied[personID][reqID];
    if (criterion[curr].size() < full[curr]) {
        criterion[curr].push(personID);
        sumOfRanks += personID;
        return;
    }

    int displaced = 0;
    if (criterion[curr].top() > personID) {
        displaced = criterion[curr].top();
        criterion[curr].pop();
        criterion[curr].push(personID);
    }
    else {
        displaced = personID;
    }

    auto possibleNxt = lower_bound(satisfied[displaced].begin(),
                                       satisfied[displaced].end(),
                                       reqID);

    if (possibleNxt == satisfied[displaced].end()) {
        return;
    }

    sumOfRanks = sumOfRanks - displaced;

    int movedReq = (possibleNxt - satisfied[displaced].begin() - 1);
    propogate(full, p, satisfied, criterion, sumOfRanks, displaced, movedReq);
    return;
}

int main()
{
    int n, c;
    cin >> n >> c;

    ve<int> full (c);
    for (auto& fullVal : full) {
        cin >> fullVal;
    }

    ve<int> p (n);
    for (auto& contestant : p) {
        cin >> contestant;
        contestant--;
    }

    ve<ve<int>> satisfied (n);
    for (int i = 0; i < n; i++) {
        int numSat;
        cin >> numSat;
        for (int j = 0; j < numSat; j++) {
            int req;
            cin >> req;
            satisfied[i].push_back(req);
        }
        sort(satisfied.begin(), satisfied.end());
    }
    
    ve<maxHp> criterion (c);

    int sumOfRanks = 0;
    for (int i = n - 1; i >= 0; i--) {
        propogate(full, p, satisfied, criterion, sumOfRanks, p[i], 0);
        
        cout << sumOfRanks << '\n';
    }
}