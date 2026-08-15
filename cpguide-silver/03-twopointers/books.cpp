/*

    Information
    =====================
    Hengsheng Wang
    July 9th, 2026
    Codeforces Round 171 (Division 2)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> books (n);
    int answer = 0;
    for (auto& book : books) {
        cin >> book;
        if (book <= t) {
            answer = 1;
        }
    }
    int l = 0, r = 0;
    int curSum = books[0];
    while (l <= r && r < n) {
        if (curSum > t) {
            curSum -= books[l];
            l++;
            if (l > r) {
                if (r + 1 < n) {
                    curSum += books[r + 1];
                    r++;
                }
            }
        }
        else {
            answer = max(answer, l - r + 1);
        }
        if (r + 1 < n && curSum + books[r + 1] <= t) {
            curSum += books[r + 1];
            r++;
            answer = max(answer, r - l + 1);
        }
        else if (r + 1 < n && curSum + books[r + 1] > t) {
            curSum -= books[l];
            l++;
            if (l > r && r + 1 < n) {
                curSum += books[r + 1];
                r++;
            }
        }
        else {
            break;
        }
    }
    cout << answer << "\n";
}