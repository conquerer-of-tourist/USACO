// Problem Name            -> Painting the Barn (Hard Version) - Full Solution
// Link                    -> https://usaco.org/index.php?page=viewproblem2&cpid=923
// Submit                  -> Hengsheng Wang
// Date*****               -> June 28 2026

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a1[202][202];
int a2[202][202];

int goodness[205][205];
int prefix[205][205];

int improvementByColSplitL[205];
int improvementByColSplitR[205];

int improvementByRowSplitT[205];
int improvementByRowSplitB[205];

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
                improvementByColSplitL[col] = max(bestChange, improvementByColSplitL[col]);
            }
            bestChange = 0;
            current = 0;
            for (int col = 200; col >= 1; col--) {
                int colSum = prefix[j + 1][col]
                            - prefix[i][col]
                            - prefix[j + 1][col - 1]
                            + prefix[i][col - 1];
                current = max(current + colSum, colSum);
                bestChange = max(bestChange, current);
                improvementByColSplitR[col] = max(bestChange, improvementByColSplitR[col]);
            }
        }
    }
    int bestColImprovement = 0;
    for (int i = 1; i < 200; i++) {
        bestColImprovement = max(bestColImprovement,
                                 improvementByColSplitL[i] + improvementByColSplitR[i + 1]);
    }

    for (int i = 0; i < 200; i++) {
        for (int j = i; j < 200; j++) {
            int bestChange = 0;
            int current = 0;
            for (int row = 1; row <= 200; row++) {
                int rowSum = prefix[row][j + 1]
                            - prefix[row][i]
                            - prefix[row - 1][j + 1]
                            + prefix[row - 1][i];
                current = max(current + rowSum, rowSum);
                bestChange = max(bestChange, current);
                improvementByRowSplitT[row] = max(bestChange, improvementByRowSplitT[row]);
            }
            bestChange = 0;
            current = 0;
            for (int row = 200; row >= 1; row--) {
                int rowSum = prefix[row][j + 1]
                            - prefix[row][i]
                            - prefix[row - 1][j + 1]
                            + prefix[row - 1][i];
                current = max(current + rowSum, rowSum);
                bestChange = max(bestChange, current);
                improvementByRowSplitB[row] = max(bestChange, improvementByRowSplitB[row]);
            }
        }
    }
    int bestRowImprovement = 0;
    for (int i = 1; i < 200; i++) {
        bestRowImprovement = max(bestRowImprovement,
                                 improvementByRowSplitT[i] + improvementByRowSplitB[i + 1]);
    }
    int bestImprovementOverall = max(bestRowImprovement, bestColImprovement);
    cout << counter + bestImprovementOverall << '\n';
}