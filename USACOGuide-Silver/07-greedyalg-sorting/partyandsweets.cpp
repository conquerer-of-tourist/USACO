/*

    August 6, 2026
    Codeforces - The Party and Sweets

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, m;
    cin >> n >> m;

    ll total = 0;

    vector<ll> boys (n);
    for (auto& boy : boys) {
        cin >> boy;
        total += boy;
    }
    vector<ll> girls (m);
    ll totalGirl = 0;
    for (auto& girl : girls) {
        cin >> girl;
        totalGirl += girl;
    }
    sort(girls.begin(), girls.end());
    sort(boys.begin(), boys.end());

    if (boys[n - 1] > girls[0]) {
        cout << -1 << '\n';
        return 0;
    }

    ll answer = (total - boys[n - 1]) * m;
    answer += totalGirl;

    if (boys[n - 1] != girls[0]) {
        answer += girls[0] - boys[n - 2];
        answer += boys[n - 1] - girls[0];
    }

    cout << answer << '\n';
}