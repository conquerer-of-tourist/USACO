/*

    November 12, 2026
    Problem 1. Convention

    2018 December - Silver Contest

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> arrivals (n);
    for (auto& a : arrivals) cin >> a;

    sort(arrivals.begin(), arrivals.end());

    /*
    
    1.

    So theoretically, we could just run a binary search
    And then for each tested value, see if it works?

    2.

    But couldn't we technically just try out values?
    Wait no, because we don't know when we could just let a bus go.

    Because it's true that MC \ge N

    So we don't know if a bus could be let go or not.

    3.

    Okay so it seems like the implementation is just
    like
    do a binary search on answer

    and then for each one, just do a simulation check

    so each checking thing is like O(N)

    and then the binary seearch is like log(t)

    So this would be O(N * log (t))

    Checking bounds, we have essentially

    10^5 (30) ish

    So this is decently manageable.
    
    */
}