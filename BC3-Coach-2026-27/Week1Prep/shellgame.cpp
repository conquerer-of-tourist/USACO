/*

    USACO 2019 January Contest, Bronze
    Problem 1. Shell Game

    September 7, 2026

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> avals, bvals, gvals;
int n;

int check(int starting) {
    int currLoc = starting;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        int a = avals[i];
        int b = bvals[i];
        if (currLoc == a) currLoc = b;
        else if (currLoc == b) currLoc = a;

        if (gvals[i] == currLoc) counter++;
    }
    return counter;
}

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        avals.push_back(a);
        bvals.push_back(b);
        gvals.push_back(g);
    }
    int cnt = max({check(1), check(2), check(3)});
    cout << cnt << '\n';
}