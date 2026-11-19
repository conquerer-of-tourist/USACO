# Coach Note: Declining Invitations and Clash!

- Review date: November 18, 2026
- Student: Hengsheng Wang
- Practice dates: November 16–18, 2026
- Document type: Coach assessment of practice and learning
- Repository snapshot reviewed: `1c49b74cd73848c4b151fda3f44f156953c9ff04`

## Main assessment

Both problems should be recorded as **assisted completions**. Hengsheng showed substantially more independent initial insight in Clash! than in Declining Invitations.

The final implementations passed independent local checks. The conversations show that ChatGPT contributed key algorithmic steps, implementation structure, and debugging fixes. Independent mastery should be checked through a later explanation and rewrite without the chats or old code.

## Evidence reviewed

- Declining Invitations: [code](../postguide-practice-2026/nov16-practice/declininginvitations.cpp) and [student notes](../postguide-practice-2026/nov16-practice/declininginvitations.md).
- Clash!: [code](../postguide-practice-2026/nov18-practice/clash.cpp) and [student notes](../postguide-practice-2026/nov18-practice/clash.md).
- ChatGPT conversation: [Reverse Processing Hint](https://chatgpt.com/c/6afd2b54-9dd4-83e8-88fb-83d558f2ceb1).
- ChatGPT conversation: [USACO Strategy Observations](https://chatgpt.com/c/6afe6f09-5b40-83e8-ad86-ea2b532b35d7).
- The earlier Clash! contest attempts in [the February contest directory](../official-contests/2026_2Feb_March/Silver).

The judgments below concern the work visible in these records. An idea appearing before a hint in one conversation does not establish that the student had never encountered it previously.

## Attribution of the solution

| Problem | Hengsheng's contribution visible in the conversation | Assistance supplied by ChatGPT |
|---|---|---|
| **Clash!** | Before substantive guidance, he proposed maintaining the hand and draw queue, choosing the cheapest eligible card, retaining expensive cards, and exploiting an eventual repeating cycle. He then discussed cycle cost and refined which cards should be retained. | Identified the exact `N-H+1` repeating structure and explained it; supplied a concrete min-heap simulation plan, full-cycle/remainder query formulas and code, and fixes for prefix indexing, output formatting, and priority-queue template arguments. |
| **Declining Invitations** | After receiving the reversal hint, he described cascading displacement. He suggested `upper_bound` on each contestant's eligible criteria and recognized that displaced contestants move only toward later criteria. | Introduced reverse processing; specified the state to maintain per criterion and the insertion-function structure; clarified displacement versus rejection; supplied rank-sum updates and corrections to indexing and missing branches. |

The assistance went beyond a single small hint. Hengsheng also made substantive contributions and revised his own drafts between responses. These records support credit for both his initial reasoning and his ability to implement with guidance.

## What improved

### 1. Clash! began with meaningful structural observations

Hengsheng identified the greedy choice and the idea of keeping some cards while circulating the others before ChatGPT's substantive response. This is stronger evidence of independent problem solving than the final code alone provides.

His question, “Why N - H + 1?”, also shows that he sought an explanation for the cycle length rather than only accepting a formula.

### 2. The implementation now handles the entire query

The new Clash! code handles both complete cycles and the remaining budget. The February attempt mainly counted complete cycles. This closes an important gap between an approximate observation and a general solution.

The conversation shows that ChatGPT supplied the query formulas and code, so this improvement is evidence of successful assisted implementation. Retention remains to be checked.

### 3. He can carry a multi-step algorithm through to working code

Declining Invitations now combines reverse processing, per-criterion heaps, eligibility searches, displacement chains, and a running sum. Clash! combines greedy simulation, cycle preprocessing, prefix sums, and binary search.

## Main weaknesses to address

### 1. Precise meanings of state and variables

In a Declining Invitations draft, `total` was not increased when a contestant actually received an empty seat, but was increased when a rejected contestant merely continued searching.

The underlying invariant should be explicit:

> `total` equals the sum of the ranks of all contestants currently invited.

Each branch should be checked against the actual change in that set.

In Clash!, the elapsed-cost prefix array and win-count prefix array initially used different indexing conventions. A consistent definition would be:

- `firstCycle[i]`: cost of the first `i` plays.
- `prefixWC[i]`: number of win-condition plays among the first `i` plays.
- Both arrays begin with the empty prefix at index `0`.

### 2. Connecting observations into an executable algorithm

Clash! shows useful initial intuition, followed by repeated requests for the next implementation step. Declining Invitations required the main reversal idea and a detailed insertion outline.

The next skill to practice is writing a short, complete plan before coding: state, transition cases, query calculation, and complexity.

### 3. Independent verification and proof

ChatGPT caught issues that small hand traces or compilation could reveal: incorrect sum updates, inconsistent prefix indexing, and reversed priority-queue template arguments.

A stronger practice routine would include one hand-traced example and a compile/run check before requesting the next hint. The explanation should also cover why the process preserves the intended state and why the total work is bounded.

## Verification performed in this review

| Implementation | Independent local check | Result |
|---|---|---|
| Declining Invitations | 800 random small inputs compared with direct recomputation of the invitation process | All matched |
| Declining Invitations | A 100,000-contestant displacement chain | Completed with the expected answers in the local test environment |
| Clash! | 240 small games, totaling 8,400 query answers, compared with exhaustive search over legal card choices | All matched |
| Clash! | A maximum-size case with `N=Q=200,000` and independently calculable answers | Passed |

The Declining Invitations commit message reports AC. Official judge results were not independently verified. The local tests support correctness on the tested cases, rather than establishing independent understanding or a proof for every valid input.

## Next coaching checkpoint

After approximately two days, ask Hengsheng to work without the chats or old code.

### Clash!

1. Explain the priority order, including the case where there are fewer than `H-1` ordinary cards.
2. Explain why the play sequence repeats with length `N-H+1`.
3. Define both prefix arrays precisely.
4. Implement the query calculation and test zero remaining budget, an exact prefix-cost boundary, and an exact whole-cycle boundary.

### Declining Invitations

1. Explain what state the reverse process represents after each insertion.
2. Explain why a displaced contestant searches only later eligible criteria.
3. List the three insertion outcomes: empty slot, replacement, and rejection.
4. State exactly how each outcome changes `total`, then implement the insertion logic.
5. Explain how monotone movement through eligible criteria bounds the total work.

Record the follow-up as **independently explained**, **independently rewritten**, or **still needs a specific hint**, with the hint described.

## Coaching conclusion

The latest work shows progress in structural reasoning and in completing multi-stage implementations with guidance. The immediate priority is to make state definitions, proof, and independent reconstruction more reliable.

Do not use the other AI's “70–75% solved” estimate as a mastery score; it has no objective measurement basis. Use the later explanation, rewrite, and test results as the evidence.
