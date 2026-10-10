# USAMTS Year 38 Round 1
Information
* Written by Hengsheng Wang
* Created on October 9th, 2026
## Probem 1
### Prechecks
Create a $5 \times 5$ matrix to represent the entire grid.

### Row-Wise Checks
* First, make sure that the units digits add up to the corresponding value.
* Then, ensure that
    1. Any prime square is a prime value.
    2. For the non-prime squares, ensure that it isn't prime.
* If our list passes these checks, add it to an array of length-`8` permutations;
    1. This long list should correspond to that row.

### Nested Iteration
Iterate through each:
* 1st, 3rd, 4th row combination.
    * Construct the $5 \times 5$ matrix.
    * Take all of the distinct values, and put them in a set.
        * If the number of values in this set is not $25$, we can continue to the next iteration.
    * Otherwise, now check, for each column:
        * Create a set of its values' digits.
        * Compute the units digit of the sum valuation.
    * If the sum doesn't match or the size of the set is not ten, continue to the next iteration.
    * Note that all primality checks have been covered in the first step (row-wise eliminations)