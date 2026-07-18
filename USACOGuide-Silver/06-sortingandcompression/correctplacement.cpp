/*

    Information
    =================
    User: bpcf
    Date: July 16th, 2026
    Prob: E. Correct Placement
    Comp: Codeforces Round 693 (Divison 2)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define p pair<long long, long long>

struct human {
    int a;
    int b;
    int index;
};

void solve()
{
    ll n;
    cin >> n;
    vector<human> vals;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        human thingie;
        thingie.a = x;
        thingie.b = y;
        thingie.index = i;

        vals.push_back(thingie);
    }

    sort(vals.begin(), vals.end(), [](const human& h1, const human& h2) {
        if (h1.a == h2.a) {
            return h1.b < h2.b;
        }
        return h1.a < h2.a;
    });

    vector<p> prefixMinB (n);
    vector<ll> answers (n);
    map<ll, p> groups;

    prefixMinB[0].first = vals[0].b;
    prefixMinB[0].second = vals[0].index;

    for (ll i = 1; i < n; i++) {
        if (prefixMinB[i - 1].first > vals[i].b) {
            prefixMinB[i].first = vals[i].b;
            prefixMinB[i].second = vals[i].index;
        }
        else {
            prefixMinB[i] = prefixMinB[i - 1];
        }
    }

    for (ll i = 0; i < n; i++) {
        if (groups.find(vals[i].a) == groups.end()) {
            groups[vals[i].a] = {i, i};
        }
        else {
            groups[vals[i].a].second = i;
        }
    }

    for (auto& thing : groups) {
        ll start = thing.second.first;
        ll end = thing.second.second;

        if (start == 0) {
            for (ll i = start; i <= end; i++) {
                answers[vals[i].index] = -1;
            }
        }
        else {
            ll minHereB = prefixMinB[start - 1].first;
            for (ll i = start; i <= end; i++) {
                if (minHereB < vals[i].b) {
                    answers[vals[i].index] = prefixMinB[start - 1].second + 1;
                }
                else {
                    answers[vals[i].index] = -1;
                }
            }
        }
    }
    for (auto& answer : answers) {
        cout << answer << " ";
    }
    cout << '\n';
}

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}