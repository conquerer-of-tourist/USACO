# Searching for Soulmates (Silver 2022 January)
Solution Writing Explanation Information
* Writer: Hengsheng Wang
* Date: August 31, 2026

## 0 Notes
### 0.1 Funny!

It turns out, I've actually done this problem before, but I had absolutely no memory of it except for the problem name. That's actually why I decided to write a `md` file for the solution today!

## 1 Solution
### 1.1 Thought Process

I let the initial value of the cow be equal to $p$ and the destination value be $q$. Then, my initial thought process was simply to get as close from $p$ to $q$ as possible through occasional incerements by $1$ and multiplying/dividing by $2$ any other time.

However, the problem is that this solution is obviously wrong due to the counterexample in the test cases:

```
p: 997
q: 120
```

This logic would yield the answer $64$, but the best answer is $20$. So this doesn't work.

### 1.2 Key Observations

WLOG, assume that $p < q$. Notice that if we ever perform a $\div 2$ operation, we're never going to do a $\times 2$ operation after this.

The idea of the proof is, suppose we take any arbitary `/2` followed later by a `*2`. Then, in between, there must be only $k$ occurences of `+1` moves.

However, it would just be more optimal to add a `+1` a total of $\dfrac{k}{2}$ times. Lik, u know.

### 1.3 Construction

Okay, maybe the proof isn't completely rigorous and accurate, but you probably get the idea. It's just since that we can only add but cannot subtract, we'll never do a $\times 2$ after a $\div 2$. That probably sounds right. I don't know.

Anyway. LOL. The construction is just that we have
* A bunch of $*2$ and $+1$ moves (for parity)
* A long list of $+1$ moves
* A bunch of $\div 2$ and $+1$ moves (for parity)

### 1.4 Implementation Idea

So essentially it's just something like taking step (1) and working forward from $p$, and taking step (3) to work backward from $q$.

Thus the total number of possible ways to choose two intermediate values as "endpoints" of steps (1) and (3) is like $\log_2(10^{18})^2$ or something. Bruh idk smth like that. It's not too bad.

## 2 Code
Here's the solution code for the problem (compressed):

### 2.1 Solution (C++ 23)
```cpp
/*

    August 31, 2026
    1. Searching for Soulmates (USACO 2022 January Silver)
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll p, q;
    cin >> p >> q;

    vector<ll> fromP, fromQ;
    fromP.push_back(p);

    while (fromP.back() > 1) {
        ll curr = fromP.back();
        if (fromP.back() % 2 == 1) curr++;
        else curr /= 2;
        fromP.push_back(curr);
    }

    fromQ.push_back(q);
    while (fromQ.back() > 1) {
        ll curr = fromQ.back()
        if (curr % 2 == 1) curr--;
        else curr /= 2;
        fromQ.push_back(curr);
    }

    ll answer = 1e17;

    for (ll i = 0; i < fromP.size(); i++) {
        for (ll j = 0; j < fromQ.size(); j++) {
            ll val = fromP[i], val2 = fromQ[j];

            if (val <= val2) {
                ll curr = i + (val2 - val) + j;
                answer = min(curr, answer);
            }
        }
    }
    cout << answer << '\n';
}

int main()
{
    ll n; cin >> n;
    while (n--) solve();
}
```