/*

    Cow-libi | USACO 2023 February
    Hengsheng W.
    Wednesday, September 9, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct poi {
    ll x, y, t;
};

bool works(poi& a, poi& b) {
    ll xx = a.x - b.x, yy = a.y - b.y, tt = a.t - b.t;
    return (xx * xx) + (yy * yy) <= (tt * tt);
}

int main()
{
    ll g, n;
    cin >> g >> n;
    vector<poi> grazes (g), cows (n);
    for (auto& gr : grazes) {
        cin >> gr.x >> gr.y >> gr.t;
    }
    for (auto& co : cows) {
        cin >> co.x >> co.y >> co.t;
    }
    sort(grazes.begin(), grazes.end(), [](const poi& a, const poi& b){
        return a.t < b.t;
    });

    ll answer = 0;
    for (ll i = 0; i < n; i++) {
        poi curr = cows[i];

        ll pos = upper_bound(   grazes.begin(), 
                                grazes.end(), 
                                curr.t,
                                [](ll t, const poi& p) 
                                {
                                    return t < p.t;
                                }) - grazes.begin();
        bool innocent = false;
        for (ll y = pos - 1; y <= pos; y++) {
            if (0 <= y && y < g) {
                innocent |= !works(grazes[y], curr);
            }
        }
        answer += innocent;
    }
    cout << answer << '\n';
}