/*

    Information
    =================
    Author: Hengsheng Wang
    Problem: (P1) Splitting The Field; USACO 2016 Gold Open
    Date: July 5th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<int, int>
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<p> cows (n);
    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;
    for (auto& cow : cows) {
        cin >> cow.first >> cow.second;
        minX = min(minX, cow.first);
        minY = min(minY, cow.second);
        maxX = max(maxY, cow.first);
        maxY = max(maxY, cow.second);
    }
    ll totalArea = (maxX - minX) * (maxY - minY);

    sort(cows.begin(), cows.end());

    //
}