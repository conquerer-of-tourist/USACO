/* July 10, 2026; USAJMO 2016 Testing for P2 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll k = 6103515625;
    for (int i = 15; i <= 1e6 + 3; i++) {
        k *= 5;
        k %= 100000000;
        if (k < 10000) {
            cout << k << " and used index " << i << '\n';
            return 0;
        }
    }
}