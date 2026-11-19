# Clash!

## General Information

USACO 2026 Third Contest
* Late February, 2026
* Problem 1. Clash

Date of Solve: November 18, 2026

## Recap of the Problem Statement

I'm actually quite proud of what I was able to find from my initial observations before looking at ChatGPT's solution. Let's first take a look at a summary of the problem.

In the problem, we're given $N$ cards, each with value $a_i$. The first $H$ cards belong in our hand, and the rest of them go into the draw queue, which maintains the same order we were given in the input.

Next, there are $k$ win-conditions; if our hand contains a win-condition card (they are referred to by the ID, essentially the index of the card), we must play that card. However, if we have multiple, we can choose which one we output, and if there aren't any, we can play whichever card we want.

Even though it is phrased in a rather complex way in the problem, we can essentially say that the cost it takes to play a card with value $a_i$ is just $a_i$. For $Q$ queries, we want to find the maximum number of win conditions we can play without crossing the limit of the budget we're given (a single integer, which can be up to $10^{18}$).

## The Intuition

This time, we got pretty close to the final solution, and my initial observations were approximately on the right direction; ChatGPT says that the observation was approximately $70$ to $75$ percent of the full conceptual difficulty.

So, what's the idea? Well, since we're trying to maximize the number of win-conditions that we play, we're effectively trying to cycle through the draw pile as quickly as possible. The observation is that it's the most optimal to play the smallest card we have in the hand (unless we have a win-condition, in which we must play the smallest win-condition).

Why?
* Suppose we don't have any win-conditions. Then, all of the other cards that we play are symmetrical in terms of their upcoming situation in the draw queue; however, it will only take a higher cost to play a more costly card. Thus it's better to play a cheaper card.
* If we *do* have win-conditions, playing the cheapest one will help
    1. Get rid of it easily to continue the cycling
    2. We gain another win condition to be played (in our counter)

This is not a rigorous proof, but the main idea should be apparent. This is pretty much as far as I got, but I was still missing three main pieces:
* What if we have fewer $H - 1$ non-WC cards?
* How should we store this information in a data structure?
* What is the main structure of the algorithm supposed to be?

It turns out, the solution answers these questions, and the answers are pretty trivial.

## Solution

Notice that if we simulate the first $N - H + 1$ operations:
1. Store, for each operation, how much time has elapsed in a vector.
2. A prefix sum, for each operation, how many WC's we have placed so far

The $H - 1$ most expensive cards (if they are not WC, or if they are WC, the non-WC card along with the most expensive WC cards) will all be contained in the hand, along with some arbitrary other card that you started with. From here, all of the simulation will be periodic, mainly because the $H - 1$ cards that we retain in the hand and never play will remain constant and not change.

From here, the rest of the logic is not too bad; the information we've gathered thus far is sufficient.

```cpp
    while (q--) {
        ll a;
        cin >> a;

        ll cycleTime = firstCycle[n - h + 1];
        ll cycleWins = prefixWC[n - h + 1];

        ll fullCycles = a / cycleTime;
        ll rem = a % cycleTime;

        int idx = upper_bound(firstCycle.begin(), firstCycle.end(),
                              rem) - firstCycle.begin() - 1;

        cout << fullCycles * cycleWins + prefixWC[idx] << '\n';
    }
```

It's rather self-explanatory once you see the variables and stuff. Okay, goodbye. $\square$

I'm actually finding that writing MD Files for solutions rather than google docs is much easier!