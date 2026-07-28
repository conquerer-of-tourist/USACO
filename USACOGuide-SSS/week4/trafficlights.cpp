/*

    Information
    ======================
    Hengsheng Wang
    Traffic Lights
    CSES Problemset

    Sunday July 26, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int x, n;
    cin >> x >> n;
    set<int> positions;
    positions.insert(0);
    positions.insert(x);

    multiset<int> lengths;
    lengths.insert(x);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        auto it = positions.lower_bound(a);
        int rightBound = *it;
        it--;
        int leftBound = *it;

        int curLength = rightBound - leftBound;
        positions.insert(a);

        lengths.erase(lengths.find(curLength));
        lengths.insert(a - leftBound);
        lengths.insert(rightBound - a);
 
        cout << *(lengths.rbegin()) << " ";
    }
}