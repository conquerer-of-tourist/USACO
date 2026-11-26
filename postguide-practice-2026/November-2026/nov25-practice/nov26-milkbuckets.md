# Milk Buckets (2026 3rd Contest - Silver P2)

## General Information
- Written at `11:40` PM on `Nov 26 2026` by Hengsheng Wang
- Spent at least six hours working on this single problem, mainly due to Segment Tree issues.

## Initial Thoughts and Process

Because of the way the problem is phrased, it takes a little bit of time to actually start thinking about how the input will work in what way the indexing the works. Especially when you're dealing with the input, there can be a lot of off-by-one issues in the indexing, but as we gradually work through testing out the input, it gets a lot better. 

The main observation is that the period, or interval over which the first bucket begins refilling for a new final product to be poured into the pool is:
$$\texttt{period } = \displaystyle \left(\prod_{i = 1}^{n - 1} \left\lceil \dfrac{a_i}{a_{i - 1}}\right\rceil \cdot (a_0 + 1) \right).$$

From here, we can continue roughly with the code in `milkbuckets_regular.cpp`. However, it turns out that this will only be able to get the three samples and none of the real test cases.

There's nothing wrong with the time complexity; it's around $O(N)$, and there is technically no algorithmic or logical issue. It's about the boudns on the numbers.

## Segment Tree Implementation and Solution

So, it turns out that we actually need to implement **Segment Tree** to solve this problem, and even though it classified in USACO Guide as a Gold Topic, these more advanced topics are starting to sift into the lower levels.

The main idea is to keep a pair-product segment binary tree of the ceiling values, and an upper bound of $10^{18} + 1$.

I'm too lazy to explain the rest. Man, it's just Segment Tree. If I try explaining it, then it's just larp. Whatver. $\square$