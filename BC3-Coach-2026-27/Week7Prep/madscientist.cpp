#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    bool curRun = false;
    int num = 0;

    for (int i = 0; i < n; i++) {
        if (curRun && a[i] == b[i]) {
            num++;
            curRun = false;
        }
        else if (a[i] != b[i]) {
            curRun = true;
        }
    }

    cout << num << '\n';
}