# Farmer John Loves Rotations

## Recap and Thought Process

So while solving this problem, I had a couple of initial intuitons, but none of it was really enough for me to actually start implementing the solution. The things that I considered included:
* Changing the array from size `n` to size `2 * n`, because this would help us deal with the rotations a bit more.
* It's optimal, given a starting point, to minimize the number of turns they make in order to reach all distinct values (e.g. you change directions at most once)
    * This means that if you are at the edge of a short, contiguous interval with all of the values, you just go straight to the other end.
    * Otherwise, if some point is in the middle of an interval, we choose the side that takes shorter time to reach, and then we go all the way to the other side.
* Answers whose indices are separated by one can differ by at most one, but I did not find a good proof for this.

## Actual Solution, Implementation, etc.

So the observations I made were indeed somewhat the main line of reasoning; it was all just a little disconnected.

We can first count the number of distinct values with a single iteration, right after the input. Then, we can iterate from left to right with a sliding window. The leftmost index represents the left end of an interval, and we're computing the `rEnd[left index]`, which essentially represents the closest rightmost index that could close the interval and include all distinct values.

Then, we can compute the answer under the assumption that our nodes will start and then endpoint of some interval. Afterward, we can use optimization via a difference of at most $1$ (the observation made earlier) to propogate back and forth throughout the array and finish our result.

$\square$ (It's not a formal proof at all, but this is just the rough progress I made to get to the solution. Was in fact solved with the help of AI, again :sweat-smile: )