#include <bits/stdc++.h>
using namespace std;

#define ve vector

bool isPrime(int k) {
    if (k == 1) {
        return false;
    }
    if (k == 2 || k == 3) {
        return true;
    }
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) return false;
    }
    return true;
}

int main()
{
    freopen("answer.txt", "w", stdout);
    ve<int> row1 = {1, 2, 3, 4, 5, 6, 7, 9};
    ve<int> row3 = {0, 1, 4, 5, 6, 7, 8, 9};
    ve<int> row4 = {0, 2, 3, 5, 6, 7, 8, 9};
    ve<int> row5 = {0, 1, 2, 3, 4, 6, 7, 8};

    do {
        int bCA = row1[6] * 10 + row1[7];
        if (bCA != 17 && bCA != 19 && bCA != 71 && bCA != 61) {
            continue;
        }
        if (((row1[1] + row1[3] + row1[5] + row1[7]) % 10) != 5) {
            continue;
        }
        do {
            if (((row5[1] + row5[3] + row5[5] + row5[7]) % 10) != 8) {
                continue;
            }
            int bC = row5[6] * 10 + row5[7];
            if (bC != 37 && bC != 67 && bC != 73) {
                continue;
            }
            do {
                if (((row4[1] + row4[3] + row4[5] + row4[7]) % 10) != 3) {
                    continue;
                }
                do {
                    if (((row3[1] + row3[3] + row3[5] + row3[7]) % 10) != 2) {
                        continue;
                    }
                    ve<ve<int>> vals (5, ve<int> (5, 0));

                    for (int i = 0; i < 8; i += 2) {
                        int j = i / 2 + 1;

                        vals[0][j] = row1[i] * 10 + row1[i + 1];
                        vals[2][j] = row3[i] * 10 + row3[i + 1];
                        vals[3][j] = row4[i] * 10 + row4[i + 1];
                        vals[4][j] = row5[i] * 10 + row5[i + 1];
                    }

                    // initiation
                    vals[0][0] = 8;
                    vals[1][0] = 67;
                    vals[2][0] = 23;
                    vals[3][0] = 14;
                    vals[4][0] = 95;
                    vals[1][1] = 19;
                    vals[1][2] = 85;
                    vals[1][3] = 43;
                    vals[1][4] = 20;

                    // checking for matching with template

                    if (!(  (vals[0][3] % 10 == 1 || vals[0][3] / 10 == 1) && 
                            (vals[0][4] % 10 == 5 || vals[0][4] / 10 == 5) && 
                            (vals[2][4] % 10 == 1 || vals[2][4] / 10 == 1) && 
                            (vals[2][3] % 10 == 0 || vals[2][3] / 10 == 0) && 
                            (vals[4][2] % 10 == 1 || vals[4][2] / 10 == 1) && 
                            (vals[4][1] % 10 == 4 || vals[4][1] / 10 == 4) && 
                            (vals[4][4] % 10 == 8 || vals[4][4] / 10 == 8) )) {
                        continue;
                    }

                    if (!isPrime(vals[0][3]) ||
                        !isPrime(vals[3][2]) ||
                        !isPrime(vals[4][4])) {
                            continue;
                    }

                    // checking for uniqueness of digits

                    set<int> a1, a2, a3, a4;
                    for (int i = 0; i <= 4; i++) {
                        a1.insert(vals[i][1] % 10);
                        a1.insert(vals[i][1] / 10);

                        a2.insert(vals[i][2] % 10);
                        a2.insert(vals[i][2] / 10);

                        a3.insert(vals[i][3] % 10);
                        a3.insert(vals[i][3] / 10);
                        
                        a4.insert(vals[i][4] % 10);
                        a4.insert(vals[i][4] / 10);
                    }

                    if (a1.size() != 10 ||
                        a2.size() != 10 ||
                        a3.size() != 10 ||
                        a4.size() != 10) {
                        continue;
                    }

                    // checking for sum of digits.

                    int k1 = 0, k3 = 0;
                    for (int i = 0; i < 5; i++) {
                        k1 += vals[1][i]; k1 %= 10;
                        k3 += vals[3][i]; k3 %= 10;
                    }

                    if (k1 != 4 || k3 != 6) {
                        continue;
                    }
                

                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            cout << vals[i][j] << '\t';
                        }
                        cout << '\n';
                    }
                    cout << "DONE" << '\n';
                    return 0;
                }
                while (next_permutation(row3.begin(), row3.end()));
            } while (next_permutation(row4.begin(), row4.end()));
        } while (next_permutation(row5.begin(), row5.end()));
    } while (next_permutation(row1.begin(), row1.end()));
}

// 67 19 85 43 20 (2nd row from top)
// 08 67 23 14 95 (1st col from left)