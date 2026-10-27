#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("outofplace.in", "r", stdin);
    // freopen("outofplace.out", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<int> vals (n);
    for (auto& val : vals) {
        cin >> val;
    }

    vector<int> sec (n, 0);
    for (int i = 0; i < n; i++) {
        sec[i] = vals[i];
    }

    sort(sec.begin(), sec.end());

}


/*



*/