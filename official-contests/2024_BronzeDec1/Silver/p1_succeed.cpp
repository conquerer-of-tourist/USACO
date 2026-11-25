#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a (n);
    ll total = 0;
    for (auto& val : a) {
        cin >> val;
        total += val;
    }
    vector<ll> pL (n), pR (n);
    pL[0] = a[0];
    for (ll i = 1; i < n; i++) {
        pL[i] = pL[i - 1] + a[i];
    }
    pR[0] = a[n - 1];
    for (ll i = 1; i < n; i++) {
        pR[i] = pR[i - 1] + a[n - i - 1];
    }
    if (n == 2) {
        cout << pR[1] << " 0\n";
        return;
    }
    vector<ll> possible;
    possible.push_back(pL[n / 2 - 2]);
    possible.push_back(pR[n / 2 - 2]);
    for (int l = 1; l < n / 2 - 1; l++) {
        possible.push_back(pL[l - 1] + pR[(n / 2 - 1) - l - 1]);
    }
    sort(possible.begin(), possible.end());
    cout << total - possible[possible.size() - 1] << " " << 
            possible[possible.size() - 1] << '\n';
}

int main()
{
    // freopen("in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}