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
    ve<int> row1 = {1, 2, 3, 4, 5, 6, 7, 9};
    ve<int> row3 = {0, 1, 4, 5, 6, 7, 8, 9};
    ve<int> row4 = {0, 2, 3, 5, 6, 7, 8, 9};
    ve<int> row5 = {0, 1, 2, 3, 4, 6, 7, 8};

    ve<ve<int>> valid1, valid3, valid4, valid5;

    do {
        if (((8 + row1[1] + row1[3] + row1[5] + row1[7]) % 10) != 5) {
            continue;
        }

        if (   !isPrime(row1[4] * 10 + row1[5]) ||
                isPrime(row1[0] * 10 + row1[1]) ||
                isPrime(row1[2] * 10 + row1[3]) ||
                isPrime(row1[6] * 10 + row1[7])) {
            continue;
        }

        if (row1[4] != 1 && row1[5] != 1) continue;
        if (row1[6] != 5 && row1[7] != 5) continue;

        valid1.push_back(row1);
    } while (next_permutation(row1.begin(), row1.end()));

    do {
        if (((3 + row3[1] + row3[3] + row3[5] + row3[7]) % 10) != 2) {
            continue;
        }

        if (    isPrime(row3[4] * 10 + row3[5]) ||
                isPrime(row3[0] * 10 + row3[1]) ||
                isPrime(row3[2] * 10 + row3[3]) ||
                isPrime(row3[6] * 10 + row3[7])) {
            continue;
        }

        if (row3[4] != 0 && row3[5] != 0) continue;
        if (row3[6] != 1 && row3[7] != 1) continue;

        valid3.push_back(row3);
    } while (next_permutation(row3.begin(), row3.end()));

    do {
        if (((4 + row4[1] + row4[3] + row4[5] + row4[7]) % 10) != 3) {
            continue;
        }

        if (    isPrime(row4[4] * 10 + row4[5]) ||
                isPrime(row4[0] * 10 + row4[1]) ||
               !isPrime(row4[2] * 10 + row4[3]) ||
                isPrime(row4[6] * 10 + row4[7])) {
            continue;
        }

        valid4.push_back(row4);
    } while (next_permutation(row4.begin(), row4.end()));

    do {
        if (((5 + row5[1] + row5[3] + row5[5] + row5[7]) % 10) != 8) {
            continue;
        }

        if (    isPrime(row5[4] * 10 + row5[5]) ||
                isPrime(row5[0] * 10 + row5[1]) ||
                isPrime(row5[2] * 10 + row5[3]) ||
               !isPrime(row5[6] * 10 + row5[7])) {
            continue;
        }

        if (row5[0] != 4 && row5[1] != 4) continue;
        if (row5[4] != 8 && row5[5] != 8) continue;

        int k = 10 * row5[6] + row5[7];
        if (k != 37 && k != 73) continue;

        valid5.push_back(row5);
    } while (next_permutation(row5.begin(), row5.end()));

    for (auto& r1 : valid1) {
        for (auto& r3 : valid3) {
            for (auto& r4 : valid4) {
                for (auto& r5 : valid5) {
                    ve<ve<int>> vals (5, ve<int> (5, 0));
                    vals[0][0] = 8;
                    vals[1][0] = 67;
                    vals[2][0] = 23;
                    vals[3][0] = 14;
                    vals[4][0] = 95;
                    vals[1][1] = 19;
                    vals[1][2] = 85;
                    vals[1][3] = 43;
                    vals[1][4] = 20;

                    for (int i = 1; i <= 4; i++) {
                        int r1Val = r1[(i - 1) * 2] * 10 + r1[(i - 1) * 2 + 1];
                        int r3Val = r3[(i - 1) * 2] * 10 + r3[(i - 1) * 2 + 1];
                        int r4Val = r4[(i - 1) * 2] * 10 + r4[(i - 1) * 2 + 1];
                        int r5Val = r5[(i - 1) * 2] * 10 + r5[(i - 1) * 2 + 1];

                        vals[0][i] = r1Val;
                        vals[2][i] = r3Val;
                        vals[3][i] = r4Val;
                        vals[4][i] = r5Val;
                    }
                    
                    set<int> diffVals;
                    for (auto& v1 : vals) {
                        for (auto& v2 : v1) {
                            diffVals.insert(v2);
                        }
                    }
                    if (diffVals.size() != 25) continue;

                    int cur2 = 0, cur4 = 0;
                    for (int i = 0; i < 5; i++) {
                        cur2 += vals[i][1];
                        cur4 += vals[i][3];
                    }
                    if ((cur2 % 10) != 4 || (cur4 % 10) != 6) continue;

                    set<int> cc1, cc2, cc3, cc4;
                    for (int i = 0; i < 5; i++) {
                        cc1.insert(vals[i][1] % 10);
                        cc2.insert(vals[i][2] % 10);
                        cc3.insert(vals[i][3] % 10);
                        cc4.insert(vals[i][4] % 10);

                        cc1.insert(vals[i][1] / 10);
                        cc2.insert(vals[i][2] / 10);
                        cc3.insert(vals[i][3] / 10);
                        cc4.insert(vals[i][4] / 10);
                    }
                    if (cc1.size() != 10 || cc2.size() != 10 || 
                        cc3.size() != 10 || cc4.size() != 10) {
                        continue;
                    }
                    for (auto& k11 : vals) {
                        for (auto& k12 : k11) {
                            cout << k12 << '\t';
                        }
                        cout << '\n';
                    }
                    return 0;
                }
            }
        }
    }
}