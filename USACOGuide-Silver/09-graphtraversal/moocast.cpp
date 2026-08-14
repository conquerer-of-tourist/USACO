/*

    USACO 2016 December Contest, Silver | Problem 3. Moocast
    August 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define v vector

struct cow {
    int x, y, range;
};

int main()
{
    int n;
    cin >> n;
    v<v<int>> adj (n);
    v<cow> cows (n);
    //
    for (auto& c : cows) {
        cin >> c.x >> c.y >> c.range;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int xloc1 = cows[i].x;
                int xloc2 = cows[j].x;
                int yloc1 = cows[i].y;
                int yloc2 = cows[j].y;
                int distSQ = (xloc1 - xloc2) * (xloc1 - xloc2) + 
                             (yloc1 - yloc2) * (yloc1 - yloc2);
                int rangeSQ = cows[i].range * cows[i].range;

                if (rangeSQ >= distSQ) {
                    adj[i].push_back(j);
                }
            }
        }
    }
}