/*
    Contests: USACO Silver 2016 January - Silver
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: June 30, 2026
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> nums (n);
    for (auto& num : nums) {
        cin >> num;
    }
    map<int, vector<int>> occurences;
    int prefix = 0;
    for (int i = 0; i < n; i++) {
        prefix += nums[i];
        prefix %= 7;

        occurences[prefix].push_back(i);
    }
    int answer = 0;
    for (auto& thing : occurences) {
        int a = thing.second[0];
        int b = thing.second[thing.second.size() - 1];
        int curr = b - a;
        answer = max(answer, curr);
    }
    cout << answer << '\n';
    return 0;
}