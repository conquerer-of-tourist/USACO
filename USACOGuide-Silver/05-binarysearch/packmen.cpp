/*

    August 12, 2026
    hangboy
    E. Packmen - Codeforces Round ACM-ICPC Online Mirror

*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
set<int> packmen;
set<int> eats;

bool check(int mid)
{
    for (auto& eat : eats) {
        auto it = packmen.upper_bound(eat);
        int distNeed = 1e9;
        if (it != packmen.begin()) {
            it--;
            distNeed = abs(eat - *it);
        }
        it++;
        if (it != packmen.end()) {
            distNeed = min(abs(*it - eat), distNeed);
        }
        if (distNeed > mid) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            packmen.insert(i);
        }
        else if (s[i] == '*') {
            eats.insert(i);
        }
    }
    
    int l = 0, r = 1e5;
    int answer = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            answer = mid;
            l = mid - 1;
        }
        else {
            r = mid + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}