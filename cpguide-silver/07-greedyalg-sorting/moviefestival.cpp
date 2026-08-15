/*

    CSES - Movie Festival
    Hengsheng Wang
    August 2nd, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define p pair<int, int>

int main()
{
    int n;
    cin >> n;
    vector<p> movies (n);
    for (auto& m : movies) {
        cin >> m.first >> m.second;
    }

    sort(movies.begin(), movies.end(), [](const auto& a,
                                          const auto& b){
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    int currEnd = 0;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].first >= currEnd) {
            currEnd = movies[i].second;
            counter++;
        }
        else {
            continue;
        }
    }
    cout << counter << '\n';
}