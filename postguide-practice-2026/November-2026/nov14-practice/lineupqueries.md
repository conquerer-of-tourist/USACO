# Lineup Queries
## Initial Thoughts
I've solved this official contest problem before with AI, but this time doing it again, I didn't remember the solution; hence it may be a good idea to write a solution this time.

My first thoughts were important but nowhere close to enough to solve the problem. They revolved around the lines of, if the first variable (`c` or `t`) is more than half of the current time $t$, then the problem is basically just solved.

In terms of actually solving the problem, I didn't do what I did the last I solved it during the contest (which was to list out larger values of t). Maybe the large bounds on $t$ were a little scary.

## Actual Implementation and Solution
And so unfortunately, inconsiderately, the five star hotel leads to ChatGPT 6.1 Max, again. We can split the problem into two subproblems: dealing with Types 1 and 2.

### Type 1 Solution

The key observation is that we can find the first time the given cow $c$ reaches position $0$, and afterward, we can easily compute the next time that the cow reaches position $0$ again. Every single time, the time that this occurs scales by a factor of approximately of $1.5$.

This is not equal to $2$, but it is logarithmic nevertheless, which is sufficient to solve the problem for $t \le 10^{18}$. The actual equation and solution follow very quickly.

### Type 2 Solution

This is almost the same idea a Type 1; it's a logarithmic solution that works backwards instead of forward. Suppose that we're given a position $p$ and time $t$. Then, let $k$ be a safe but substantial value representing the amount of time $t$ we can jump backward from here.

Fuck... Oh yeah, I remember now.

Okay, so notice that the state of our cow cannot be $p \ge 2t$, or (something along that line), because otherwise we would have the cow being in an impossible range. So this means that we can set an equation regarding $k$. The equation looks something like:

$$k \le \left\lfloor \dfrac{p - 2n}{3} \right\rfloor$$

I cannot rememeber the details. That will be left as an exercise to whoever is reading this. Okay, then, because $k$ could be $0$, we could take smaller steps as we get closer to the transition between the points $(0, s)$ and $(\approx s/2, s + 1)$. This solution is also equivalently logarithmic, I believe.