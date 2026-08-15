// Google Kickstart | Candies
// User             | Hengsheng Wang
// Date             | June 28, 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve() {
    int n, q;
    cin >> n >> q;
    vector<int> nums (n);
    for (auto& num : nums) {
        cin >> num;
    }
    int normalPrefix[n + 5];

    int weightPrefix[n + 5];
    for (int i = 0; i < n + 3; i++) {
        normalPrefix[i] = 0;
        weightPrefix[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            normalPrefix[i + 1] = normalPrefix[i] + nums[i];
            weightPrefix[i + 1] = weightPrefix[i] + (i + 1) * nums[i];
        }
        else {
            normalPrefix[i + 1] = normalPrefix[i] - nums[i];
            weightPrefix[i + 1] = weightPrefix[i] - (i + 1) * nums[i];
        }
    }
    int totalSweetness = 0;
    while (q--) {
        string querytype;
        cin >> querytype;
        if (querytype == "U") {
            int index, value;
            cin >> index >> value;
            nums[index - 1] = value;
            for (int i = 0; i < n + 3; i++) {
                normalPrefix[i] = 0;
                weightPrefix[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    normalPrefix[i + 1] = normalPrefix[i] + nums[i];
                    weightPrefix[i + 1] = weightPrefix[i] + (i + 1) * nums[i];
                }
                else {
                    normalPrefix[i + 1] = normalPrefix[i] - nums[i];
                    weightPrefix[i + 1] = weightPrefix[i] - (i + 1) * nums[i];
                }
            }
        }
        else {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int curSweet = weightPrefix[b + 1] - weightPrefix[a] -
                           a * (normalPrefix[b + 1] - normalPrefix[a]);
            if (a % 2 == 1) {
                curSweet *= -1;
            }
            totalSweetness += curSweet;
        }
    }
    return totalSweetness;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        ll answer = solve();
        cout << "Case #" << i << ": " << answer << '\n';
    }
}