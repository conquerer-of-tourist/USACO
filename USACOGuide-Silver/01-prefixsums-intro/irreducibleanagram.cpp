/*
    Contest: Codeforces Round 616
    Author: Hengsheng Wang
    User: conquerer-of-tourist
    Date: July 3rd, 2026
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        string curr = "";
        for (int i = a + 1; i <= b + 1; i++) {
            curr += s[i];
        }
        //
    }
}