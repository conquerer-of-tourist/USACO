#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    freopen(
        "input", "r", stdin
    );
    int n, c;
    cin >> n >> c;
    vector<int> constraints (c);
    for (int i = 0; i < c; i++) {
        cin >> constraints[i];
    }
    vector<int> ordering (n);
    for (int i = 0; i < n; i++) {
        cin >> ordering[i];
    }
    map<int, vector<int>> success;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int sat;
            cin >> sat;
            success[ordering[i] - 1].push_back(sat);
        }
    }
    for (int numR = 0; numR <= n - 1; numR++) {
        vector<int> members;
        for (int i = numR; i < n; i++) {
            members.push_back(ordering[i]);
        }
        sort(members.begin(), members.end());
        vector<int> chosen;
        for (int i = 0; i < c; i++) {
            int k = 0;
            for (int m = 0; m < (int) members.size(); m++) {
                if (k == constraints[i]) {
                    break;
                }
                if (find(success[members[m]].begin(), 
                        success[members[m]].end(), i + 1) ==
                        success[members[m]].end()) {
                    continue;
                }
                else {
                    chosen.push_back(members[m]);
                    k++;
                }
            }
            // while (!members.empty() && k < constraints[i]) {
            //     if (find(success[members[start].first].begin(), 
            //             success[members[start].first].end(), i + 1) ==
            //             success[members[start].first].end()) {
            //         start++;
            //         continue;
            //     }
            //     else if (declined[start]) {
            //         chosen.push_back(members[start].first);
            //         members.erase(members.begin() + start);
            //         k++;
            //     }
            // }
        }
        int ans = 0;
        for (auto& ch : chosen) {
            ans += ch;
        }
        cout << ans << '\n';
    }
}