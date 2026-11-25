# Thought Process
## Initial Thoughts + Brainstorming
October 12, 2026: 9:30 PM

### Thought Process
---------------- 9:07 PM ----------------

SAMPLE TESTS

```cpp
5 1
10011
```

* RI: Parity of number of 1's in Length-K window.
* Informally.
    * From $i$ to $(i + k - 1)$, basically the next k values including index i
    * Take the number of $1$'s; and find the parity of this value.

So in the sample, `10011` $\Rightarrow$ basically the number is fixed??

So uh, we have the minimum and maximum values...

Oh wait, we're looking for the min/max number of one's not the value itself.
So, we can make a `vec<bool>`; and then it has a size $n$. So we can run a prefix on it or something.

Right, so let's look at the second sample test case:
```
5 2 
1001
```

So: 
* Among the first two, there are odd # of 1's, so 10XXX or 01XXX
    * Among the second two, even number of 1's, so X11XX or X00XX
    * Among third pair: even number of 1's so XX11X or XX00X
    * Last pair: odd number of 1's so XXX10 or XXX01??

1) minimal construction: `10001? - 2` (correct)
2) maximal construction: `01110? - 3` (correct)

Wait that's weird, because the whole thing gets inverted.
Maybe this is just a special case..

Okay so lets just hypothetically suppose that we like, ran a prefix.. Uhh.. On the parity of the array's 1-count. So uh, it would just be filled with ones and zeroes

so we could do something depending on the parity of the first index
take the second sample as our current thingie

1) the first value is a 1.

parity[0] = 1;
parity[1] = (we know that here, it's guaranteed to be like odd)
-> so this forces our next value?


parity[0] = 0.

OHHH so we could like do a bits thing on determining the first K bits
and then after that O(n) the rest

so the complexity would be O(2^k * n)
which is not very efficient..
do they have subtasks??

LOL so they have one subtask for N \le 8, which I guess is okay
but that's like 1/10th of the test cases so we better not do that

okay let's take a look at what the third test case can tell us
"100" for "5, 3"

so we could greedy choose 111 for the first three, and then uh
11101
111
 110
  101

yeah so four works, and then we have the opposite:

10000
100
 000
  000

which also works, so this gives us 4 and 1

so yeah lowk maybe this is the strategy here.
basically something like:
1. to maximize, fill up everything until you can no longer fill anything else
2. to minimize, only fill the first index with a one
    > and then you bash out the rest of it with a sliding window or something idk

AAHAHAHAHAHA wait maybe this works idk
the next could test cases are kinda weird..
okay:
5 5 0

so we could uh
do a greeedy alg like
something like 11110, and that would work perfectly fine; so max at 4
and then to minimize, just make something like uh
so err
yea like 00000, and this also works
so this also gives us the correct answer

and then for 4 4 1:
min 1000
max 1111

WAIT i think this works...
cannot figure. out a proof though...
yeah this could actually be an issue

test case
wait last one
yay

wait no  5 5 1 should be 1, 5
yeah it is okay good

5 2 
0000??????

okay well we can try out the greedy idea here...
lets see

greedy:
11111??
11, etc.
so this does indeed work

and if you don't use this greedy, it doesn't give the same answer

so wait yeah this might just be the answer!
bruh i cant prove it
i swear if i end up like taking 30 minutes to implement this,
and if it doesnt end up being the correct solution......

"sigh" 
q.e.d. \square

Then, I used an LLM to debunk my theorems.


## After Help
After utilizing an LLM (ChatGPT-5 High) to give me the key intuition, these are the main parts that I thought about again:

## After Finished Solution