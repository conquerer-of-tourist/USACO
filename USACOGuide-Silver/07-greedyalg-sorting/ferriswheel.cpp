/*

    CSES - Ferris Wheel
    Hengsheng Wang
    August 3rd, 2026

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> kids (n);
    for (auto& kid : kids) {
        cin >> kid;
    }
    sort(kids.begin(), kids.end());

    int p1 = 0;
    int p2 = n - 1;

    int counter = 0;
    while (p1 <= p2) {
        if (p1 == p2) {
            counter++;
            break;
        }
        if (kids[p1] + kids[p2] > x) {
            p2--;
            counter++;
        }
        else {
            p1++;
            p2--;
            counter++;
        }
    }
    cout << counter << '\n';
}