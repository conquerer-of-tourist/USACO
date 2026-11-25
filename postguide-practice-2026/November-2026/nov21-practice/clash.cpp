/*

    USACO 2026 Third Contest - Silver
    Problem 1. Clash

    Hengsheng Wang
    November 21, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<long long, long long>

int main()
{
    ll n, h;
    cin >> n >> h;
    vector<pi> cards (n, make_pair(1, 0));
    for (auto& card : cards) {
        cin >> card.second;
    }

    ll k;
    cin >> k;

    for (ll i = 0; i < k; i++) {
        ll a;
        cin >> a;
        cards[a - 1].first = 0;
    }

    queue<pi> drawPile;
    priority_queue<pi, vector<pi>, greater<pi>> hand;

    for (ll i = 0; i < h; i++) {
        hand.push(cards[i]);
    }
    
    for (ll i = h; i < n; i++) {
        drawPile.push(cards[i]);
    }

    ll wcGiven = 0;
    ll curTime = 0;
    vector<ll> prefix (n - h + 2, 0);
    vector<ll> cycle  (n - h + 2, 0);
    for (ll i = 0; i < n - h + 1; i++) {
        ll topVal = hand.top().second;
        ll topTyp = hand.top().first;

        drawPile.push(hand.top());
        hand.pop();

        curTime += topVal;

        if (topTyp == 0) {
            wcGiven++;
        }

        prefix[i + 1] = wcGiven;
        cycle[i + 1] = curTime;

        hand.push(drawPile.front());
        drawPile.pop();
    }

    ll q;
    cin >> q;
    while (q--) {
        ll t;
        cin >> t;
        ll ful = t / curTime;
        ll rem = t % curTime;

        ll ans = (ful) * wcGiven;
        ans += prefix[upper_bound(
                        cycle.begin(), 
                        cycle.end(), rem) - 
                        cycle.begin() - 1];

        cout << ans << '\n';
    }
}