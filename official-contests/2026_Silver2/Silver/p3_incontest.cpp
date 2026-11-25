// /*
//     Hengsheng Wang
//     USACO Silver
//     February 1st, 2026
//  */

// #include <iostream>
// #include <vector>
// #include <set>
// #include <map>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> vals (n);
//     for (auto& val : vals) cin >> val;

//     set<int> uniques;
//     for (auto& val : vals) uniques.insert(val);
//     vector<int> uniqueVals;
//     for (auto& val : uniques) uniqueVals.push_back(val);

//     int diffs = uniques.size();

//     map<int, vector<int>> locations;
//     for (int i = 0; i < n; i++) {
//         locations[vals[i]].push_back(i);
//     }

//     vector<vector<int>> nearest (n, vector<int> (diffs, 1000000));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < diffs; j++) {
//             if (vals[i] == uniqueVals[j]) {
//                 nearest[i][j] = 0;
//                 continue;
//             }
//             for (auto& loc : locations[uniqueVals[j]]) {
//                 int wrapValueLeft = abs(i + n - loc);
//                 int wrapValueRight = ()
//                 nearest[i][j] = min(nearest[i][j], min(abs(i - loc), abs(i + n - loc)));
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         int maxVal = 0;
//         for (auto& dist : nearest[i]) {
//             maxVal = max(maxVal, dist);
//         }
//         cout << maxVal << " ";
//     }
// }