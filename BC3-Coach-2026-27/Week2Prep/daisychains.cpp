/*

    2020 Bronze - Daisy Chains
    Hengsheng W.
    Monday, September 14, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> currValues;
            int total = 0;
            for (int curr = i; curr <= j; curr++) {
                total += vals[curr];
                currValues.push_back(vals[curr]);
            }
            int numHere = j - i + 1;
            for (int flower : currValues) {
                if (flower * numHere == total) {
                    answer++;
                    break;
                }
            }
        }
    }
    cout << answer << '\n';
}