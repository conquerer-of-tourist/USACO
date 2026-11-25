# January 2026 Upsolves
## Main Information
These are the problems from the January 2026 Silver contest.
* Date: January 9th, 2026
* Upsolving Dates: January 20-28, 2026
## Problem 1
Problem 1 is all about realizing the main pattern:
* You can have a cow, and if you trace backwards you can essentially do a $\log n$ time sol.
* Just make sure to stay careful about indexing, that's about it.
## Problem 2
This is a connected components graph problem, where:
* Individual rod values represent components represent nodes.
* Any relationships between a pair of rod values is equivalently an edge
* Using these relationships you can iterate (like stack DFS) through connected components
* Using this information, solving the problem is simply about indexing and staying careful.
## Problem 3
Problem 3 is essentially another connected components question
* You have the make the key observation that for the string $b_1 b_2 \cdots b_n$
* And for the string $b_2 b_3 \cdots b_{n + 1}$
* The overlap is discounted, and then you have $b_1$ and $b_{n + 1}$ (let $n = k$ here)
    * Using this information you can make connected components with intervals of $k$
    * Finally, remember to double check the parity counts for the first $k$-subarray at the end