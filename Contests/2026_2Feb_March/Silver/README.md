# ReadME

## Basic Information: February Contest 2
USACO Silver contest taken live, February 2026!
* Contestant: Hengsheng Wang
* Division: USACO Silver
* Date: February 21st, 2026
* Time: Starting at approximately 1:00 PM

## Problems
Here are the links to the problems!
* [Problem 1: *Clash!*](https://usaco.org/index.php?page=viewproblem2&cpid=11)
    * FJ has $N$ cards; $K$ of them are special.
    * FJ has a hand of $h$ cards; the rest go in the draw pile with the same order.
    * FJ can play a card $i$ after $a_i$ seconds.
    * If FJ is in possession of a special card, he must play that card ASAP.
    * After $t$ seconds, how many times will FJ has played a special card?
* [Problem 2: *Milk Buckets*](https://usaco.org/index.php?page=viewproblem2&cpid=11)
    * There are $n$ buckets.
    * Every second, a dispenser on the ceiling dumps 1 gallon of milk down.
    * If a bucket reaches full capacity, it will flip over and dump into whatever is below.
    * Any milk that isn't contained properly is lost.
    * A bucket cannot recieve milk when it is flipped over.
    * How much milk will be in the pool at the bottom after $t$ seconds?
* [Problem 3: *Point Elimination*](https://usaco.org/index.php?page=viewproblem2&cpid=11)
    * You are given a list of coordinates in the plane
    * You must determine if, with the following two operations:
        1) Delete two adjacent points where $\overline{AB} = 1$, or...
        2) Swap the $y$-coordinates of two points
    * ... it is possible to end up with zero points at the end.

Yipee!

## IN-Contest Statistics

### Problem 1
I figured out the main observations of Problem 1, mainly via the last part of the sample test.
$$142857...143 \approx \dfrac{1000...000}{7}$$
And after analyzing the numbers we were given, it seems to be that you can play special cards consistently. Thus, the $1/7$ fraction just represents, on average, the number of special cards that we can play after waiting $t$ time.

There are two special cards, and outside of the largest two (6 and 7), the sum is $14$. That essentially concludes the main observation.

### Problem 2
Nah. (I didn't even attempt this question in the first two hours)


### Problem 3
Oh, it's an interesting coordinate problem. This is genuinely intruiging! Bye!!! (I didn't attempt this question in the first two hours either)