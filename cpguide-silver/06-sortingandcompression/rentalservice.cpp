/*

    Information
    =================
    Hengsheng Wang
    Contest: USACO 2018 January Silver Contest; Problem 2. Rental Service
    Date Started: July 14th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define p pair<long long, long long>

int main()
{
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    ll n, m, r;
    cin >> n >> m >> r;

    vector<ll> cows (n);
    for (auto& cow : cows) {
        cin >> cow;
    }

    sort(cows.rbegin(), cows.rend());

    vector<p> stores (m);
    for (ll i = 0; i < m; i++) {
        cin >> stores[i].second >> stores[i].first;
    }

    sort(stores.rbegin(), stores.rend());

    vector<ll> farmers (r);
    for (auto& farmer : farmers) {
        cin >> farmer;
    }
    sort(farmers.rbegin(), farmers.rend());

    ll bestAnswer = 0;
    ll currStore = 0;

    vector<ll> milkingProfit (n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        ll newMilk = cows[i - 1];

        milkingProfit[i] = milkingProfit[i - 1];

        while (newMilk > 0 && currStore < m) {
            ll amountSold = min(newMilk, stores[currStore].second);
            milkingProfit[i] += amountSold * stores[currStore].first;

            newMilk -= amountSold;
            stores[currStore].second -= amountSold;

            if (stores[currStore].second == 0) {
                currStore++;
            }
        }
    }

    vector<ll> rentalProfit (n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        rentalProfit[i] = rentalProfit[i - 1] + ((i <= r) ? farmers[i - 1] : 0);
    }
    
    for (ll k = 0; k <= n; k++) {
        ll total = milkingProfit[k] + rentalProfit[n - k];
        bestAnswer = max(bestAnswer, total);
    }
    cout << bestAnswer << '\n';
}

// /*

//     Information
//     =================
//     Hengsheng Wang
//     Contest: USACO 2018 January Silver Contest; Problem 2. Rental Service
//     Date Started: July 14th, 2026

// */

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define p pair<long long, long long>

// int main()
// {
//     ll n, m, r;
//     cin >> n >> m >> r;

//     ll gallonsRemain = 0;

//     vector<ll> cows (n);
//     for (auto& cow : cows) {
//         cin >> cow;
//         gallonsRemain += cow;
//     }

//     sort(cows.begin(), cows.end());

//     vector<p> stores (m);
//     for (ll i = 0; i < m; i++) {
//         cin >> stores[i].second >> stores[i].first;
//     }

//     sort(stores.rbegin(), stores.rend());

//     vector<ll> farmers (r);
//     for (auto& farmer : farmers) {
//         cin >> farmer;
//     }
//     sort(farmers.rbegin(), farmers.rend());

//     ll curFirstCow = 0;
//     ll curLastCow = n - 1;
//     ll curStore = 0;
//     ll answer = 0;

//     for (ll i = 0; i < r; i++) {
//         while (true) {
//             ll curCowGallons = cows[curFirstCow];

//             if (curCowGallons > stores[curStore].second) {
//                 // this means we would have to overlap it to other stores as well
//                 // so we can just calculate the amount that for this store; move on?
//                 // and compare it to the day for a rental?
//             }
//             else if (curCowGallons == stores[curStore].second) {
//                 answer += curCowGallons * stores[curStore].first;
//                 stores[curStore].second -= curCowGallons;
//                 curStore++;
//                 curFirstCow++;
//             }
//             else {
//                 if (farmers[i] > curCowGallons * stores[curStore].first) {
//                     answer += farmers[i];
//                     curLastCow--;
//                     break;
//                 }
//                 else {
//                     answer += curCowGallons * stores[curStore].first;
//                     stores[curStore].second -= curCowGallons;
//                     curFirstCow++;
//                 }
//             }
//         }
//     }
// }