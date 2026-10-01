/*

    2022 U.S. Open - Silver
    Problem 1. Visits
    September 30, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
vector<ll> a;
vector<ll> v;
vector<ll> visited;

ll largest(ll currSmall, ll currTotal, ll curr) {
    if (visited[curr] == 1) {
        return currTotal - currSmall;
    }
    visited[curr] = 1;
    ll nextOne = a[curr];
    ll nextMoo = v[curr];
    currSmall = min(currSmall, nextMoo);
    return largest(currSmall, currTotal + nextMoo, nextOne);
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll ai, vi;
        cin >> ai >> vi;
        a.push_back(ai - 1);
        v.push_back(vi);
        visited.push_back(0);
    }
    
    ll answer = 0;
    for (ll i = 0; i < n; i++) {
        if (visited[i] == 0) {
            answer += largest(INT_MAX, 0, i);
        }
    }
    cout << answer << '\n';
}