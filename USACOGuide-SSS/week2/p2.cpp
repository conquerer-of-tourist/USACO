/*

    Information
    =================
    Author: Hengsheng Wang
    Problem: USACO 2020 February Contest, Silver. Problem 2. Triangles
    Date: July 13th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<ll, ll>
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<p> vals (n);
    map<int, vector<int>> yCorrespondence;
    map<int, vector<int>> xCorrespondence;
    for (auto& val : vals) {
        cin >> val.first >> val.second;
        xCorrespondence[val.first].push_back(val.second);
        yCorrespondence[val.second].push_back(val.first);
    }


    map<int, vector<int>> yCorrPrefix;
    map<int, vector<int>> xCorrPrefix;
    for (auto& thing : yCorrespondence) {
        sort(thing.second.begin(), thing.second.end());
        vector<int> currPrefix;
        currPrefix[0] = 0;
        currPrefix[1] = 0;
        for (int i = 1; i < thing.second.size(); i++) {
            currPrefix.push_back(currPrefix[i - 1] + thing.second[i] - thing.second[i - 1]);
        }
    }
    for (auto& thing : xCorrespondence) {
        sort(thing.second.begin(), thing.second.end());
    }
}