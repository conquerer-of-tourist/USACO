# Switching on the Lights

Information
* Hengsheng Wang
* October 10th, 2026

## Reflection
### Thought Process
Because of the way the problem is formatted, it is obvious that the implementation utilizes Floodfill. I first used Depth First Search.

### First Implementation
First, we can observe that masking a coordinate can be done with an integer $1000 \cdot a + b$, because all coordinates are in the range $[2, 100]$. 

From here, my code used three main data structures: an $n \times n$ grid that would represent the final barn (where a $1$ represents that the room has a light), an $n \times n$ visited array, and a `map<int, vec<int>>` called `adj`.

The idea here is to avoid using pairs of integers by using the masking technique above.

Then, I performed a regular DFS, following the steps:

1. Mark all of the connected rooms as lit up via the map `adj`.
2. Visit all of the adjacent rooms.

However, there is an important issue here. Suppose that we are at room $C$, and we light up Room $D$. If we have visited a Room $A$ such that $A$ and $D$ are adjacent to each other, and $D$ is not adjacent to $C$, Bessie doesn't recognize that she is now able to travel down the path, through $D$, to other adjacent cells.

As a result, whenever we light up a room, we check whether one of its neighbors has been visited before. If it's been visited before, we can "traverse backward" to that node we've seen before, and continue down that path.

This comes in the shape of simply doing another DFS from that location.

In the DFS Impelemntation I had earlier, this part was:

```c++
    for (auto& k : adj[1000 * a + b]) {
        grid[k / 1000][k % 1000] = 1;

        if ((k / 1000 > 0 && visited[k / 1000 - 1][k % 1000] == 1) ||
            (k % 1000 > 0 && visited[k / 1000][k % 1000 - 1] == 1) ||
            (k / 1000 < n - 1 && visited[k / 1000 + 1][k % 1000] == 1) ||
            (k % 1000 < n - 1 && visited[k / 1000][k % 1000 + 1] == 1)) {
            visited[k / 1000][k % 1000] = 1;
            dfs(grid, visited, k / 1000, k % 1000, adj);
        }
    }
```

Running the overall program with this, however, only gives three test cases out of all fifteen (that is, one sample test, along with two legitimate tests, numbered 2 and 3).

The other cases will go through the `!` verdict, and that is because if we have visited such node before, we continue to visit it.

As a result, this one-line change will change the verdict to AC:

```cpp
... grid[k / 1000][k % 1000] = 1;

if (visited[k / 1000][k % 1000] == 1) {
    continue;
}

...
```

This prevents us from looking at a room that we "thought we toggled" but had already been "lit up" before; so could possibly prevent an infinite loop or something.