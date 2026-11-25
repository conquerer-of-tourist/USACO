# Bovine Acrobatics (2023 Dec. Silver #1)
## Information
* Written on Novemeber 10th, 2026
* Tuesday night before Veteran's Day
* Right before the AMC 10B. 10A seems to be 118.5; not confirmed.

## Thought Process
Before I asked for help, the main ideas I had included:
* The key greedy idea that a tower with as many cows as possible is better.
* (This is because it uses the limited number of towers; more efficiently)
* I wanted to do a binary search on answer for the number of cows.

## Actual Solution
* First, we can suppose that we actually have $M$ base towers.
* Storing each tower as part of a pair:
    * `.first` represents the weight of the top cow.
    * `.second` is the number of these towers.
* For a clean implementation:
    * We can iterate from heaviest to lowest.
    * The idea is to build towers from the bottom-up.
    * Obviously, heavier towers belong at the bottom, so we consider them first.
* Then, notice that a queue suffices to solve the problem.
* Each time, we do a bit of tiny casework to solve the scenario.
* We can set the current cow as the new top of *some* towers.

That's pretty much it. The actual implementation follow nicely.

A couple of important things to consider:
1. You can use a `while` loop when the current cow has not been completely exhausted by the available towers.
2. We can completely ignore cows that cannot be placed on the tower with the heaviest base; as it's not going to work for anything else, either.
3. You have to be a bit careful when making sure that the queue of towers is not empty.