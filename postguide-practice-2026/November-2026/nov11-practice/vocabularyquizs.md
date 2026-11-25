# Vocabulary Quiz `2025 Silver Feb. P2`

## General Information
* Written on November 11, 2026
* 7:36 PM PST - Hengsheng Wang

## Comprehension, Intuition, and Initial Thoughts
* The problem is worded in a very interesting way;
    * Expecially, for example: ("The words are given in compressed format...")
* The input is sufficient for understanding the problem, but it's still a bit hard to wrap one's head around the topic of the question.

## Main Observations
* Essentially, the words spoken are modelled as a tree.
* By compressing the words down by prefix characters, this helps us to:
    * Construct a tree representing the words.
    * Allows us to search through relationships between words much more easily.

So this would look something like:

$\tiny{\color{lightgreen}\text{[Following Diagram copied via ChatGPT]}}$

```
      root        children = 2
      /  \
     c    d       children[c] = 1
     |    |
     a    o       children[a] = 1
     |    |
     r    g
    car  dog
```

## Implementation Details
Yeah so the implementation follows.