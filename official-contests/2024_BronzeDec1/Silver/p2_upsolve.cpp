#include <string>
#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> locations (n);
    for (auto& loc : locations) cin >> loc;

    for (int i = 0; i < k; i++) {
        //
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

// BRAINSTORMING

/*
Sample Input: (looking at test #2)

0            b1
1   t        b1
2   t   a3   b1
3       a3   b1
4   t   a3   b1
5       a3   b1
6   t   a3   b1
7   t   a3   b1
8   t   a3   b1
9       a3   b1
10  t        b1

This gives some sort of prefix sum-like vibes...

(initially a total = 4 + 4 + 4 = 12)
ttt t   tttt  t tt t
3333333333      1111
    22222222
          33333333
~~~~~~~~~~~~~~~~~~~~~~~
t   t   t     t tt  
3333333333      1111
    22222222
          33333333
*/