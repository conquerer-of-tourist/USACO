/*

    November 25, 2026 | Hengsheng Wang
    ====================================
    > USACO 2026 Third Contest
    > Problem 2 - Milk Buckets

*/

// Can the 2026-2027 Schedule just come out already?

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a)
{
    int i, v, t;
    cin >> i >> v >> t;

    //
}

int main()
{
    int n;
    cin >> n;
    vector<int> a (n);
    for (auto& capacity : a) {
        cin >> capacity;
    }

    int q;
    cin >> q;
    while (q--) {
        solve(a);
    }
}


/*

* N buckets in a stack (up to 2 * 100,000)
* Each bucket has capacity a_i, where ai is integer range
* Tap in the top bucket : 1 gal / second
* A pool below pool bucket N
* At start of t + 1 ssecond (after reaching capacity @ t second)
    > dump contents into bucket below, or the pool
    > reverts to filling, at the end of t + 1 second
    > no collection during the 1-second flip

Queries: up to 300,000:
> initially, given the a1, a2, ... aN
> for each query
    * i, v, t: ith bucket gets new ai to be v; find question for t
    * so, how many gallons of mik in bucket after t seconds.
*/