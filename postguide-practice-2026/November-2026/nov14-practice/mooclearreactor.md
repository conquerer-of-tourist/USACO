# Mooclear Reactor
## Initial Thoughts
I kind of got stuck again at first, mainly because I did not make the key observation.

I actually watched Errichto's video on X-Camp's YT Channel on this before, so I don't know how I didn't realize what the solution was supposed to be.

## Actual Solution and Thoughts + Observations

### Observations

Notice that the $M$ lines that we are given each relate two cows $x$ and $y$. This suggests that the problem can be represented with a graph!

### Solution Ideas

Since we don't actually know what to initiate the variables at with a concrete value, we could literally just set a variable to the value $X$, which we do not initially know. After that, the idea is use each edge to deduce information about the expressions representing the values of the other nodes in the same connected component as the current node with value $X$.

By using this information, we can get a forced X, a contradiction, or an unchecked bound (where X is still not determined).

### Implementation Details

We can use an adjacency list of pairs of integers to store the edge relationships. Iterating through each individual connected component, we can find the optimal $X$ with the first node we have in this CC.

The rest of the solution follows very nicely with three cases; we either reach a contradiction where no $X$ works (meaning that the answer is $-1$), we have a fixed $X$ value and we need to check which rods can work, and when we have a range of $X$ values that work, in which case we slightly shift our $[L, R]$ bounds to accomodate this.

A sliding window suffices for the rest of the solution, and we're done. $\square$

(Ultimately, this problem is a very nice blend of graph theory and with a bit of sliding window/sweep line techniques.)