/*

    August 23, 2026
    Hengsheng Wang

    USACO 2018 US Open (Bronze) - Problem 3. Family Tree

*/

#include <bits/stdc++.h>
using namespace std;

#define ve vector

int main()
{
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    int n;
    string a, b;
    cin >> n >> a >> b;

    map<string, int> IDs;
    map<int, int> parents;
    int curID = 0, aID = 0, bID = 0;
    for (int i = 0; i < n; i++) {
        string cow1, cow2;
        cin >> cow1 >> cow2;
        if (IDs.find(cow1) == IDs.end()) {
            IDs[cow1] = curID;
            curID++;
        }
        if (IDs.find(cow2) == IDs.end()) {
            IDs[cow2] = curID;
            curID++;
        }
        parents[IDs[cow2]] = IDs[cow1];
    }
    aID = IDs[a];
    bID = IDs[b];

    map<int, int> distA;
    int cur = aID, d = 0;
    while (true) {
        distA[cur] = d;
        if (parents.find(cur) == parents.end()) {
            break;
        }
        cur = parents[cur];
        d++;
    }

    bool found = false;
    map<int, int> distB;
    int cur2 = bID, d2 = 0;
    while (true) {
        distB[cur2] = d2;
        if (distA.find(cur2) != distA.end()) {
            found = true;
            break;
        }
        if (parents.find(cur2) == parents.end()) {
            break;
        }
        cur2 = parents[cur2];
        d2++;
    }

    d = distA[cur2];

    if (!found) {
        cout << "NOT RELATED" << endl;
        return 0;
    }

    if (d == 1 && d2 == 1) {
        cout << "SIBLINGS" << "\n";
    }
    else if (d == 0 && d2 == 1) {
        cout << a << " is the mother of " << b;
    }
    else if (d2 == 0 && d == 1) {
        cout << b << " is the mother of " << a;
    }
    else if (d == 0) {
        string k = "";
        for (int i = 0; i < d2 - 2; i++) {
            k += "great-";
        }
        cout << a << " is the " << k << "grand-mother of " << b;
    }
    else if (d2 == 0) {
        string k = "";
        for (int i = 0; i < d - 2; i++) {
            k += "great-";
        }
        cout << b << " is the " << k << "grand-mother of " << a;
    }
    else if (d == 1 && d2 == 2) {
        cout << a << " is the aunt of " << b;
    }
    else if (d == 2 && d2 == 1) {
        cout << b << " is the aunt of " << a;
    }
    else if (d == 1) {
        string k = "";
        for (int i = 0; i < d2 - 3; i++) {
            k += "great-";
        }
        cout << a << " is the " << k << "great-aunt of " << b;
    }
    else if (d2 == 1) {
        string k = "";
        for (int i = 0; i < d - 3; i++) {
            k += "great-";
        }
        cout << b << " is the " << k << "great-aunt of " << a;
    }
    else if (d > 1 && d2 > 1) {
        cout << "COUSINS" << '\n';
    }
}