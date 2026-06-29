// Problem Name            -> Painting the Barn (Easy Version)
// Link                    -> https://usaco.org/index.php?page=viewproblem2&cpid=919
// Submit                  -> Hengsheng Wang
// Date                    -> June 27 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a1[1002][1002];
int a2[1002][1002];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++; x2++; y1++; y2++;

        a1[x1][y1]++;
        a1[x2][y1]--;
        a1[x1][y2]--;
        a1[x2][y2]++;
    }
    int counter = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            a2[i][j] = a2[i - 1][j] + a2[i][j - 1] - a2[i - 1][j - 1];
            a2[i][j] += a1[i][j];
            if (a2[i][j] == k) {
                counter++;
            }
        }
    }
    cout << counter << '\n';
}