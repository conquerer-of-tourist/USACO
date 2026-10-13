/*

    October 12, 2026
    Hengsheng Wang
    Sliding Window Summation
    (P3. 2026 Silver First Contest)

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

void solve()
{
    int n, k;
    cin >> n >> k;
    ve<int> vals (n, 0);
    for (auto& val : vals) {
        char a; cin >> a; val = (a == '0') ? 0 : 1;
    }

    //
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
---------------- 9:07 PM ----------------

SAMPLE TESTS

5 1
10011

* RI: Parity of number of 1's in Length-K window.
* Informally.
    * From i to (i + k - 1), basically the next k values including index i
    * Take the number of 1's; and find the parity of this value.

So in the sample, 10011 --> basically the number is fixed??

SOooo uh

The minimum value

The maximum value: //

oH WAIT we're looking for the min/max number of one's not the value itself.
so we can make a vec<bool>
and then it has a size n
so we can run a prefix on it or smth

right so........
second sample test:
5 2 
1001

So: 
    * Among the first two, there are odd # of 1's, so 10XXX or 01XXX
    * Among the second two, even number of 1's, so X11XX or X00XX
    * Among third pair: even number of 1's so XX11X or XX00X
    * Last pair: odd number of 1's so XXX10 or XXX01??

1) minimal construction: 10001? - 2 (correct)
2) maximal construction: 01110? - 3 (correct)

Wait that's weird, because the whole thing gets inverted
Maybe this is just a special case

Okay so lets just hypothetically suppose that we like
ran a prefix ummm
on the parity of the array's 1-count
so uh it would just be filled with ones and zeroes

so we could do something depending on the parity of the first index
take the second sample as our current thingie

1) the first value is a 1.

parity[0] = 1;
parity[1] = (we know that here, it's guaranteed to be like odd)
-> so this forces our next value?


parity[0] = 0.

OHHH so we could like do a bits thing on determining the first K bits
and then after that O(n) the rest

so the complexity would be O(2^k * n)
which is not very efficient..
do they have subtasks??

LOL so they have one subtask for N \le 8, which I guess is okay
but that's like 1/10th of the test cases so we better not do that

*/