/*

    Thursday, September 10, 2026
    Milk Pails (2016 February, Bronze)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m;
    cin >> x >> y >> m;
    int maximal = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            int curr = i * x + j * y;
            if (curr <= m) {
                maximal = max(maximal, curr);
            }
        }
    }
    cout << maximal << '\n';
}