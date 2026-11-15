# Cow-Libi 2

November 15, 2026 (Hengsheng W.)
* Solve Time: 1 hour 51 minutes

## Thought Process

Since I've done this problem before, even though I don't remember the solution itself, I was primed to basically walk in the direction for the correct solution. I did remember vaguely watching Errichto's YouTube solution via X-Camp's channel and applying this exact logic on the BAMO 2026 Problem 5 for 8th Grade and under.

Okay, so the essential idea is that we can look at the relationships between any two cows. If the two cows, in reality, have the same owner, they will say "J" to each other. However, if they are not belonging to the same owner, then they will say "N" to each other.

* `JJ` says "J", because they don't lie.
* `NN` says "N", because they lie.
* `NJ` (from the left to right), they lie, so they say "N"
* `JN` (from the left to right), truthfully, they are "N"

From this, we've basically solved the important half of the problem. Now, it remains to solve the subtask of $C = 0$. There are just two main important observations to make:
* If we start at cow of Type X, after completing a whole cycle, we end up at Type X again, which means that there has to be an even number of $N$ occurences (representing a change) on both top layer and bottom.
* There has to be a same number of "NJ" and "JN" pairs; and there is a bit other stuff to deal with as well.

Then, the construction of the actual solution for cases $C = 1$ follows. It just takes a bit of careful indexing and planning, not too much else.

$\square$