# Sliding Window Summation (SWS)

## Initial Thoughts

So I have solved this problem with AI before, twice. I think that this time, I looked at the problem, and the key intuition came pretty quickly, and this is probably because I've done it before, so I have been primed to do this exact problem.

Anyway, the idea is that we if we take the XOR of any $k$ consecutive terms and the $XOR$ of the $k$ consecutive terms that are shifted in the right direction by $1$, we end up with the relationship:

$$r(1) \oplus r(2) = b(1) \oplus b(1 + k).$$

Hence, values that are separated by $k$ are only dependent on each other in the final result. We know what $r(1)$, $r(2)$, and $b(1)$ (we can initialize this to a fixed value at first) are, so this will allow us to find $b(1 + k)$.

## Thinking Process (During Solving)

As of writing, I am also trying to solve the problem.