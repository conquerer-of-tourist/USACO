/*

    August 8th, 2026
    Ciel and Duel (B) - Codeforces Round 190 (Div. 1)

*/

#include <bits/stdc++.h>
using namespace std;


vector<int> jATK;
vector<int> jDEF;
vector<int> cards;

int solve1() {
    int total = min(jATK.size(), cards.size());
    int returnVal = 0;
    for (int i = 0; i < total; i++) {
        int currJiro = i;
        int currCiel = cards.size() - (i + 1);

        if (cards[currCiel] >= jATK[i]) {
            returnVal += cards[currCiel] - jATK[i];
        }
        else {
            break;
        }
    }
    return returnVal;
}

int solve2() {
    if (jDEF.size() + jATK.size() > cards.size()) {
        return 0;
    }

    multiset<int> ourCards;
    for (auto& card : cards) {
        ourCards.insert(card);
    }

    for (auto& def : jDEF) {
        auto it = ourCards.upper_bound(def);
        if (it == ourCards.end()) {
            return 0;
        }
        ourCards.erase(it);
    }

    vector<int> remaining;
    for (auto& val : ourCards) {
        remaining.push_back(val);
    }

    sort(remaining.begin(), remaining.end());

    sort(jATK.begin(), jATK.end());

    int returnVal = 0;
    for (int i = 0; i < jATK.size(); i++) {
        if (remaining[remaining.size() - i - 1] < 
            jATK[jATK.size() - i - 1]) {
            return 0;
        }
    }
    for (auto& val : remaining) {
        returnVal += val;
    }
    for (auto& val : jATK) {
        returnVal -= val;
    }
    return returnVal;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string k;
        cin >> k;
        int a;
        cin >> a;
        if (k == "ATK") {
            jATK.push_back(a);
        }
        else {
            jDEF.push_back(a);
        }
    }
    sort(jATK.begin(), jATK.end());
    sort(jDEF.begin(), jDEF.end());

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cards.push_back(a);
    }
    
    sort(cards.begin(), cards.end());

    int a1 = solve1();
    int a2 = solve2();
    cout << max(a1, a2) << '\n';
}