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
    int n, m, r;
    cin >> n >> m >> r;

    int gallonsRemain = 0;

    vector<int> cows (n);
    for (auto& cow : cows) {
        cin >> cow;
        gallonsRemain += cow;
    }

    sort(cows.begin(), cows.end());

    vector<p> stores (m);
    for (int i = 0; i < m; i++) {
        cin >> stores[i].second >> stores[i].first;
    }

    vector<ll> farmers (r);
    for (auto& farmer : farmers) {
        cin >> farmer;
    }
    sort(farmers.rbegin(), farmers.rend());

    int curFirstCow = 0;
    int curLastCow = n - 1;
    int curStore = 0;

    for (int i = 0; i < r; i++) {
        int curCowGallons = cows[curFirstCow];
        
    }
}

/*

Cows
=============

1 2 4 6 7

Stores are wiling to offer the following quantities:

10 gallons for 25 cents each
15 gallons for 15 cents each
2 gallons for 10 cents each

The neighbors offer 
250 a day
100 a day
80 a day
40 a day

The thing is that each cow is only able to commit to one thing:
- either the store milk
- or giving it to the neighbor

there are two directions that we can look in:
- we can either look at the most milk-producing cows
- this will allow us to maximize the amount of money to make by giving them to a store
- the amount of money that this cow would be worth is ∑ [(# gallons) * (amt/gal)]

instead, we could
wait actuall yea

we're just always maximizing how much we can make with the optimal cows
it's like
ok so basically we can iterate through the (neighbors)
* and the neighbors are in decreasing order
* and then each time, we have all of the cows, right
* so we look: for the MAXIMALLY PRODUCING COW
    * is it more optimal to:
        * ONE: take the minimally producing cow and sell it
        * or TWO: take the maximally producing cow and produce milk?

so:

for (iteration through the farmers; from greatest to least)
* so look at the current amount we could make from selling to a store:
    * just give all of our gallons to the store
    * or we run out of cows; done.

//


*/