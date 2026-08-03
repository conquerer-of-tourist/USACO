/*

    Movie Festival II (CSES)
    Hengsheng Wang
    July 28, 2026
    July 29, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies (n);
    for (auto& movie : movies) {
        cin >> movie.first >> movie.second;
    }
    sort(movies.begin(), movies.end(), [](const auto& a,
                                          const auto& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    int counter = 0;
    multiset<int> endTimes;
    for (auto& movie : movies) {
        auto it = endTimes.upper_bound(movie.first);

        if (it != endTimes.begin()) {
            --it;
            endTimes.erase(it);
            endTimes.insert(movie.second);
            counter++;
        }
        else if (endTimes.size() < k) {
            endTimes.insert(movie.second);
            counter++;
        }
    }
    cout << counter << '\n';
}