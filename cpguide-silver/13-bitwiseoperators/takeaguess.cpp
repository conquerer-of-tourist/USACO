/*

    Take a Guess (Codeforces Deltix Summer 2021) Problem D
    Hengsheng W.
    August 26, 2026

*/

// SUPER IMPORTANT NOTE: "xor" is (negation of AND) AND (OR)

#include <bits/stdc++.h>
using namespace std;

int query(string s, int a, int b) {
    cout << s << " " << a << " " << b << '\n';
    int k; cin >> k; fflush(stdout); return k;
}

int sum(int a, int b) {
    a++; b++;
    int aVal = query("and", a, b);
    int oVal = query("or", a, b);
    int xVal = (~aVal) & oVal;

    return 2 * aVal + xVal;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int AB = sum(0, 1);
    int AC = sum(0, 2);
    int BC = sum(1, 2);

    vector<int> vals {(AB + AC - BC) / 2};
    vals.push_back(AB - vals[0]);
    vals.push_back(AC - vals[0]);

    for (int i = 3; i < n; i++) {
        vals.push_back(sum(i - 1, i) - vals.back());
    }
    sort(vals.begin(), vals.end());
    cout << "finish " << vals[k - 1] << '\n';
}