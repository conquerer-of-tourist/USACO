# Potion Farming (Silver, Jan. 2024)

## Information
* Hengsheng Wang
* October 28, 2026

## Thought Process
* Overall, it's immediate that the problem relates to graphs.
* So, we can define an adjacency list as usual.

## Continued: Solution Implementation
* First, notice that the number of traversals we can have is just the # of leaf nodes.
* Thus, we can compute $L$, and then only consider the first $L$ potion locations.
* It follows that we can perform the following subtask for each subtree:
    * Base Case: If the subtree is a leaf, our answer is $1$. We also pass up the number of leaves in the subtree.
    * Otherwise, we can utilize information from the children nodes to determine the answer for the current stage.

Yeah it's a bit rushed, but this is the gist of the solution.