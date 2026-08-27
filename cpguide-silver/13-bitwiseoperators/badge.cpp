/*

    August 26, 2026
    Codeforces Round 503 (Division 2) - B. Badge
    Hengsheng W.

*/

#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> successors (n);
    for (auto& successor : successors) {
        int a; cin >> a;
        successor = a - 1;
    }
}