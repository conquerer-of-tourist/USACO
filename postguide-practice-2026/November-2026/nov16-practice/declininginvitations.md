# Declining Invitations

This is from the 2026 USACO Second Contest.

## General

Information
* November 17th, 2026
* Today is the end of the Discussion Ban for the 2026 AMC 10B!
    * Solutions came out on AoPS!
    * It seems like I did in fact answer all the questions that I did correct, but of course, I got question 3 wrong.
    * Problem 9 was a misunderstanding, which is why I kept on getting 21 instead of 22, and Problem 25 was misread to be $30-60-90$ triangle in reality, but I read it to be a $1-2-\sqrt{5}$ triangle.
    * Whatever.

## Thought Process

So, I first started working on this problem on November 16th (Monday), but I didn't make much progress outside of getting a grasp of what the problem is saying. I think that this time, I was actually quite stuck and had absolutely no idea what to do.

So yeah, there's not much of a thought process here.

## Solution

### Main Idea

Here's the key idea that I was given:
* Right now, we're trying to solve a problem by steadily getting rid of participants and seeing what happens to the rest of them, right?
    * This seems like a really complicated and hard thing to do, especially since $N$ can be quite large (up to $10^5$, and there can also be up to $C \le 10^5$ criterion)
    * This implies that maybe instead of working forward in the way the problem intended, we can work backwards.
* Essentially, since we know that at the very end, there will only be one contestant remaining to get placed in the final round, we can actually begin our implementation there, and work backwards from the permutation to slowly construct the final rankings one by one until we reach the full permutation.

### Construction to Implement the Main Idea

Let's take a look at what it would mean for us to put a criterion in a thingie. Wait, I mean liek... Okay, it's 10:00, I'm kind of tired. Let's take a look at what it would mean for us to put a contestant back into the final round.

Since any contestant will be placed the highest by the best-ranking criterion that they satisfy, we can essentially look at the highest criterion that a certain contestant satisfies, and work our way down to lower satisfied criterion.
* So suppose that the $n - 1$th cow in the permutation qualifies for Criterion $k$, where $k$ is like the lowest criterion value (a better one, because lower is better) that this cow satisfies.
* If the $f_k$ for this criterion is not fully filled (there is still room to spare), we can put the cow in, and add to our **sum of ranks**.
    * However, if the criterion is *not* available for seats, we can take a look at the rankings of this cow compared to the worst-ranking cow in the currently filled criterion thingie.
    * If that cow ranks worse than we do, we can steal the spot, because our original cow was better than the other one. Then, that cow is displaced and their placing will propogate downward. (This implementation is not too bad)
    * However, if that cow ranks better than *we* do, then we have to continue down the chain of criterion for our own cow.

Okay so yeah, that's the main point. **The main takeaway** is probably just that it's important to not just consider the problem from the perspective of working forwards, but also think about what it would mean to construct the output the other way around. That makes construction a lot easier.

Nice. $\square \texttt{ 11-17-2026}$