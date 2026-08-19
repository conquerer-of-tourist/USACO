# D. Solve The Maze (Codeforces Round 648)
Writing Information
* Hengsheng Wang
* August 19, 2026

## Thought Process
Here's what I first went through:
* Initially, when I read the problem, I skipped over some of the most important parts
    * This can lead to some understanding issues
    * For example, is it actually *possible* to pass through a `G` or a `B`
    * And initially, the cell at $(n, m)$ is guarantee to be empty.

Algorithmically speaking, I think I pretty much made the key observation at the start
* The main idea is basically just a greedy constructive algorithm
    * For each `B` cell, we just make sure that it's "encased" on all four sides immediately
    * The intuition I had: if we block other cells, it can also affect `G` cells.
    * Therefore, it's probably better to block `B` cells adjacently

The construction for this initial setup is pretty simple.
* It's just important to make sure we don't make any bad mistakes, such as
    * Messing up `n` and `m`, as well as off-by-one indexing and out-of-bounds control
    * Other key character, such as replacing `-` with `+`

### Implementation Thoughts
This problem is obviously a Depth First Search problem.
* First, I performed a $\mathcal{O}(n \cdot m)$ iteration of every single cell
    * For each Point of Interest (POI), we run a DFS.
    * Here, a POI is just a `G` cell, and we're trying to see if we can reach $(n, m)$.

However, doing this results in an overall time complexity of $\mathcal{O}(n^2 \cdot m^2)$ per test case. Noting that the constraints are $1 \le n, m \le 50$, this seems pretty reasonable.
* Unfortunately, calculating the time complexity while considering that $T \le 100$,
    * This seems to be a bit too slow (TLE on Test #16)
    * So we need to be able to do better.

### Optimization
* Instead of thinking about this problem from the standpoint of each POI, we can work backwards.
* So, we can actually just perform one DFS from $(n, m)$
    * And from this start point, search the grid and count the number of `G` cells we can find
    * If this count matches the total count, we're done.
* This is a much faster approach that takes about $\mathcal{O}(n \cdot m)$ per test.
    * In concept, there is not much difference, but this is much faster and optimized

### Edge Cases
* In this problem, it's also important to consider the edges cases, as this is a floodfill problem and these kinds of things will give you a lot of casework to do.
* There a couple of important ones:
    * If there are ever a pair of `G` and `B` adjacent to each other (this will be covered while we are encasing each `B` cell), we automatically return `no`, since the `B` cell follows whatever path the `A` cell goes through
    * It's also possible that a `B` cell is adjacent to $(n, m)$, so this needs to be covered as well.

## Summary
Overall, the key observation of the problem is just to greedily encase each `B` cell from the start.
* The rest of the solution, while not straightforward, follows pretty intuitively with a bit of thought.


$\square$