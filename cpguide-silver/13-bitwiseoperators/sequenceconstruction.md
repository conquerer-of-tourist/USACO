# Sequence Construction (2025 US Open Silver)
## Writing Information
* Writer: Hengsheng Wang
* Context:
    * September 6th, 2026 - Sunday
    * Labor Day Weekend
    * This weekend, I got 5 problems on CF Round 1119 and became pupil: $1102 \rightarrow 1214$.
    * We got a lot of AP Government homework as well; to take notes on Chapter 1.

# Experimental Process
## Brief Initial Thoughts
This problem immediately gives us restraints in math notation, which makes things very clear:
1. $a_1 + a_2 + \cdots + a_N = M$
2. Let $p_i = \text{popcount}(a_i)$. Then, $p_1 \oplus \cdots \oplus p_N = K$

Both $M$ and $K$ are given, so we're asked to determine a construction. This is very candid.

Since bitwise operations are a topic that only started getting tested extensively in recent years (as of 2026), we can look a bit at the properties of `popcount` and the $\oplus$ (XOR) operations.

## My Own Thought Process
I tried out a couple of the sample test cases (which you should always do), but didn't find anything very fruitful out of them. One of the first things that comes to mind when we're doing problems with bitwise operators is to analyze each bit index individually. So, I reached the conclusion that, when taking all bits $b_i$ at a certain index $c$, the XOR of these bits is $1$ IFF the number of $1$'s is odd.

The main reasoning is simple:
1. If we have two $1$'s, notice that $1 \oplus 1 = 0$, so this reduces the number of $1$'s by 2.
2. If we have a $1$ and a $0$, we get $1 \oplus 0 = 1$.

Everything afterward follows pretty nicely. However, I pretty much got stuck here; partly since I overthought the problem a tiny bit. It turns out, that even with certain edge cases (which I will explain later), the overall construction is pretty straightforward.

# Solution Explanation
Here's how the solution actually goes.
## Main Construction
Suppose, for example, that $K = 11101_2$. We can find the minimal set of integers $a_1$ through $a_H$ such that the second condition is true. The simple construction is that for each bit $b_i$ in $k$ where $b_i = 1$, we can let another value of $a$ be:
$$2^{\left(2^i\right)} - 1.$$
This way, this value of $a$ would have the desired component of the total popcount.

## Edge Cases
Okay that's it for the most part. There's a nice easy way to deal with a remaining sum having even parity, odd parity greater than 1, and odd parity equal to 1. I'm too lazy to put that in for now.

# Code
## Solution
Written in C++ (utilizes only tools up until C++11).

```c++
/*

    September 6th, 2026
    Sequence Construction - USACO Silver US Open 2025

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll m, k;
    cin >> m >> k;
    vector<ll> vals;
    ll totalSum = 0;
    for (int i = 0; i < 6; i++) {
        if ((k >> i) % 2 == 1) {
            ll curr = (1LL << (1LL << i)) - 1;
            totalSum += curr;
            vals.push_back(curr);
        }
    }
    if (totalSum > m || ((m - totalSum == 1) && (k % 2 == 0))) {
        cout << -1 << '\n';
        return;
    }
    if ((m - totalSum) % 2 == 0) {
        vals.push_back((m - totalSum) / 2);
        vals.push_back((m - totalSum) / 2);
    }
    else if ((m - totalSum) == 1) {
        vals.erase(vals.begin());
        vals.push_back(2);
    }
    else {
        vals.push_back(1);
        vals.push_back(2);
        totalSum += 3;
        vals.push_back((m - totalSum) / 2);
        vals.push_back((m - totalSum) / 2);
    }

    cout << vals.size() << '\n';
    for (auto& val : vals) cout << val << " ";
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```