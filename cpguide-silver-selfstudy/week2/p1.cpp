/*

    Information
    =================
    Author: Hengsheng Wang
    Problem: (P1) Splitting The Field; USACO 2016 Gold Open
    Date: July 5th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<ll, ll>
#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<p> cows (n);
    ll minX = 100000000000000000;
    ll minY = 100000000000000000;
    ll maxX = -1000000000000000;
    ll maxY = -1000000000000000;
    for (auto& cow : cows) {
        cin >> cow.first >> cow.second;
        minX = min(minX, cow.first);
        minY = min(minY, cow.second);
        maxX = max(maxX, cow.first);
        maxY = max(maxY, cow.second);
    }
    ll totalArea = (maxX - minX) * (maxY - minY);

    sort(cows.begin(), cows.end());

    vector<ll> preMin (n + 1, 1e10);
    vector<ll> preMax (n + 1, -1);
    vector<ll> sufMin (n + 1, 1e10);
    vector<ll> sufMax (n + 1, -1);

    
    for (ll i = 1; i <= n; i++) {
        preMin[i] = min(preMin[i - 1], cows[i - 1].second);
        preMax[i] = max(preMax[i - 1], cows[i - 1].second);
    }

    for (ll i = n - 1; i >= 0; i--) {
        sufMin[i] = min(sufMin[i + 1], cows[i].second);
        sufMax[i] = max(sufMax[i + 1], cows[i].second);
    }

    ll bestAns = 0;
    ll leftMost = cows[0].first;
    ll rightMost = cows[n - 1].first;
    for (ll i = 0; i < n - 1; i++) {
        ll lInclude = cows[i].first;
        ll rInclude = cows[i + 1].first;
        ll lTop = preMax[i + 1];
        ll lBottom = preMin[i + 1];
        ll rTop = sufMax[i + 1];
        ll rBottom = sufMin[i + 1];
        ll curArea = (lInclude - leftMost) * (lTop - lBottom) +
                      (rightMost - rInclude) * (rTop - rBottom);
        bestAns = max(bestAns, totalArea - curArea);
    }

    sort(cows.begin(), cows.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    vector<ll> preMinY (n + 1, 1e10);
    vector<ll> preMaxY (n + 1, -1);
    vector<ll> sufMinY (n + 1, 1e10);
    vector<ll> sufMaxY (n + 1, -1);

    
    for (ll i = 1; i <= n; i++) {
        preMinY[i] = min(preMinY[i - 1], cows[i - 1].first);
        preMaxY[i] = max(preMaxY[i - 1], cows[i - 1].first);
    }

    for (ll i = n - 1; i >= 0; i--) {
        sufMinY[i] = min(sufMinY[i + 1], cows[i].first);
        sufMaxY[i] = max(sufMaxY[i + 1], cows[i].first);
    }

    leftMost = cows[0].second;
    rightMost = cows[n - 1].second;
    for (ll i = 0; i < n - 1; i++) {
        ll lInclude = cows[i].second;
        ll rInclude = cows[i + 1].second;
        ll lTop = preMaxY[i + 1];
        ll lBottom = preMinY[i + 1];
        ll rTop = sufMaxY[i + 1];
        ll rBottom = sufMinY[i + 1];
        ll curArea = (lInclude - leftMost) * (lTop - lBottom) +
                      (rightMost - rInclude) * (rTop - rBottom);
        bestAns = max(bestAns, totalArea - curArea);
    }

    cout << bestAns << '\n';
}