# Visits
## General Info
* November 11, 2026
* Veteran's Day - Wednesday and No School (Break)

## General Solution Idea

Intuition and Observations
* We can actually set our answer as the total number of moo's.
* Then, we can optimally remove whatever moo's we can.
* Furthermore, the problem is a functional graph, since each node has one out-edge.

Solution
* Our whole algorithm should be something like $\mathcal{O}(n)$.
* For each node, if we haven't visited it yet:
    * We can create a path starting from this node until we complete a cycle.
    * Once we finish cycling, we can see which node to sacrifice is the most optimal.