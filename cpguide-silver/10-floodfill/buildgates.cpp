/*

    August 22, 2026
    Hengsheng Wang
    Build Gates (USACO 2016 January Silver - Problem 2)

*/

#include <bits/stdc++.h>
using namespace std;

int n;
bool grid [4007][4007];
bool visi [4007][4007];

int main()
{
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    cin >> n;
    int cx = 2002, cy = 2002;
    grid[cx][cy] = 1;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (a == 'N') {
            grid[cx][cy + 1] = 1;
            grid[cx][cy + 2] = 1;
            cy += 2;
        }
        else if (a == 'S') {
            grid[cx][cy - 1] = 1;
            grid[cx][cy - 2] = 1;
            cy -= 2;
        }
        else if (a == 'W') {
            grid[cx - 1][cy] = 1;
            grid[cx - 2][cy] = 1;
            cx -= 2;
        }
        else {
            grid[cx + 1][cy] = 1;
            grid[cx + 2][cy] = 1;
            cx += 2;
        }
    }
    int counter = 0;
    for (int i = 0; i < 4006; i++) {
        for (int j = 0; j < 4006; j++) {
            if (visi[i][j] == 0 && grid[i][j] == 0) {
                stack<pair<int, int>> vals;
                vals.push({i, j});
                visi[i][j] = 1;

                while (!vals.empty()) {
                    int curI = vals.top().first;
                    int curJ = vals.top().second;
                    vals.pop();

                    if (curI > 0 && !grid[curI - 1][curJ] && !visi[curI - 1][curJ]) {
                        visi[curI - 1][curJ] = 1;
                        vals.push({curI - 1, curJ});
                    }
                    if (curI + 1 < 4006 && !grid[curI + 1][curJ] && !visi[curI + 1][curJ]) {
                        visi[curI + 1][curJ] = 1;
                        vals.push({curI + 1, curJ});
                    }
                    if (curJ > 0 && !grid[curI][curJ - 1] && !visi[curI][curJ - 1]) {
                        visi[curI][curJ - 1] = 1;
                        vals.push({curI, curJ - 1});
                    }
                    if (curJ + 1 < 4006 && !grid[curI][curJ + 1] && !visi[curI][curJ + 1]) {
                        visi[curI][curJ + 1] = 1;
                        vals.push({curI, curJ + 1});
                    }
                }
                counter++;
            }
        }
    }
    cout << counter - 1 << '\n';
}