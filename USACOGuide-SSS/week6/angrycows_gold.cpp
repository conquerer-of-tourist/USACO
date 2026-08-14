/*

    August 13, 2026
    Angry Cows - USACO Gold (2016 January)
    Hengsheng Wang

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
vector<ll> llist, rlist;

ll findNeedL(vector<ll>& vals, ll ind, ll prevGood) {
    return max(vals[ind] - vals[prevGood], llist[prevGood] + 1);
}

ll findNeedR(vector<ll>& vals, ll ind, ll prevGood) {
    return max(vals[prevGood] - vals[ind], rlist[prevGood] + 1);
}

bool check(vector<ll>& vals, double mid)
{
    for (ll i = 0; i < n; i++) {
        ll curNeed = llist[i];
        auto otherSide = upper_bound(vals.begin(), vals.end(), vals[i] + 2 * mid);
        otherSide--;

        ll otherIndex = otherSide - vals.begin();
        ll otherNeed = rlist[otherIndex];

        if (otherNeed + 1 <= mid && curNeed + 1 <= mid) {
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n;
    vector<ll> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    sort(vals.begin(), vals.end());

    llist.resize(n);
    rlist.resize(n);

    llist[0] = 0;
    for (ll i = 1; i < n; i++) {
        ll low = 0, high = i - 1;

        ll firstGood = i;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (vals[i] - vals[mid] <= llist[mid] + 1) {
                firstGood = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        ll best = INT_MAX;

        if (firstGood < i) {
            best = min(best, findNeedL(vals, i, firstGood));
        }

        if (firstGood >= 1) {
            best = min(best, findNeedL(vals, i, firstGood - 1));
        }

        llist[i] = best;
    }

    rlist[n - 1] = 0;

    for (ll i = n - 2; i >= 0; i--) {
        ll low = i + 1;
        ll high = n - 1;

        ll firstGood = n;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (vals[mid] - vals[i] >= rlist[mid] + 1) {
                firstGood = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        ll best = INT_MAX;

        if (firstGood < n) {
            best = min(best, findNeedR(vals, i, firstGood));
        }

        if (firstGood - 1 > i) {
            best = min(best, findNeedR(vals, i, firstGood - 1));
        }

        rlist[i] = best;
    }

    double l = 0, r = 1e9;
    double answer = r;

    while (l <= r) {
        double mid = l + (r - l) / 2;
        if (check(vals, mid)) {
            answer = mid;
            r = mid - 0.05;
        }
        else {
            l = mid + 0.05;
        }
    }
    cout << fixed << setprecision(1) << answer << '\n';
    return 0;
}