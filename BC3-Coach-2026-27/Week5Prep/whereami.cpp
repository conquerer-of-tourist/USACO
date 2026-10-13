#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;
    vector<char> vals (n);
    for (auto& v : vals) {
        cin >> v;
    }

    for (int i = 1; i <= n; i++) {
        set<string> ranges;
        // should have size n + 1 - i.
        for (int j = 0; j < n - i + 1; j++) {
            string curString = "";
            for (int k = j; k < j + i; k++) {
                curString += vals[k];
            }
            ranges.insert(curString);
        }
        if (ranges.size() == n + 1 - i) {
            cout << i << '\n';
            return 0;
        }
    }
}