/*

    LeetCode - IPO
    Sep 20, 2026

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        int n = (int) capital.size();

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        
        priority_queue<int> available;
        int curr = 0;
        for (int i = 0; i < k; i++) {
            while (curr < n && projects[curr].first <= w) {
                available.push(projects[curr].second);
                curr++;
            }
            if (available.empty()) {
                break;
            }

            w += available.top();
            available.pop();
        }
        return w;
    }
};