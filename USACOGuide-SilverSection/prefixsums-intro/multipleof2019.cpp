/*
    Contest: AtCoder JP
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: Junly 1st, 2026
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    string s;
    cin >> s;
    vector<int> suffix (s.length() + 1, 0);
    vector<int> p10sfx (s.length() + 1, 0);
    p10sfx[s.length()] = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        //
    }

    for (int i = s.length() - 1; i >= 0; i--) {
        char curr = s[i];
        int  currVal = curr - '0';
        int  currValm2019 = (currVal * p10sfx[i + 1]) % 2019;
        suffix[i] = suffix[i + 1] + currValm2019;
        suffix[i] %= 2019;
    }
    map<int, int> freq;
    
    //
}