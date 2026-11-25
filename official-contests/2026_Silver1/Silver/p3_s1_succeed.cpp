#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    int init = 0;

    int minimumSum = 0;
    int minDiff = INT_MAX;

    for (int i = 0; i < k; i++) {
        vector<int> curChain;
        curChain.push_back(0);

        for (int j = i + k; j < n; j += k) {
            int previous = curChain.back();

            int a = str[j - k] - '0';
            int b = str[j - k + 1] - '0';
            
            if (a == b) {
                curChain.push_back(previous);
            }
            else {
                curChain.push_back(1 - previous);
            }
        }
        int st0 = 0;
        for (int x : curChain) {
            st0 += x;
        }
        int st1 = (int) curChain.size() - st0;
        
        minimumSum += min(st0, st1);
        minDiff = min(minDiff, max(st0, st1) - min(st0, st1));

        if (min(st0, st1) == st1) {
            init++;
        }
    }
    int minAnswer = minimumSum;
    int maxAnswer = n - minimumSum;
    
    int r1 = str[0] - '0';
    if (init % 2 != r1) {
        minAnswer += minDiff;
    }

    if ((k - init) % 2 != r1) {
        maxAnswer -= minDiff;
    }

    cout << minAnswer << " " << maxAnswer << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*

BRAINSTORMING SAMPLE TEST CASES

So we know there is a binary string b1 b2 .. bn

and you know that for r1 r2 r3 .. r(n - k + 1)

that ri is whether # of 1s is even or odd
in the next substring thing


===== TEST CASE #1 =====

We are given the value of:
n = 5.
k = 1.

Therefore every r_i corresponds to the exact same b_i.

So the only possible binary string is 10011 (given in the input).


===== TEST CASE #2 =====

We are given the values:
n = 5;
k = 2.

And the input string is 1001

So let the values be abcde

In "ab" there is an odd # of ones
In "bc" there is an even # of ones

So in "ab" there is exactly 1 one.

-> If it occurs at "a", then
---> The new string is "10cde"
---> Therefore "100de"
---> Therefore "10001"
Substrings:     10
                 00
                  00
                   01
So this matches 1001.'

-> If it doesn't occur at a, must occur at b.
---> New string is "01cde"
---> Therefore, "011de"
---> Therefore, "0111e"
---> Therefore, "01110"
Substrings:
                 01
                  11
                   11
                    10
This also matches 1001, and both possibilities are finished.

so the possible values are 2 and 3, so we output this

*/