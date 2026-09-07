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

Everything afterward follows pretty nicely.