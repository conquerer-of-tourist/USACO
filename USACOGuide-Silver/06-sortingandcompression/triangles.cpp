/*

    Information
    =================
    Author: Hengsheng Wang
    Problem: USACO 2020 February Contest, Silver. Problem 2. Triangles
    Date: July 13th, 14th, 2026


    NOTE: INITIALLY FINISHED FOR "Silver Self Study Class"
*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<ll, ll>
#define ll long long

const ll MOD = (ll) 1e9 + 7;

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    vector<p> vals (n);

    map<ll, vector<p>> yCorrespond;
    map<ll, vector<p>> xCorrespond;
    
    for (int i = 0; i < n; i++) {
        cin >> vals[i].first >> vals[i].second;

        ll x = vals[i].first;
        ll y = vals[i].second;

        xCorrespond[x].push_back({y, i});
        yCorrespond[y].push_back({x, i});
    }

    vector<ll> horizontal (n, 0);

    for (auto& thing : yCorrespond) {
        vector<p> curVals = thing.second;
        int m = curVals.size();
        sort(curVals.begin(), curVals.end());
    
        vector<ll> prefix (m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefix[i + 1] = prefix[i] + curVals[i].first;
        }

        for (int i = 0; i < m; i++) {
            ll x = curVals[i].first;
            ll lDist = x * i - prefix[i];

            ll rDist = prefix[m] - prefix[i + 1] - (m - i - 1) * x;

            int originalIndex = curVals[i].second;
            horizontal[originalIndex] = lDist + rDist;
        }
    }

    vector<ll> vertical (n, 0);

    for (auto& thing : xCorrespond) {
        vector<p> curVals = thing.second;
        int m = curVals.size();
        sort(curVals.begin(), curVals.end());

        vector<ll> prefix (m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefix[i + 1] = prefix[i] + curVals[i].first;
        }

        for (int i = 0; i < m; i++) {
            ll x = curVals[i].first;
            ll bottomDist = x * i - prefix[i];
            ll topDist = prefix[m] - prefix[i + 1] - (m - i - 1) * x;

            int originalIndex = curVals[i].second;
            vertical[originalIndex] = bottomDist + topDist;
        }
    }
    ll answer = 0;
    for (int i = 0; i < n; i++) {
        ll curr = vertical[i] * horizontal[i];
        curr %= MOD;
        answer += curr;
        answer %= MOD;
    }
    cout << answer << '\n';
}