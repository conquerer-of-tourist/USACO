#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("sample.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> buckets; // limit, current amount
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        buckets.push_back({l, 0});
    }
    buckets.push_back({INT_MAX, 0});
    int q;
    cin >> q;
    for (int w = 0; w < q; w++) {
        int s;
        int v;
        cin >> s >> v;
        buckets[s - 1].first = v;
        buckets[s - 1].second = 0;
        bool statusTop = 1;
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
            if (statusTop == 1) {
                buckets[0].second++;
            }
            if (buckets[0].first == buckets[0].second) {
                statusTop = 0;
            }
            for (int b = 0; b < n; b++) {
                if (buckets[b].second == buckets[b].first) {
                    buckets[b + 1].second = min(buckets[b + 1].first, buckets[b].second + buckets[b + 1].second);
                    b++;
                }
            }
        }
        cout << buckets[n].second << '\n';
        for (int i = 0; i <= n; i++) {
            buckets[i].second = 0;
        }
    }
}