/*

    Codeforces Round 862 (Division 2)
    F1. Survival of the Weakest (Easy Version)
    September 24, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> v (n);
    for (auto& V : v) {
        cin >> V;
    }
    ll total = (n) * (n - 1) / 2;

    priority_queue<ll> vals;
}