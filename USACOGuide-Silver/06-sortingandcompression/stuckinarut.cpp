/*

    Information
    ---------------------------
    Hengsheng Wang
    USACO 2020 December Contest: Silver
    July 14th, 2026 and July 15th, 2026

*/

#include <bits/stdc++.h>
using namespace std;

class cowInfo {
    public:
        char dir;
        int x;
        int y;
};

int main()
{
    int n;
    cin >> n;
    vector<cowInfo> cows (n);
    for (auto& cow : cows) {
        cin >> cow.dir >> cow.x >> cow.y;
    }
    //
}