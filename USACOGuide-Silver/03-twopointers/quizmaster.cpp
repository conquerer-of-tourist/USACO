/*

    General Information
    ================================
    Hengsheng Wang
    July 21 and 22, 2026
    C. Quiz Master (Codeforces Round 845)

*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    set<int> initVals;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        initVals.insert(k);
    }

    vector<int> vals;
    for (auto& thing : initVals) {
        vals.push_back(thing);
    }
    sort(vals.begin(), vals.end());

    int covered = 0, left = 0, answer = 1e9 + 8;

    vector<int> freq (m + 1, 0);

    for (int right = 0; right < vals.size(); right++) {
        for (int i = 1; i * i <= vals[right]; i++) {
            if (i < m && vals[right] % i == 0) {
                if (freq[i] == 0) {
                    covered++;
                }
                freq[i]++;
                if (vals[right] / i <= m && i * i != vals[right]) {
                    if (freq[vals[right] / i] == 0) {
                        covered++;
                    }
                    freq[vals[right] / i]++;
                }
            }
            else if (i == m && vals[right] % i == 0) {
                if (freq[m] == 0) {
                    covered++;
                }
                freq[i]++;
            }
        }

        while (covered == m) {
            answer = min(answer, vals[right] - vals[left]);

            for (int i = 1; i * i <= vals[left]; i++) {
                if (i < m && vals[left] % i == 0) {
                    if (freq[i] == 1) {
                        covered--;
                    }
                    freq[i]--;
                    if (vals[left] / i <= m && i * i != vals[left]) {
                        if (freq[vals[left] / i] == 1) {
                            covered--;
                        }
                        freq[vals[left] / i]--;
                    }
                }
                else if (i == m && vals[left] % i == 0) {
                    if (freq[m] == 1) {
                        covered--;
                    }
                    freq[i]--;
                }
            }

            left++;
        }
    }

    if (answer == (int) 1e9 + 8) {
        cout << -1 << '\n';
    }
    else {
        cout << answer << '\n';
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}