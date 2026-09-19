/*

    Air Cownditioning II (Bronze Jan 2023)
    Hengsheng W.
    September 18, 2026

*/

#include <bits/stdc++.h>
using namespace std;

struct cow {
    int a, b, c;
};

struct conditioner {
    int a, b, p, m;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<cow> cows (n);
    for (auto& cow : cows) {
        cin >> cow.a >> cow.b >> cow.c;
    }

    vector<conditioner> conditioners (m);
    for (auto& cond : conditioners) {
        cin >> cond.a >> cond.b >> cond.p >> cond.m;
    }

    //
}