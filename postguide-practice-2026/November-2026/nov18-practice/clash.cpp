/*

    USACO 2026 Third Contest (Silver)

    Hengsheng Wang
    Problem 1. Clash
    Nov. 18, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

int main()
{
    int n, h;
    cin >> n >> h;

    vector<pair<int, int>> cards (n);
    for (auto& card : cards) {
        cin >> card.second;
        card.first = 1;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        cards[a - 1].first = 0;
    }

    priority_queue<pii, vector<pii>, greater<pii>> hand;
    queue<pii> drawPile;

    for (int i = 0; i < h; i++) {
        hand.push(cards[i]);
    }
    for (int i = h; i < n; i++) {
        drawPile.push(cards[i]);
    }

    ll curTime = 0;

    vector<ll> firstCycle (n - h + 2, 0);
    vector<ll> prefixWC   (n - h + 2, 0);

    for (int i = 0; i < n - h + 1; i++) {
        curTime += hand.top().second;

        prefixWC[i + 1] = prefixWC[i] + (!hand.top().first);

        drawPile.push(hand.top());
        hand.pop();
        firstCycle[i + 1] = curTime;

        hand.push(drawPile.front());
        drawPile.pop();
    }

    int q;
    cin >> q;
    while (q--) {
        ll a;
        cin >> a;

        ll cycleTime = firstCycle[n - h + 1];
        ll cycleWins = prefixWC[n - h + 1];

        ll fullCycles = a / cycleTime;
        ll rem = a % cycleTime;

        int idx = upper_bound(firstCycle.begin(), firstCycle.end(),
                              rem) - firstCycle.begin() - 1;

        cout << fullCycles * cycleWins + prefixWC[idx] << '\n';
    }
}