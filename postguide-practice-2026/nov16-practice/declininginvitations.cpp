/*

    Hengsheng Wang

    Problem 2. Declining Invitations
    USACO 2026 Second Contest - Silver

    November 16, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;

    vector<int> f (c);
    for (auto& F : f) cin >> F;

    vector<int> p (n);
    for (auto& P : p) cin >> P;

    for (int i = 0; i < n; i++){
        int n_i;
        cin >> n_i;
        for (int j = 0; j < n_i; j++) {
            //
        }
    }
}

/*

for example if we're given the input

5 1
3
5 1 4 3 2
1 1 ... (x5)

SOLUTION VIA BRUTE FORCE
==============================
- Storage of:
    * Conditions
        * Maybe like a vector 

*/