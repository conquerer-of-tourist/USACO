// Weird Algorithm - September 7, 2026

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while (true) {
        if (n == 1) {
            cout << "1\n"; break;
        }
        cout << n << " ";
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
}