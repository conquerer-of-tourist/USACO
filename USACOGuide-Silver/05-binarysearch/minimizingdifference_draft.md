# Minimizing Difference | Codeforces
Updated on `August 12th, 2026`

## Brainstorming for the Checking Function
Okay, so suppose we take an example, like $1, 1, 1, 1, 4, 5, 5, 7, 10$.
* Our input parameters are just:
    * the sorted list of values (above)
    * the amount we want to squeeze by (the range of the final list)
* So we're going to put these values into some data structure, storing:
    * The value
    * The number of times it appears

## Sample Test Case
So using our example, we have: $1, 1, 1, 1, 4, 5, 5, 7, 10$.
* Let's just say that we want to reduce the range to $4$ or something.
* So right now, the set is:

```
Occurence Set

 {  1:  4 occurence,
    4:  1 occurence,
    5:  2 occurence,
    7:  1 occurence,
    10: 1 occurence  }
```

If we wanted to squeeze the range by $1$ from:
* The left side: the cost is $4$.
* The right side: cost is $1$.

So it's definitely optimal to squeeze from the right side. Let's look at this iteration:
* Okay, look: our largest value is $10$, and we only have one
* The second-largest value is $7$.
* This means we can use $10 - 7 = 3$ operations.

Our new set becomes:

```
Occurence Set           (Usage: 3)

 {  1:  4 occurence,
    4:  1 occurence,
    5:  2 occurence,
    7:  2 occurence  }
```

Okay, now it's onto our second iteration. Now, we still have two operations:
* Use $4$ cost to increase by $1$
* Or use $2$ cost to decrease by $1$
* So obviously decreasing the right side here is still the optimal choice*

(**Interesting Thought:**)
1. If both sides (L and R) have the same number of values, which one do we choose?
2. Furthermore, if cost is same and incre/decrement are also the same, which one?

So there seems to be a little flaw in the greedy approach; though maybe we can also dismiss this.

Like, suppose we have $1, 1, 1, 2, 2, 2, 8, 9, 9, 9$
* Here, left side has `cost = 3` and `difference = 1`
* The right side has `cost = 3` and `difference = 1`

However, if we just go straight to the $8$, we end up with $4$ of them;
* Otherwise, going to the $2$ will give us $6$ of them... Interesting.