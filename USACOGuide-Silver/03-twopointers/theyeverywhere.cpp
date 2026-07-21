/*

    Information
    ====================
    bpcf
    July 20, 2026
    Grinding Session: 2 Pointers
    C. They Are Everywhere
    Codeforces Round 364 (Division 2)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<char> vals;

    vector<int> freq (200, 0);

    for (char k : s) {
        vals.insert(k);
    }

    int needed = vals.size();

    int left = 0;
    int currNum = 0;
    int ans = n;

    for (int right = 0; right < n; right++) {
        unsigned char rightChar = s[right];

        if (freq[rightChar] == 0) {
            currNum++;
        }
        freq[rightChar]++;

        while (currNum == needed) {
            ans = min(ans, right - left + 1);

            unsigned char lChar = s[left];
            freq[lChar]--;

            if (freq[lChar] == 0) {
                currNum--;
            }

            left++;
        }
    }
    cout << ans << '\n';
}

// /*

//     Information
//     ====================
//     bpcf
//     July 20, 2026
//     Grinding Session: 2 Pointers
//     C. They Are Everywhere
//     Codeforces Round 364 (Division 2)

// */

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<char> vals (n);
//     map<char, int> occurences;
//     for (auto& val : vals) {
//         cin >> val;
//         occurences[val]++;
//     }
    
//     int l = 0;
//     int r = n - 1;
//     while (true) {
//         if (l >= r) {
//             cout << 1 << '\n';
//             return 0;
//         }
//         if (occurences[vals[l]] >= 2) {
//             occurences[vals[l]]--;
//             l++;
//         }
//         else if (occurences[vals[r]] >= 2) {
//             occurences[vals[r]]--;
//             r--;
//         }
//         else {
//             break;
//         }
//     }
//     cout << r - l + 1 << '\n';
// }