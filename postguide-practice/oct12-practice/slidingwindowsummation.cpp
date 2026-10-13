/*

    October 12, 2026
    Hengsheng Wang
    Sliding Window Summation
    (P3. 2026 Silver First Contest)

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

Thought Process
---------------- 9:07 PM ---------

SAMPLE TESTS

5 1
10011

* RI: Parity of number of 1's in Length-K window.
* Informally.
    * From i to (i + k - 1), basically the next k values including index i
    * Take the number of 1's; and find the parity of this value.

So in the sample, 10011 --> basically the number is fixed??

SOooo uh

The minimum valu

The maximum value: //

oH WAIT we're looking for the min/max number of one's not the value itself.
so we can make a vec<bool>
and then it has a size n
so we can run a prefix on it or smth

//

*/