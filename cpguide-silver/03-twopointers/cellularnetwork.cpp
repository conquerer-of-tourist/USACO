/*

    Info
    ----------------------
    Hengsheng Wang
    Educational Codeforces Round 15 (Division 2)
    July 20, 2026
    C. Cellular Network

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    set<int> cities;
    set<int> towers;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        cities.insert(k);
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        towers.insert(k);
    }
    vector<int> cityList;
    vector<int> towerList;

    for (auto& val : cities) {
        cityList.push_back(val);
    }
    for (auto& val : towers) {
        towerList.push_back(val);
    }
    
    int maxDist = 0;
    int lClose = 0;
    for (int i = 0; i < cityList.size(); i++) {
        int curLoc = cityList[i];

        while (true) {
            if (lClose < towerList.size() - 1) {
                if (towerList[lClose + 1] < curLoc) {
                    lClose++;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }

        if (lClose < towerList.size() - 1) {
            maxDist = max(maxDist, min(abs(curLoc - towerList[lClose]),
                                       abs(curLoc - towerList[lClose + 1])
            ));
        }
        else {
            maxDist = max(maxDist, abs(curLoc - towerList[lClose]));
        }
    }
    cout << maxDist << '\n';
}