// Hengsheng Wang
// USACO Silver, February 21st, 2026 - Clash!
// Yippee!

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, h, k, q;

int main()
{
    freopen("sample.txt", "r", stdin);
    cin >> n >> h;
    vector<pair<ll, ll>> cards (n);
    vector<pair<ll, ll>> sorted;
    for (ll i = 0; i < n; i++) {
        cin >> cards[i].second;
        cards[i].first = 1;
        sorted.push_back({i + 1, cards[i].second});
    }

    sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b){
        return a.second < b.second;
    });

    cin >> k;
    vector<ll> winConditions (k);
    for (auto& winCondition : winConditions) cin >> winCondition;

    sort(winConditions.begin(), winConditions.end());

    queue<ll> winConditionQ;
    for (auto& wc : winConditions) {
        winConditionQ.push(wc);
    }

    ll nonOversized = 0;
    ll counter = 0;
    for (ll i = 0; i < n; i++) {
        if (winConditionQ.empty()) {
            nonOversized += sorted[i].second;
            counter++;
        }
        if (!winConditionQ.empty() && sorted[i].first == winConditionQ.front()) {
            nonOversized += sorted[i].second;
            counter++;
            winConditionQ.pop();
        }
        if (counter == n - h + 1) {
            break;
        }
    }

    for (auto& winCondition : winConditions) {
        cards[winCondition - 1].first = 0;
    }

    queue<pair<ll, ll>> drawPile;
    vector<pair<ll, ll>> curHand;

    for (ll i = 0; i < h; i++) {
        curHand.push_back(cards[i]);
    }
    sort(curHand.begin(), curHand.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    for (int i = h; i < n; i++) {
        drawPile.push(cards[i]);
    }

    int getFirstWin = 0;

    if (curHand[0].first != 0) {
        while (drawPile.front().first != 0) {
            //
        }
    }

    cin >> q;

    while (q--) {
        ll goalTime;
        cin >> goalTime;
        cout << (goalTime / nonOversized) * k << '\n'; 

        /*
            1) We first need to find the time that it takes in order to GET a win-condition card
            2) Then, we have to find the time it takes to play it??
            3) The greedy idea is that we just keep on storing the (h - 1) biggest cards in our hand pile
            4) Keep on playing the remaining one that we have
            5) 
        */
    }
}