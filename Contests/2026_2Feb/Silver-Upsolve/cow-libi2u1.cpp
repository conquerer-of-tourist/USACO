#include <bits/stdc++.h>
using namespace std;

int t, c;

void solve()
{
    int n;
    cin >> n;
    vector<char> r1 (n), r2 (n);
    int nTop = 0;

    for (auto& r : r1) cin >> r;
    for (auto& r : r2) cin >> r;
    int cNN = 0, cJJ = 0, cNJ = 0, cJN = 0;
    for (int i = 0; i < n; i++) {
        if (r1[i] == 'N') nTop++;
        if (r1[i] == 'N' && r2[i] == 'J') cNJ++;
        else if (r1[i] == 'J' && r2[i] == 'N') cJN++;
        else if (r1[i] == r2[i] && r1[i] == 'N') cNN++;
        else cJJ++;
    }
    if (cJN != cNJ || nTop % 2 != 0) {
        cout << "NO" << "\n";
        return;
    }
    if (cNJ == 0 && cJJ > 0 && cNN > 0) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << "\n";
    if (c == 0) {
        return;
    }
    else {
        // we could also make separate vectors for each individual types;
        vector<int> v1; // NN
        vector<int> v2; // NJ
        vector<int> v3; // JN
        vector<int> v4; // JJ
        for (int i = 0; i < n; i++) {
            char a = r1[i];
            char b = r2[i];
            if (a == 'N' && b == 'N') v1.push_back(i);
            else if (a == 'N' && b == 'J') v2.push_back(i);
            else if (a == 'J' && b == 'N') v3.push_back(i);
            else v4.push_back(i);
        }
        vector<pair<int, int>> ordering;
        
        // vector<pair<int, int>> correspondence;
        // for (int i = 0; i < n; i++) {
        //     char a = r1[i];
        //     char b = r2[i];
        //     if (a == 'N' && b == 'J') correspondence.push_back({i, 1});
        //     if (a == 'N' && b == 'N') correspondence.push_back({i, 2});
        //     if (a == 'N' && b == 'J') correspondence.push_back({i, 3});
        //     else correspondence.push_back({i, 4});

        //     /* The Goal:
        //     JNNNNNNNJJJJNJNJ
        //     NNNNNNNJJJJNJNJN
            


        //     1. Transition element (JN)
        //     2. Block of N
        //     3. Transition element (NJ)
        //     4. Block of J
        //     5. Alternating between NJ and JN 
        //     */
        // }
    }
}

int main()
{
    cin >> t >> c;
    while (t--) {
        solve();
    }
}