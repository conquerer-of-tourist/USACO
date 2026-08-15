// Problem Name            -> Painting the Barn (Hard Version)
// Link                    -> https://usaco.org/index.php?page=viewproblem2&cpid=923
// Submit                  -> Hengsheng Wang
// Date*****               -> June 27 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a1[202][202];
int a2[202][202];

int goodness[205][205];
int prefix[205][205];

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
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            a2[i][j] = a2[i - 1][j] + a2[i][j - 1] - a2[i - 1][j - 1];
            a2[i][j] += a1[i][j];
            if (a2[i][j] == k) {
                goodness[i][j] = - 1;
                counter++;
            }
            else if (a2[i][j] == k - 1) {
                goodness[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            prefix[i][j] = goodness[i][j] +
                           prefix[i][j - 1] +
                           prefix[i - 1][j] -
                           prefix[i - 1][j - 1];
        }
    }
    int bestImprovement = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = i; j < 200; j++) {
            int bestChange = 0;
            int current = 0;
            for (int col = 1; col <= 200; col++) {
                int colSum = prefix[j + 1][col]
                            - prefix[i][col]
                            - prefix[j + 1][col - 1]
                            + prefix[i][col - 1];
                current = max(current + colSum, colSum);
                bestChange = max(bestChange, current);
            }
            bestImprovement = max(bestImprovement, bestChange);
        }
    }
}