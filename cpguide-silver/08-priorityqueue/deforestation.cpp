/*

    2024 - Deforestation [December, Silver]
    Sunday, September 20/23, 2026
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>

struct interval {
    int l, r, t;
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> trees (n);
    for (auto& t : trees) {
        cin >> t;
    }
    sort(trees.begin(), trees.end());

    vector<interval> laws;
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        interval curr;
        curr.l = a;
        curr.r = b;
        curr.t = c;
        laws.push_back(curr);
    }

    sort(laws.begin(), laws.end(), [](const interval& a, const interval& b){
        if (a.l == b.l) {
            return a.r < b.r;
        }
        return a.l < b.l;
    });

    priority_queue<pii, vector<pii>, greater<pii>> values;

    int ans = 0, curr = 0;
    for (int x : trees) {
        while (curr < k && laws[curr].l <= x) {
            int existing = upper_bound(trees.begin(), trees.end(), laws[curr].r) -
                           lower_bound(trees.begin(), trees.end(), laws[curr].l);
            
            int cut = existing - laws[curr].t;
            int lim = ans + cut;

            values.push({lim, laws[curr].r});
            curr++;
        }

        while (!values.empty() && values.top().second < x) {
            values.pop();
        }

        if (values.empty() || ans < values.top().first) {
            ans++;
        }
    }
    cout << ans << '\n';

}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}