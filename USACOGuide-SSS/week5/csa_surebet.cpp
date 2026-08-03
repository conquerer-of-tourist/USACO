/*

    Information
    ===============================
    Name:           Hengsheng Wang
    Date:           August 2nd, 2026
    Problem:        Sure Bet (CSAcademy)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> choice1;
    vector<double> choice2;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;

        choice1.push_back(a);
        choice2.push_back(b);
    }
    sort(choice1.rbegin(), choice1.rend());
    sort(choice2.rbegin(), choice2.rend());

    double answer = 0;
    double total1 = 0;
    double total2 = 0;
    int i = 0, j = 0;

    while (true) {
        if (total1 < total2) {
            if (i == n) break;
            total1 += choice1[i];
            i++;
        }
        else {
            if (j == n) break;
            total2 += choice2[j];
            j++;
        }

        double currTotal = min(total1, total2) - i - j;
        answer = max(answer, currTotal);
    }
    cout << fixed << setprecision(4) << answer << '\n';
}