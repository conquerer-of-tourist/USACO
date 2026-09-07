/*

    September 7, 2026
    Mixing Milk - USACO Bronze (2018 December)

*/

#include <bits/stdc++.h>
using namespace std;

int c1, m1, c2, m2, c3, m3;

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    for (int i = 0; i < 100; i++) {
        int s1 = i % 3 + 1;

        if (s1 == 1) {
            int remaining = c2 - m2;
            if (remaining >= m1) {
                m2 += m1;
                m1 = 0;
            }
            else {
                m1 -= remaining;
                m2 = c2;
            }
        }
        else if (s1 == 2) {
            int remaining = c3 - m3;
            if (remaining >= m2) {
                m3 += m2;
                m2 = 0;
            }
            else {
                m2 -= remaining;
                m3 = c3;
            }
        }
        else {
            int remaining = c1 - m1;
            if (remaining >= m3) {
                m1 += m3;
                m3 = 0;
            }
            else {
                m3 -= remaining;
                m1 = c1;
            }
        }
    }
    cout << m1 << '\n' << m2 << '\n' << m3;
}